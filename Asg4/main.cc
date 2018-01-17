#include <string>
#include <vector>
using namespace std;

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include  <unistd.h>
#include <cstring>
#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"
#include "stringset.h"

const string cpp_name = "/usr/bin/cpp";
string yyin_cpp_command;
int D_flag;
string D_string;
FILE* str_set;

void cpp_popen(const char* filename){

	yyin_cpp_command = cpp_name;
	yyin_cpp_command += " ";
	if(!D_string.empty()){
		yyin_cpp_command += "-D ";
		yyin_cpp_command += D_string;	
		yyin_cpp_command += " ";
	}
	yyin_cpp_command += filename;
//	printf("\n%s\n",yyin_cpp_command.c_str());
	yyin = popen(yyin_cpp_command.c_str(),"r");
	str_set = popen(yyin_cpp_command.c_str(),"r");

}
void cpp_pclose(){

	int pclose_rc = pclose(str_set);
	//eprint_status(yyin_cpp_command.c_str(), pclose_rc);
	if(pclose_rc != 0) set_exitstatus(EXIT_FAILURE);


}
void scan_opt(int argc, char* argv[]){

	int option;
	opterr = 0;
	yy_flex_debug = 0;
	yydebug = 0;
	while(true){
		option = getopt(argc,argv,"@:D:ly");
		if(option == -1) break;
		switch(option){
			
				
			case '@': set_debugflags(optarg); break;
			case 'l': yy_flex_debug = 1; break;
			case 'y': yydebug = 1; break;
			case 'D': D_string = optarg;  break; 
			default : errprintf("%:bad option (%c)\n",optopt);break;
		}
	}
	if(optind > argc){
		errprintf("Usage: %s [-ly] [filename]\n",get_execname());
		exit(get_exitstatus());
	}

}
void cpp_lines(FILE* pipe, const char * name){
	int linenr = 1;
	char input[1024];
	strcpy(input,name);
	while(fgets(input,1024,pipe)!=NULL){


		if(sscanf(input,"# %d \"%[^\"]\"",&linenr,name) == 2){

			continue;
		}
		char * savepos = NULL;
		char * buffptr = input;
		char * token = strtok_r(buffptr," \t\n",&savepos);	
			if(token != NULL){
				intern_stringset(strdup(token));
			}
		while(true){

			char * token = strtok_r(NULL," \t\n",&savepos);
			if(token == NULL)break;
			else {
				intern_stringset(strdup(token));	
			}	

		}
		linenr++;

	}	

}
int main(int argc, char* argv[]){


	const char * cmd_arg_file = argv[argc-1]; 	
	scan_opt(argc,argv);
	//printf("\n%s\n",D_string.c_str());	
	cpp_popen(cmd_arg_file);
		
	cpp_lines(str_set,cmd_arg_file);
	cpp_pclose();	

	char * outfile = basename((char*)cmd_arg_file);
	string outfile_dot_str = strtok(outfile,".");	
	outfile_dot_str += ".str";
	//	printf("\n%s\n",outfile_dot_str.c_str());	
	FILE * str_outfile = fopen(outfile_dot_str.c_str(),"w");
	dump_stringset(str_outfile);
	fclose(str_outfile);	

	string outfile_dot_tok = strtok(outfile,".");
	outfile_dot_tok += ".tok";
	FILE* tok_outfile = fopen(outfile_dot_tok.c_str(),"w");

	set_tok_file(tok_outfile);
	//while(yylex()!=YYEOF){}
	yyparse();	
	fclose(tok_outfile);

	string outfile_dot_ast = strtok(outfile,".");
	outfile_dot_ast += ".ast";
	FILE* ast_outfile = fopen(outfile_dot_ast.c_str(),"w");
	dump_astree(ast_outfile,yyparse_astree);

	fclose(ast_outfile);
	
return 0;
}
