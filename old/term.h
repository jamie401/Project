#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Iterator;

class Term {
public:
    virtual string value() const { return symbol() ;}
    virtual string symbol() const = 0;
    virtual bool match( Term & term ) { return symbol() == term.symbol() ; }
    virtual int arity() {}
    virtual Term * args(int a) {}
    virtual Iterator * createIterator();
};

#endif
