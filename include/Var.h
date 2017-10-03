#ifndef VAR_H
#define VAR_H

#include "SimpleOb.h"
#include <string>
using std::string;

class Var : public SimpleOb {
public:
    Var(string s):_symbol(s) {}
    const string value() { return _value ; }
    const string symbol() { return _symbol ; }
    const bool assignable() { return _assignable ; }
    const void alreadyAssign() { _assignable = false ; }
    const void setValue( string s ) { _value = s ; }
    const bool match( SimpleOb &simOb) {
        bool ret = _assignable ;
        if ( _assignable ) {
            _value = simOb.value() ;
            _assignable = false ;
        } // if
        else if ( simOb.value() == _value ) {
            ret = true ;
        } // else
        return ret ;
    } // Var match simpleObject

private:
    string _value ;
    string _symbol ;
    bool _assignable = true ;
};

#endif
