#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <string>
using std::string;

class Variable : public Term {
public:
    Variable(string s):_symbol(s) { _value = NULL ;}
    string value() const {
      if ( _value != NULL ) return _value->value() ;
      return symbol() ;
    }
    string symbol() const { return _symbol ; }
    const bool assignable() { return _assignable ; }
    const void alreadyAssign() { _assignable = false ; }
    const void setValue( Term * term ) { _value = term ; }
    const bool not_value() { if( _value == NULL ) return true ; }
    bool match( Term &term) {
        bool ret = _assignable ;
        Variable *pv = dynamic_cast<Variable *>(&term);
        if ( _assignable ) {
          _value = &term ;
          _assignable = false ;
        } // if
        else if ( term.value() == _value->value() ) {
            ret = true ;
        } // else
        else if ( _value->match(term) ) ret = true ;
        else if (pv) // X.match(X) , Y.match(X)
          if ( pv-> assignable()){
            pv->setValue( _value ) ;
            return true;
          }
        return ret ;
    } // Var match simpleObject

private:
    Term * _value;
    string _symbol = "";
    bool _assignable = true ; // 是否可以assign
};

#endif
