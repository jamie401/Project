#ifndef SIMPLEOB_H
#define SIMPLEOB_H

using std::string;
#include <string>

class SimpleOb {
public:
    virtual const string value() = 0;
    virtual const string symbol() = 0;
    virtual const bool match( SimpleOb &simOb ) = 0 ;
};

#endif
