#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <sstream>

using std::string;

#include "term.h"

class Number : public Term{
public:
  Number(double db){
      std::ostringstream strs;
      strs << db;
      _symbol = strs.str();
  }
};

#endif
