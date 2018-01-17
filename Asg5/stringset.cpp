// $Id: stringset.cpp,v 1.12 2016-03-24 14:33:24-07 - - $

#include <iomanip>

#include <unordered_set>
using namespace std;

#include "stringset.h"

using stringset = unordered_set<string>;

stringset  set;

const string* intern_stringset (const char* string) {
   pair<stringset::const_iterator,bool> handle = set.insert (string);
   return &*handle.first;
}

void dump_stringset (FILE* o) {
   size_t max_bucket_size = 0;
   for (size_t bucket = 0; bucket < set.bucket_count(); ++bucket) {
      bool need_index = true;
      size_t curr_size = set.bucket_size (bucket);
      if (max_bucket_size < curr_size) max_bucket_size = curr_size;
      for (stringset::const_local_iterator itor = set.cbegin (bucket);
           itor != set.cend (bucket); ++itor) {
         if (need_index)
		fprintf(o, "hash[%4lu]:	",bucket);
                         
         else 
		fprintf(o,"%4s","");
         need_index = false;
         const string* str = &*itor;
        fprintf (o, "%20lu %p-> \"%s\" \n",set.hash_function()(*str),str, str->c_str());
	}
  }

  fprintf(o,"load_factor = %.3f\n" ,set.load_factor());

  fprintf(o,"bucket_count = %lu\n",set.bucket_count());

  fprintf(o,"max_bucket_size = %lu\n",max_bucket_size);

}

