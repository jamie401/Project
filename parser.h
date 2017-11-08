#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "number.h"
#include "term.h"
#include "list.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
          _scanner.nextToken() ;
          vector<Term*> terms = getArgs();
          if(_currentToken == ')' || _scanner.currentChar() == ')')
            return new Struct(*atom, terms);
        }
        else
          return atom;
    }
    else if( token == '[' ){
      _scanner.skipLeadingWhiteSpace();
      if(_scanner.currentChar() == ')') throw string("unexpected token") ;
      if( _scanner.currentChar() == ']') {
        _scanner.nextToken();
        return new List();
      }
      else {
        vector<Term*> terms = getArgs();
        if(_currentToken == ')') throw string("unexpected token") ;
        if( _currentToken == ']' )
          return new List(terms);
      }
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    vector<Term*> args ;
    if( _scanner.currentChar() == ')' || _scanner.currentChar() == ']' ) {
      return args;
    }
    Term* term = createTerm();
    if(term)
      args.push_back(term);
    while((_currentToken = _scanner.nextToken()) == ',') {
      args.push_back(createTerm());
    }
    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif
