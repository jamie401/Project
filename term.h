#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Term {
public:
    virtual string value() const { return symbol() ;}
    virtual string symbol() const = 0;
    virtual bool match( Term & term ) { return symbol() == term.symbol() ; }
};

#endif
