// $Id: cppstrtok.cpp,v 1.4 2016-03-24 14:34:10-07 - - $

// Use cpp to scan a file and print line numbers.
// Print out each input line read in, then strtok it for
// tokens.

#include <string>
using namespace std;

#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <assert.h>
#include <unistd.h>
#include "auxlib.h"
#include "stringset.h"

string CPP = "/usr/bin/cpp";
constexpr size_t LINESIZE = 1024;

struct opt{

	bool suppress;
	char* arg;

};
//don't use
char* getFName(char* file){

	if(file == NULL){
		
		errprintf("%s: %s: %s: %s","Error",get_execname(),"getFName()","Null String Pointer");

	}
	
	char* temp = strcpy(temp,file);

	char* dot = strchr(temp,'.');

	if(dot == NULL){

		errprintf("%s: %s: %s: %s","Error",get_execname(),"getFName()","No extension detected.");
	
	}

	if(strcmp(dot,".")!=0){

		errprintf("%s: %s: %s: %s","Error",get_execname(),"getFName()","Incorrect extension, only .oc supported");

	}
	*dot  = '\0';

	return temp;	

}

void D_Operation(int argvar, char**  argstr, struct opt * opt_ptr ){

	int opt;

	opterr = 0;

	while((opt = getopt(argvar,argstr,"@:D:ly"))!=-1){

		switch(opt){
			
			case '@': set_debugflags(optarg);
			break;

			case 'D': opt_ptr -> suppress = true;
				opt_ptr -> arg = optarg;
			break;

			case 'l':

			case 'y': 

			default: errprintf("Error debug options\n");
		

		}



	}

}


// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}


// don't use
void cpplines (FILE* pipe, char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, filename);
      if (sscanf_rc == 2) {
         printf ("DIRECTIVE: line %d file \"%s\"\n", linenr, filename);
         continue;
      }
      char* savepos = NULL;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         printf ("token %d.%d: [%s]\n",
                 linenr, tokenct, token);
      }
      ++linenr;
   }
}

int main (int argc, char** argv) {

	set_execname (argv[0]);
	struct opt debug;
	debug.suppress = false;
	debug.arg = NULL;
	D_Operation(argc,argv,&debug);
	const char * fname = optind == argc ? "-" : argv[optind];
	char * cmd = new char[CPP.size() + 1 + strlen(fname) + 1];
	strcpy(cmd,CPP.c_str());
	strcat(cmd," ");
	if(debug.suppress){
		strcat(cmd,debug.arg);
		strcat(cmd," ");	
	}
	strcat(cmd,fname);
	FILE *pipe = popen (cmd, "r");
	int linenr = 1;
	if (pipe == NULL) {
	syserrprintf (cmd);
	}else{
		for (;;){
			char buffer[1024];
        		char* fgets_rc = fgets(buffer, LINESIZE, pipe);
			if (fgets_rc == NULL)
				break;
        		chomp (buffer, '\n');
        		int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",&linenr, fname);
			if (sscanf_rc == 2) {
			printf ("DIRECTIVE: line %d file \"%s\"\n", linenr, fname);
				continue;
			}
			char* savepos = NULL;
            		char* bufptr = buffer;
            		for (int tokenct = 1;; ++tokenct) {
            			char* token = strtok_r (bufptr, " \t\n", &savepos);
            			bufptr = NULL;
            			if (token == NULL) 
					break;
            			const string* str = intern_stringset (token);
			}
           	}
	}
	char* out = basename( (char*) fname);
	string put = strtok(out, ".");
	put += ".str";
	FILE* o = fopen(put.c_str(), "w");
	dump_stringset(o);
	{
   return get_exitstatus();
}

