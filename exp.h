#ifndef EXP_H
#define EXP_H

#include "atom.h"
#include <vector>
#include <iostream>

using std::vector;

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getExpressionResult(vector<string> v) = 0;
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  string getExpressionResult(vector<string> v) {

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

  string getExpressionResult(vector<string> _vectorOfExp) {
    string output = "";
    bool noSameExp = true;
    if(evaluate()){

      if ( _vectorOfExp.size() == 0 ) // _vectorOfExp is null
      {
        _vectorOfExp.push_back( _left->getExpressionResult(_vectorOfExp) ) ;
        output += _left->getExpressionResult(_vectorOfExp) ;
      }

      MatchExp* dM = dynamic_cast<MatchExp *>(_right);
      if (dM) // if _righ is last(MatchExp)
      {
        for( int index = 0 ; index < _vectorOfExp.size() ; index++ )
          if( _vectorOfExp[index] == _right->getExpressionResult(_vectorOfExp) )
            return output ; // ExpressionResult already exist
        if ( dM->evaluate() )
        {
          if( trueAndExp( _vectorOfExp ) ){
            if( _left->getExpressionResult(_vectorOfExp) == "true" )
              return _right->getExpressionResult(_vectorOfExp); // if true, Exp only return Exp

            if( _right->getExpressionResult(_vectorOfExp) == "true" )
              return _left->getExpressionResult(_vectorOfExp); // if true, Exp only return Exp

          }

          if( _vectorOfExp[0].find(_right->getExpressionResult(_vectorOfExp)) != string::npos )
            return _vectorOfExp[0] ;
          return output + ", " + _right->getExpressionResult(_vectorOfExp); // normal return
        }

      }

    }
    else
      return "false"; // evaluate() = false

  }

  bool trueAndExp(vector<string> _vectorOfExp){
    if( _right->getExpressionResult(_vectorOfExp) != _left->getExpressionResult(_vectorOfExp) )
      if( _left->getExpressionResult(_vectorOfExp) == "true" || _right->getExpressionResult(_vectorOfExp) == "true" )
        return true ;
    return false;
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

  string getExpressionResult(vector<string> v) {
    v.clear();
    if(  _left->getExpressionResult( v ) == "false")
      return _right->getExpressionResult( v ) ;
    else if (  _right->getExpressionResult( v ) == "false" )
      return _left->getExpressionResult( v ) ;
    else
      return _left->getExpressionResult( v ) + "; " + _right->getExpressionResult( v ) ;

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
