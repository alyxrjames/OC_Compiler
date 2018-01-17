#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map> 
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;


enum { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
ATTR_string, ATTR_struct, ATTR_array, ATTR_function, ATTR_proto,
ATTR_variable, ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval,
ATTR_const, ATTR_vreg, ATTR_vaddr, ATTR_bitset_size 
};

struct symbol;
using attr_bitset = bitset<ATTR_bitset_size>;
using symbol_table = unordered_map<string*,symbol*>;
using symbol_entry = pair<const string*,symbol*>;
using symbol_stack = vector<symbol_table*>;

#include "astree.h"
#include "auxlib.h"


struct symbol {

	attr_bitset attributes;
	symbol_table* fields;
	size_t filenr, linenr, offset;
	size_t block_nr;
	string * type_id;
	vector<symbol*>* parameters;

};

void set_sym_file(FILE * f);
//to be called to fill the symbol tables
void init_stack();

//gets the attribute information for the dump 
//const char * get_attr(attr_bitset attr);

//inserts the symbol into the table
//bool insert_sym(symbol_table * table, symbol * s,
//string * name);

//defines any new types made by struc

void get_func_names(astree * node);

void set_attr_rc(astree * root);

const char * get_attr(attr_bitset attr,string *);

void free_t();


#endif //

