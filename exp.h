#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include <vector>
#include <iostream>

using std::vector;

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getExpressionResult() = 0;
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  string getExpressionResult() {

    if(evaluate()) {
      if( _left->symbol() == _right->symbol()) {
        return "true";
      }
      return _left->symbol() + " = " + _right->value();
    }
    else {
      return "false";
    }
  }

  bool evaluate(){
    return _left->match(*_right);
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  string getExpressionResult() {
    string output = "";
    bool noSameExp = true;
    static vector<string> _vectorOfExp;
    if(evaluate()){

      if ( _vectorOfExp.size() == 0 ) // _vectorOfExp is null
      {
        std::cout << "\n1\n" ; //
        _vectorOfExp.push_back( _left->getExpressionResult() ) ;
        output += _left->getExpressionResult() ;
      }
      else
      {
        std::cout << "\nelse\n" ; //
        for( int index = 0 ; index < _vectorOfExp.size() ; index++ )
          if( _vectorOfExp[index] == _left->getExpressionResult() )
            noSameExp = false ;

        if( noSameExp )
        {
          std::cout << "\nnoSameExp\n" ; //
          _vectorOfExp.push_back( _left->getExpressionResult() ) ;
          output += _left->getExpressionResult() ;
        }
      }

      for( int index = 0 ; index < _vectorOfExp.size() ; index++ )
        std::cout << "exp.h_getConjExpRusult:No." << index << ":" << _vectorOfExp[index] << "|end|\n" ;
      MatchExp* dM = dynamic_cast<MatchExp *>(_right);
      if (dM)
      {
        if( dM->evaluate() && noSameExp )
          return output + ", " + _right->getExpressionResult();
        else if ( dM->evaluate() )
          return output + _right->getExpressionResult();
      }

      return output + _right->getExpressionResult();
    }
    else
      return "false"; // evaluate() = false

  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  string getExpressionResult() {
    return "1";
  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
