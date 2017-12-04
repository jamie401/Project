#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "variable.h"
#include "iterator.h"
#include <string>
using std::string ;

class Iterator;

class Atom : public Term {
public:
    Atom(string s):_symbol(s) {}
//    string value() const { return _symbol ; }
    string symbol() const { return _symbol ; }
    bool match ( Term &term ) { return _symbol == term.value() ; }
    bool match ( Variable &var ) {
        bool ret = var.assignable() ;
        if ( var.assignable() ) {
            var.setValue( this ) ;
            var.alreadyAssign() ;
        }
        else {
            if ( var.value() == _symbol ) ret = true ;
        }
        return ret ;
    } // Atom match Variable

    Iterator * createIterator(){
      return new NullIterator(this);
    }

private:
    string _symbol = "" ;
//    string _value = "" ;
};

#endif
