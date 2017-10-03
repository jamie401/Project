#ifndef VAR_H
#define VAR_H

#include "simpleOb.h"
#include <string>
using std::string;

class Variable : public SimpleOb {
public:
    Variable(string s):_symbol(s) {}
    const string value() { return std::to_string( _value ) ; }
    const string symbol() { return _symbol ; }
    const bool assignable() { return _assignable ; }
    const void alreadyAssign() { _assignable = false ; }
    const void setValue( int i ) { _value = i ; }
    const void setSymbol( string s ) { _symbol = s ; }
    const bool match( SimpleOb &simOb) {
        bool ret = _assignable ;
        if ( _assignable ) {
            _value = std::stoi( simOb.value() ) ;
            _symbol = simOb.symbol() ;
            _assignable = false ;
        } // if
        else if ( std::stoi( simOb.value() ) == _value || simOb.symbol() == _symbol ) {
            ret = true ;
        } // else
        return ret ;
    } // Var match simpleObject

private:
    int _value = -1 ;
    string _symbol = "";
    bool _assignable = true ;
};

#endif
