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
    try{
      if (_elements.empty()) throw 0 ;
      return _elements.front() ;
    }
    catch(...) {
      std::cout << "Accessing head in a an empty list" ;
    }
    Atom * temp_null = new Atom("0");
    return temp_null;

  }

  List * tail() {
    vector<Term *> temp = _elements;
    try {
      if (_elements.empty()) throw 0 ;
      if ( temp.size() > 0 ) {
        temp.erase( temp.begin() ) ;
        List *l = new List(temp);
        return l ;
      }
      else return this ;
    }
    catch(...) {
      std::cout << "Accessing tail in a an empty list" ;
    }
    List *l = new List(temp);
    return l;

  }

private:
  vector<Term *> _elements;

};

#endif
