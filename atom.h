#ifndef ATOM_H
#define ATOM_H

#include "simpleOb.h"
#include <string>
using std::string ;

class Atom : public SimpleOb {
public:
    Atom(string s):_symbol(s) {}
    const string value() { return _symbol ; }
    const string symbol() { return _symbol ; }
    const bool match ( SimpleOb &simOb ) { return _symbol == simOb.symbol() ; }

private:
    string _symbol ;
};

#endif
