#ifndef VAR_H
#define VAR_H

#include "SimpleOb.h"
#include <string>
using std::string;

class Var : public SimpleOb {
public:
    Var(string s):_value(s), _symbol(s) {}
    const string value() { return _value ; }
    const string symbol() { return _symbol ; }
    const bool match( SimpleOb &simOb) {
        bool ret = _assignable ;
        if ( _assignable ) {
            _symbol = simOb.symbol() ;
            _assignable = false ;
        } // if
        else if ( simOb.symbol() == _value ) {
            ret = true ;
        } // else
        return ret ;
    }

private:
    string _value ;
    string _symbol ;
    bool _assignable = true ;
};

#endif
