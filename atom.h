#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <sstream>

using std::string;

#include "term.h"

class Atom : public Term{
public:
  Atom(string s):Term(s) {}
};

class Number : public Term{
public:
  Number(double db){
      std::ostringstream strs;
      strs << db;
      _symbol = strs.str();
  }
};

#endif
