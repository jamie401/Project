#ifndef NUMBER_H
#define NUMBER_H

#include "SimpleOb.h"
#include "Var.h"
#include <string>
using std::string ;

class Number : public SimpleOb {
public:
    Number(string s):_value(s) {}
    string const symbol() { return _value; }
    string const value() { return _value; }
    bool const match ( SimpleOb &simOb ) { return _value == simOb.symbol() ; } // Number = Atom
    bool const match ( Var &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( value() ) ;
            var.alreadyAssign() ;
        }
        else if ( var.value() == _value ){
            ret = true ;
        }
        return ret ;
    } // Number match Var

private:
    string _value ;
};

#endif
