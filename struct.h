#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include "variable.h"
#include <vector>
#include <string>

using std::string;

class Struct: public Term {
public:
  Struct(Atom name, std::vector<Term *> args): _name(name) {
    _args = args;
  }

  Iterator * createIterator();

  Term * args(int index) {
    return _args[index];
  }

  Atom & name() {
    return _name;
  }
  string symbol() const {
    if(_args.empty())
    return  _name.symbol() + "()";
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->symbol()+", ";
    ret  += (*it)->symbol()+")";
    return ret;
  }

  string value() const {
    string ret = _name.symbol() + "(";
    std::vector<Term *>::const_iterator it = _args.begin();
    for (; it != _args.end()-1; ++it)
      ret += (*it)->value()+", ";
    ret  += (*it)->value()+")";
    return ret;
  }
  int arity() const {return _args.size();}

  void haveVar(Variable *var){ // have same Variable, then match
    for(int i = 0; i < _args.size() ; i++) {
      if( var->symbol() == _args[i]->symbol() ){
        var->match(*(_args[i]));
        return;
      }
      Struct * ps = dynamic_cast<Struct *>(_args[i]);
      if(ps) ps->haveVar(var);
    }
  }

private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
