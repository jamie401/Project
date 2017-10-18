#ifndef VAR_H
#define VAR_H

#include "term.h"
#include <string>
using std::string;

class Variable : public Term {
public:
    Variable(string s):_symbol(s) {}
    string value() const { return _value ; }
    string symbol() const { return _symbol ; }
    const bool assignable() { return _assignable ; }
    const void alreadyAssign() { _assignable = false ; }
    const void setValue( string s ) { _value = s ; }
//    const void setSymbol( string s ) { _symbol = s ; }
    bool match( Term &term) {
        bool ret = _assignable ;
        if ( _assignable ) {
            _value = term.value() ;
//            _symbol = simOb.symbol() ;
            _assignable = false ;
        } // if
        else if ( term.value() == _value ) {
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
