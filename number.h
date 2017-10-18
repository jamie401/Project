#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include "variable.h"
#include <string>
#include <sstream>
using std::string ;

class Number : public Term {
public:
    Number(double i):_value(i) { ss << _value ; }
    string symbol() const { return ss.str(); }
    string value() const { return symbol() ; }
//    bool const match ( Term &term ) { return value() == term.value() ; } // Number = Atom
    bool match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( std::to_string( _value ) ) ;
            var.alreadyAssign() ;
        }
        else if ( var.value() == value() ){
            ret = true ;
        }
        return ret ;
    } // Number match Variable

private:
    std::stringstream ss ;
    double _value = 0.0; // Number with int type
    string _symbol = "";
};

#endif
