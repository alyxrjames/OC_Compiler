#include "stringset.h"
#include "symboltable.h"
#include "lyutils.h"

size_t glb_blk = 0;
size_t next_block = 1;
symbol_table variables;
symbol_table structs;
vector<symbol_table*> symbol_stack;

void process_ast(astree* root, FILE* o){


	for(int i = 0; i < root->children.size();i++){
		if(!root->children.empty()){
			process_ast(root -> children.at(i),o);
		}
		switch(root->symbol){
			
			case TOK_FUNCTION: seed_function(root); break;
			case TOK_PROTOTYPE: seed_prototype(root); break;
			case TOK_VARDECL: seed_variable(root); break;
			case TOK_BLOCK: incr_block(); break;
			case TOK_STRUCT: seed_struct(root); break;	
			default: break;
		}
	}
}
symbol * newsymbol(astree * node){
	symbol* sym = new symbol();
	sym -> filenr = node -> filenr;
	sym -> linenr = node -> linenr;
	sym -> offset = node -> offset;
	sym -> block_nr = glb_blk;
	sym -> attributes = node -> attributes;	
	return sym;
}
void set_field(symbol * s, symbol_table * st){
	s -> fields = st;

}
void set_parameters(symbol * s, vector<symbol*>* param){
	s -> parameters = param
}
void set_attributes(astree * node){

	switch(node->symbol){

			case TOK_VOID:		node->attributes.set(ATTR_void);
						for(auto& ch:node->children){
							ch->attributes.set(ATTR_void);
						}
						break;

			case TOK_INT:		node->attributes.set(ATTR_int);
						for(auto& ch:node->children){
							ch->attributes.set(ATTR_int);
						}
						break;

			case TOK_CHAR:		node->attributes.set(ATTR_char);
						for(auto& ch:node->children){
							ch->attributes.set(ATTR_char);
						}
						break;

			case TOK_STRING: 	node->attributes.set(ATTR_string);
						for(auto& ch:node->children){
							ch->attributes.set(ATTR_string);
						}	
					 	break;

			case TOK_INTCON: 	node->attributes.set(ATTR_const);
						node->attributes.set(ATTR_int);
					 	break;

			case TOK_CHARCON: 	node->attributes.set(ATTR_const);
						node->attributes.set(ATTR_char);
					  	break;

			case TOK_STRINGCON: 	node->attributes.set(ATTR_const);
						node->attributes.set(ATTR_string);
					    	break;

			case TOK_NULL:		node->attributes.set(ATTR_null);
						node->attributes.set(ATTR_const);
						break;

			case TOK_STRUCT: 	node->attributes.set(ATTR_struct);
						node->attributes.set(ATTR_typeid);
						node->children[0]->attributes.set(ATTR_struct);
						break;

			case TOK_TYPEID: 	node->attributes.set(ATTR_typeid);
						for(auto &ch:node->children){
							ch->attributes.set(ATTR_typeid);
						}		
						break;
						
			case TOK_FUNCTION: 	node->attributes.set(ATTR_function);
						break;

			case TOK_ARRAY:		node->attributes.set(ATTR_array);
						for(auto &ch:node->children){
							ch->attributes.set(ATTR_array);
						}	
						break;

			case TOK_PARAMLIST:	node->attributes.set(ATTR_param);
						for(auto &ch:node->children){
							ch->attributes.set(ATTR_param);
						}	
						break;

			case TOK_FIELD:		node->attributes.set(ATTR_field);
						node->attributes.set(ATTR_lval);	
						for(auto &ch:node->children){
							ch->attributes.set(ATTR_field);
						}	
						break;

			case TOK_IDENT:		node->attributes.set(ATTR_lval);
						break;

			case TOK_DECLID:	node->attributes.set(ATTR_lval);
						break;

			case TOK_VARDECL	node->attributes.set(ATTR_variable);
						break;

			default:	break;
	}
		
	return;
}
void seed_function(astree* node){

	

}
void seed_prototype(astree* node){
	node -> children[0];
}
void seed_variable(astree* node){


}
void seed_struct(astree* node){
	
	symbol * s = newsymbol(node->children[0]);
		
	structs.pushback(s);
	return;

}
void enter_block(){
	next_block++;
	symbol_stack.push_back(nullptr);	


}
void exit_block(){
	symbol_stack.pop();
}





















