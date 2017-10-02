#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using std::string ;

class Number{
public:
    Number(string s):_symbol(s), _value(s) {}
    string symbol() { return _symbol; }
    string value() { return _value; }


private:
    string _value ;
    string _symbol ;
};

#endif
