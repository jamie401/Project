#ifndef VAR_H
#define VAR_H

#include "simpleOb.h"
#include <string>
using std::string;

class Variable : public SimpleOb {
public:
    Variable(string s):_symbol(s) {}
    const string value() { return _value ; }
    const string symbol() { return _symbol ; }
    const bool assignable() { return _assignable ; }
    const void alreadyAssign() { _assignable = false ; }
    const void setValue( string s ) { _value = s ; }
//    const void setSymbol( string s ) { _symbol = s ; }
    const bool match( SimpleOb &simOb) {
        bool ret = _assignable ;
        if ( _assignable ) {
            _value = simOb.value() ;
            _symbol = simOb.symbol() ;
            _assignable = false ;
        } // if
        else if ( simOb.value() == _value ) {
            ret = true ;
        } // else
        return ret ;
    } // Var match simpleObject

private:
    string _value = "" ;
    string _symbol = "";
    bool _assignable = true ;
};

#endif
