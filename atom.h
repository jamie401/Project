#ifndef ATOM_H
#define ATOM_H

#include "simpleOb.h"
#include "variable.h"
#include <string>
using std::string ;

class Atom : public SimpleOb {
public:
    Atom(string s):_symbol(s) {}
    const string value() { return _symbol ; }
    const string symbol() { return _symbol ; }
    const bool match ( SimpleOb &simOb ) { return _value == simOb.value() ; }
    bool const match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( _value ) ;
            var.alreadyAssign() ;
        }
        else if ( var.value() != _value ) {
            ret = true ;
        }
        return ret ;
    } // Atom match Variable

private:
    string _symbol = "" ;
    string _value = "" ;
};

#endif
