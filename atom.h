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
    bool const match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setSymbol( _symbol ) ;
            var.alreadyAssign() ;
        }
        else if ( var.symbol() == _symbol ){
            ret = true ;
        }
        return ret ;
    } // Number match Variable

private:
    string _symbol = "" ;
    int _value = -1 ;
};

#endif
