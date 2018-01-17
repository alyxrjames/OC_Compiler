#include <vector>
#include <bitset>
#include <unordered_map>
#include <string>

#include "symbol_table.h"
#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"

symbol_stack id;
symbol_table type;
symbol_stack field;

size_t blkctr = 0;
size_t next_block = 1;
vector<size_t> blkstk;

FILE * symbol_file;

void set_sym_file(FILE * f){

	symbol_file = f;

}
//intilizes the global stack
void init_stack(){


	symbol_table * glb = new symbol_table();

	blkstk.push_back(blkctr);
	id.push_back(glb);

}

//increment the block stack everytime you enter a new block

symbol_table *enter_blk(){

	blkctr = next_block;

	next_block++;

	blkstk.push_back(blkctr);

	symbol_table * new_blk = new symbol_table();	

	return new_blk;

}

void  exit_blk(){

	blkstk.pop_back();

}

symbol * new_symbol(astree * node){

        if(node == NULL)
                return NULL;

        symbol * sym = new symbol();

        sym -> fields = NULL;

        sym -> filenr = node -> filenr;

        sym -> linenr = node -> linenr;

        sym -> offset = node -> offset;

        sym -> block_nr = blkstk.back();

        sym -> attributes = node -> attributes;

	sym -> parameters = NULL;

	sym -> type_id = NULL;

//	printf("made new symbol \n");

	return sym;
}

// dumps the symbol into an outfile

void dump_symbol(symbol * symb, string * name){

	//printf("testing1:%lu \n", symb ->block_nr);

        if(symb == NULL || name == NULL){
               //         printf("testing2: \n");
			return;
        }
        
        size_t depth = symb ->block_nr;

        for(size_t i = 0; i < depth; i++){

		fprintf(symbol_file,"\t");

	}

        fprintf(symbol_file, "%s (%lu.%lu.%lu) {%lu} %s \n",
        name -> c_str(), symb -> filenr, symb -> linenr,
        symb -> offset, symb -> block_nr, get_attr(symb -> attributes, name));
		
		
        

}
//inserts a symbol into the symbol table along with its name
bool insert_sym(symbol_table * table, symbol * sym, string * name){
	
	if(table == NULL || sym == NULL || name == NULL)
				return false;

	if( table -> find(name) != table -> end())
		return false;
	
	table -> insert(make_pair(name,sym));
	dump_symbol(sym, name);

	//printf("inserting: %s \n", name -> c_str());

	return true;
	
}
// creates a type specified by a struct and puts it into the table
void new_prim_type(astree * node){

	if(node == NULL)
		if(node -> children.empty())
			return;
	astree * struct_name = node -> children[0];

	if(struct_name == NULL)
		return;

	symbol * type_sym = new_symbol(struct_name);
	
	insert_sym(&type, type_sym, (string*) struct_name -> lexinfo);

	symbol_table * field_table = new symbol_table();

	bool q = true;

	for(auto &j : node -> children){

		if(j -> symbol == TOK_TYPEID && q){
			
			q = false;
			continue;
		}		
		
		if(j->children.empty())
			return;
		
		astree * f_name = j -> children[0];

		if(f_name == NULL)
			return;

		symbol * fieldsym = new_symbol(j);

		if(fieldsym == NULL)
			return;

		fieldsym -> attributes.set(ATTR_field);

		insert_sym(field_table, fieldsym, (string*)f_name -> lexinfo);

	}

	field.push_back(field_table);
	
	type_sym -> fields = field_table;

	node -> visited = true;

	node -> struct_entry = new symbol_entry((string*)struct_name -> lexinfo, type_sym);
	
}

