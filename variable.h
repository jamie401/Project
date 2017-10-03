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
    const bool match( SimpleOb &simOb) {
        bool ret = _assignable ;
        if ( _assignable ) {
            _value = stoi( simOb.value() ) ;
            _assignable = false ;
        } // if
        else if ( stoi( simOb.value() ) == _value ) {
            ret = true ;
        } // else
        return ret ;
    } // Var match simpleObject

private:
    int _value = 0 ;
    string _symbol ;
    bool _assignable = true ;
};

#endif
