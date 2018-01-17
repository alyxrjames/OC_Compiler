#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

#include <vector>
#include <bitset>
#include <unordered_map>



enum { ATTR_void, ATTR_int, ATTR_char, ATTR_null, ATTR_string,
ATTR_struct, ATTR_array, ATTR_function, ATTR_variable, 
ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const, 
ATTR_vreg, ATTR_vaddr, ATTR_bitset_size };

struct symbol;

using symbol_table = unordered_map<string*,symbol*>;
using symbol_entry = symbol_table::value_type;
using attr_bitset = bitset<ATTR_bitset_size>;
//using symbol_stack = vector<symbol_table*>; 




struct symbol{

	attr_bitset attributes;
	symbol_table * fields;
	size_t filenr, linenr, offset;
	size_t blocknr;
	vector<symbol*>* parameters;

};

#include "astree.h"

void process_ast(astree* root, FILE* o);
void seed_function(astree* node);
void seed_prototype(astree* node);
void seed_variable(astree* node);
void seed_struct(astree* node);
void incr_block();
symbol* newsymbol(astree* node);





#endif
