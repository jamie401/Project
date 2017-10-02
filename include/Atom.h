#ifndef ATOM_H
#define ATOM_H

#include <string>
using std::string ;

class Atom {
public:
    Atom(string s):_symbol(s){}
    string const symbol() { return _symbol ; }

private:
    string _symbol ;
};

#endif
