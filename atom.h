#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include <string>
using std::string ;

class Atom : public Term {
public:
    Atom(string s):_symbol(s), _value(s) {}
    string value() const { return _symbol ; }
    string symbol() const { return _symbol ; }
    bool match ( Term &term ) { return _value == term.value() ; }
    bool match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( _value ) ;
            var.alreadyAssign() ;
        }
        else {
            if ( var.value() == _value ) ret = true ;
        }
        return ret ;
    } // Atom match Variable

//private:
    string _symbol = "" ;
    string _value = "" ;
};

#endif
