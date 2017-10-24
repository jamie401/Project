#ifndef LIST_H
#define LIST_H

#include "term.h"

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

  }

  Term * elements(int index) {
    return _elements[index] ;
  }

public:
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}

  Term * head() const{
    return _elements.front() ;
  }
  List * tail() {
    vector<Term *> temp = _elements;
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
