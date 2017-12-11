#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <sstream>
using std::string;

template <class T>
class Iterator;
template <class T>
class BFSIterator;
template <class T>
class DFSIterator;

class Term{
public:
  virtual string symbol() const {return _symbol;}
  virtual string value() const {return symbol();}
  virtual bool match(Term & a);
  virtual Iterator<Term *> * createIterator();
  virtual Iterator<Term *> * createBFSIterator();
  virtual Iterator<Term *> * createDFSIterator();
protected:
  Term ():_symbol(""){}
  Term (string s):_symbol(s) {}
  Term(double db){
    std::ostringstream strs;
    strs << db;
    _symbol = strs.str();
  }
  string _symbol;
};

class Atom : public Term{
public:
  Atom(string s):Term(s) {}
};

#endif