//creates a new variable to be entered into the symbol table
void new_variable(astree * node){

	if (node == NULL)
		if(node -> children.empty())
			return;
	astree * var_type = node -> children[0];

	if( var_type == NULL)
		return;

	astree * var_name = var_type -> children[0];

	if( var_name == NULL)	
		return;

	astree * var_v =  node ->children[1];

	if(var_v == NULL)
		return;

	symbol * var_symbol = new_symbol(node);

	if(var_symbol == NULL)
		return;

	var_symbol -> attributes.set(ATTR_variable);
	
	insert_sym(id[blkstk.back()], var_symbol, (string*) var_name -> lexinfo);

	node -> visited = true;

}
// creates a new block to be added into the block stack
void new_blk(astree * node){

	for(auto &j : node -> children){

		if(j -> symbol == TOK_VARDECL){

			new_variable(j);
			
		}
		else if(j -> symbol == TOK_BLOCK){

			symbol_table * jblock = enter_blk();

			id.push_back(jblock);

			new_blk(j);	
			exit_blk();
	
		}
		else{

			break;}

	}
	
	node -> visited = true;

}
// gets the variables inside a function parameter and puts it into a symbol table
void new_parameter(astree * parameter, symbol_table * func_table, symbol * func_sym){

	if(parameter == NULL)
		return;

	if (parameter -> children.empty())
		return;
	
	astree * param_name = parameter -> children[0];

	if (param_name == NULL)
		return;

	symbol * param_symbol = new_symbol(param_name);

	param_symbol -> attributes.set(ATTR_variable);

	param_symbol -> attributes.set(ATTR_param);

	func_sym -> parameters -> push_back(param_symbol);

	insert_sym(func_table, param_symbol, (string*)param_name->lexinfo);

	parameter -> visited = true;

}
// retrieves the function and its parameter names and puts it into the symbol table
void new_func_(astree * node){

	if(node == NULL)
		if(node -> children.empty())
			return;

	astree * t_node = node -> children[0];

	if(t_node == NULL)
		if(t_node -> children.empty())
			return;

	astree * n_node = t_node -> children[0];

	if(n_node == NULL)
		return;
	
	astree * parameter_node = node -> children[1];
	
	if(parameter_node == NULL)
		return;
	astree * funcblk_node = node -> children[2];

	if(funcblk_node == NULL)
		return;

	symbol * func_symbol = new_symbol(node);

	if(func_symbol == NULL)
		return;
	
	func_symbol -> attributes.set(ATTR_function);

	func_symbol -> parameters = new vector<symbol*>;

	dump_symbol( func_symbol, (string *) n_node -> lexinfo);

	symbol_table * func_table = enter_blk();
	
	id.push_back(func_table);

	for( auto &param : parameter_node -> children){

		new_parameter(param,func_table,func_symbol);

	}

	new_blk(node);

	exit_blk();

	insert_sym(id[blkstk.back()],func_symbol, (string*)n_node ->lexinfo);

	node -> visited = true;

		
}	
// retrieve function name from an astree and puts it into the symb table
void get_func_names(astree * root){

	if(root == NULL)
		return;

	if(root -> children.empty())
		return;

	else{
		
		for(auto &ch : root -> children){
			

			//printf("SYMBOL = %s\n",ch -> lexinfo -> c_str());
			if(ch -> visited){
				continue;
			}
			else if(ch -> symbol == TOK_STRUCT){
			//	printf("found struct\n");
				new_prim_type(ch);
				

			}
			else if(ch -> symbol == TOK_FUNCTION){
			//	printf("found function\n");
				new_func_(ch);
		
			
			}

			else if( ch -> symbol == TOK_VARDECL){
			//	printf("found variable declaration\n");
				new_variable(ch);
				
			}
			
			else if( ch -> symbol == TOK_BLOCK){
			//	printf("found block\n");	
				symbol_table * blk = enter_blk();
				id.push_back(blk);
				new_blk(ch);
				exit_blk();
			
				
			}

		get_func_names(ch);

		}

	}	
}

void set_attr(astree * node){

	if(node == NULL)
		return;

	switch (node->symbol) {

        case TOK_INTCON:
        node -> attributes.set(ATTR_const);
                
      
	case TOK_INT:
        node -> attributes.set(ATTR_int);
		break;

        case TOK_CHARCON:
        node -> attributes.set(ATTR_const);

	case TOK_CHAR:
        	node -> attributes.set(ATTR_char);
		break;

	case TOK_STRINGCON:
        node -> attributes.set(ATTR_const);


	case TOK_STRING:
        	node -> attributes.set(ATTR_string);
		break;
      
	case TOK_VOID:
        	node -> attributes.set(ATTR_void);
		break;
      
	case TOK_BOOL:
        	node -> attributes.set(ATTR_bool);
		break;

	case TOK_IDENT:
		node -> attributes.set(ATTR_lval);
		break;

	case TOK_DECLID:
      		node -> attributes.set(ATTR_lval);
		break;

	case TOK_TYPEID:
		node -> attributes.set(ATTR_typeid);	

	case TOK_STRUCT:
        	node -> attributes.set(ATTR_struct);
		break;
      
	case TOK_NULL:
        	node -> attributes.set(ATTR_const);
		break;
      
	case TOK_FIELD:
        	node -> attributes.set(ATTR_field);
		break;
      	
	case TOK_FUNCTION:
        	node -> attributes.set(ATTR_function);
		break;
      	
	case TOK_ARRAY:
        	node -> attributes.set(ATTR_array);
		break;
      
	case TOK_VARDECL:
        	node -> attributes.set(ATTR_variable);
		break;
      
	case TOK_PROTOTYPE:
        	node -> attributes.set(ATTR_proto);
	default: break;
   }

}
// ets attributes for an AST by searching its children
void set_attr_rc( astree * r){
	
	if(r == NULL)
		return;
	if(r -> children.empty())
		return;
	else{
		
		for(auto &ch : r -> children){
			set_attr(ch);
			set_attr_rc(ch);
		}
		
	}

}

//gets all the attributes in a symbol and returns it as a concatenated string
const char * get_attr(attr_bitset attributes, string * struct_name){

	string a = "";


	if (attributes.test(ATTR_void))
		a += "void ";

   	if (attributes.test(ATTR_bool))     
		a += "bool ";

   	if (attributes.test(ATTR_char))     
		a += "char ";

   	if (attributes.test(ATTR_int))      
		a += "int ";

   	if (attributes.test(ATTR_null))     
		a += "null ";

   	if (attributes.test(ATTR_string))   
		a += "string ";

	if (attributes.test(ATTR_struct)){
		a += "struct {";
		a += *struct_name;
		a += "} ";
	}
   	if (attributes.test(ATTR_array))    
		a += "array ";

   	if (attributes.test(ATTR_function)) 
		a += "function ";

   	if (attributes.test(ATTR_proto))    
		a += "prototype ";

   	if (attributes.test(ATTR_variable)) 
		a += "variable ";

   	if (attributes.test(ATTR_field))    
		a += "field ";
	
	
   	if (attributes.test(ATTR_typeid))   
		a += "typeid ";

   	if (attributes.test(ATTR_param))    
		a += "param ";

   	if (attributes.test(ATTR_lval))     
		a += "lval ";

   	if (attributes.test(ATTR_const))    
		a += "const ";

   	if (attributes.test(ATTR_vreg))     
		a += "vreg ";

   	if (attributes.test(ATTR_vaddr))    
		a += "vaddr ";

   	return a.c_str();	


}


