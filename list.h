#ifndef LIST_H
#define LIST_H

#include "term.h"
#include "variable.h"
#include "atom.h"

#include <iostream>
#include <vector>
using std::vector;

class List : public Term {
public:
  string symbol() const {
    if ( _elements.empty() ) return "[]" ;
    string ret = "[";
    for(int i = 0; i < _elements.size() - 1 ; i++){
      ret += _elements[i]-> symbol() + ", ";
    }
    ret += _elements[_elements.size()-1]-> symbol() + "]";
    return  ret;
  }

  string value() const {
    if ( _elements.empty() ) return "[]" ;
    string ret = "[";
    for(int i = 0; i < _elements.size() - 1 ; i++){
      ret += _elements[i]-> value() + ", ";
    }
    ret += _elements[_elements.size()-1]-> value() + "]";
    return  ret;
  }

  bool match(Term & term) {
    List * ps = dynamic_cast<List *>(&term);
    Variable  * pv = dynamic_cast<Variable *>(&term);
    if (ps){
      if(_elements.size()!= ps->_elements.size())
        return false;
      for(int i=0;i<_elements.size();i++){
        if(_elements[i]->symbol() != ps->_elements[i]->symbol())
          if( !_elements[i]->match( *(ps->_elements[i]) ) )
            return false;
      }
      return true;
    }
    else if (pv){
      if ( pv->assignable() ) {
        pv->setValue( this ) ;
        pv->alreadyAssign() ;
        return true;
      }
    }
    return false;
  }

public:
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}

  Term * head() const{
    if (_elements.empty()) throw "Accessing head in an empty list" ;
    return _elements.front() ;
  }

  List * tail() {
    vector<Term *> temp = _elements;
    if (_elements.empty()) throw string("Accessing tail in an empty list") ;
    if ( temp.size() > 0 ) {
      temp.erase( temp.begin() ) ;
      List *l = new List(temp);
      return l ;
    }
    else return this ;
  }

private:
  vector<Term *> _elements;

};

#endif
