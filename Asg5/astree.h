#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include <bitset>
using namespace std;

#include "auxlib.h"

struct astree;

#include "symbol_table.h"


struct astree {
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
   size_t block_nr;	     // for project 4
   attr_bitset attributes;   // for porject 4
   symbol_entry* struct_entry;// for project 4
   bool visited = false;
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
  astree (int symbol, int filenr, int linenr,
           int offset, const char* clexinfo);
};
astree* new_astree (int symbol, int filenr, int linenr, int offset,
                    const char* lexinfo); 
// Append one child to the vector of children.
astree* adopt1 (astree* root, astree* child);

// Append two children to the vector of children.
astree* adopt2 (astree* root, astree* left, astree* right);

astree* adopt3 (astree* root, astree* left, astree* middle, astree* right);

astree* adopt1_sym (astree* root, astree* child, int symbol);

astree* adopt2_sym (astree* root, astree* left, astree* right, int symbol);

astree* change_sym(astree *root, int symbol);

// Dump an astree to a FILE.
void dump_astree (FILE* outfile, astree* root);

// Debug print an astree.
void yyprint (FILE* outfile, astree* yyvaluep);

// Recursively free an astree.
void free_ast (astree* tree);

// Recursively free two astrees.
void free_ast2 (astree* tree1, astree* tree2);




#endif

