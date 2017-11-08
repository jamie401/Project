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
    vector<Term*> terms ;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
          _scanner.nextToken() ;
          terms = getArgs();
          if(_currentToken == ')' || _scanner.currentChar() == ')')
            return new Struct(*atom, terms);
        }
        else
          return atom;
    }
    else if( token == LIST ){
      printf("\n--11--\n" );
      if(_scanner.currentChar() == '[') {
        printf("\n--22--\n" );
        _scanner.nextToken();
        terms = getArgs();
        if(_currentToken == ']' || _scanner.currentChar() == ']') {
          printf("\n--33--\n" );
          return new List(terms);
        }
      }
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    vector<Term*> args ;
    if( _scanner.currentChar() == ')' || _scanner.currentChar() == ']' ) return args;
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
