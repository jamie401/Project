#ifndef NUMBER_H
#define NUMBER_H

#include "Atom.h"
#include <string>
using std::string ;

class Number{
public:
    Number(string s):_symbol(s), _value(s) {}
    string const symbol() { return _symbol; }
    string const value() { return _value; }
    bool match ( Atom atom ) { return _value == atom.symbol() ; }
//    bool match( Atom atom) {
//        bool ret = _assignable ;
//        if ( _assignable ) {
//            _symbol = atom.symbol() ;
//            _assignable = false ;
//        } // if
//        else if ( atom.symbol() == _value ) {
//            ret = true ;
//        } // else
//        return ret ;
//    }

private:
    string _value ;
    string _symbol ;
    bool _assignable = true ;
};

#endif
