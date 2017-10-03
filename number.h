#ifndef NUMBER_H
#define NUMBER_H

#include "simpleOb.h"
#include "variable.h"
#include <string>
using std::string ;

class Number : public SimpleOb {
public:
    Number(int i):_value(i) {}
    string const symbol() { return std::to_string( _value ); }
    string const value() { return std::to_string( _value ) ; }
    bool const match ( SimpleOb &simOb ) { return value() == simOb.symbol() ; } // Number = Atom
    bool const match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( _value ) ;
            var.alreadyAssign() ;
        }
        else if ( stoi( var.value() ) == _value ){
            ret = true ;
        }
        return ret ;
    } // Number match Variable

private:
    int _value = -1; // Number with int type
};

#endif
