const char * docstring="search query database cutoff output\n"
"  query    - query fingerpint in contactlib-DNN format.\n"
"  database - contactlib-DNN format structure database.\n"
"  cutoff   - an int to initialize database. Recommended value: 12\n"
"  output   - output file name\n"
"\n"
"Example:\n"
"  search 3aa0a.cl ~/.cache/contactlib/contactlib-l4-g0-c2-d7.db 12 output.txt\n"
;

#include "Library.h"
#include "Common.h"
#include "Search.h"

using namespace std;

int main(int argc, char **args)
{
  // parse parameters
  if (argc != 5)
  {
    cerr<<docstring<<endl;
    return 1;
  }
  int index = 1;
  string tfn = args[index++];
  string dbfn = args[index++];
  int cutoff = atoi(args[index++]);
  string res_fn = args[index++];

  // read target and database
  cerr << "#preprocessing" << endl;
  void *db = newDB(dbfn.c_str(), cutoff);

  vector<string> tfns = loadFilenames(tfn);
  for (int tfnIndex = 0; tfnIndex < tfns.size(); tfnIndex++)
  {
    cerr << "#working on target " << tfnIndex << "/" << tfns.size() << endl;
    search(db, tfns[tfnIndex].c_str(), res_fn.c_str());
  }
  deleteDB(db);
  cerr << "done!!!" << endl;
  return 0;
}
