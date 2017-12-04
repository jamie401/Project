#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include "variable.h"
#include <string>
#include <sstream>
using std::string ;

class Iterator;

class Number : public Term {
public:
    Number(double i):_value(i) { ss << _value ; }
    string symbol() const { return ss.str(); }
//    string value() const { return symbol() ; }
    bool match ( Term &term ) { return symbol() == term.value() ; } // Number = Atom
    bool match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( this ) ;
            var.alreadyAssign() ;
        }
        else if ( var.value() == symbol() ){
            ret = true ;
        }
        return ret ;
    } // Number match Variable

    Iterator * createIterator(){
      return new NullIterator(this);
    }

private:
    std::stringstream ss ;
    double _value = 0.0; // Number with int type
    string _symbol = "";
};

#endif
