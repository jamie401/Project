#ifndef TERM_H
#define TERM_H

#include <string>
#include <sstream>

class Variable;
class Struct;
class Iterator;
class Term {
public:
  virtual string symbol() const {return _symbol;}
  virtual string value() const {return symbol();}
  virtual bool match(Term & a);
  virtual Iterator * createIterator();
  virtual Struct* getStruct() {
    return nullptr;
  }
  virtual Variable* getVariable() {
    return nullptr;
  }
protected:
  Term (string s = ""):_symbol(s) {}
  string _symbol;
};

#endif
