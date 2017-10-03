#ifndef NUMBER_H
#define NUMBER_H

#include "SimpleOb.h"
#include "Var.h"
#include <string>
using std::string ;

class Number : public SimpleOb {
public:
    Number(int i):_value(i) {}
    string const symbol() { return std::to_string( _value ); }
    string const value() { return std::to_string( _value ) ; }
    bool const match ( SimpleOb &simOb ) { return value() == simOb.symbol() ; } // Number = Atom
    bool const match ( Var &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( _value ) ;
            var.alreadyAssign() ;
        }
        else if ( stoi( var.value() ) == _value ){
            ret = true ;
        }
        return ret ;
    } // Number match Var

private:
    int _value ; // Number with int type
};

#endif
