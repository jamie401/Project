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
#include "node.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(), _rangeFirstIndex(0){}

  void matchings() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',' || _currentToken == '=' || _currentToken == ';') {
        if ( _currentToken == '=' ) {
          Node* left = new Node( TERM, _terms.back(), 0, 0 ) ;
          _terms.push_back(createTerm());
          Node* right = new Node( TERM, _terms.back(), 0, 0 );
          _expressionTree = new Node(EQUALITY, 0, left, right) ;
        }
        else if ( _currentToken == ',' ) {
          Node* left = _expressionTree ;
          matchings();
          Node* right = _expressionTree ;
          _expressionTree = new Node(COMMA, 0, left, right) ;
          // match the same variable
          for ( int i = _rangeFirstIndex ; i < _terms.size() ; i++ ) {
            Variable * pv = dynamic_cast<Variable *>(_terms[i]);
            if(pv)
              for ( int j = _rangeFirstIndex ; j < _terms.size() ; j++){
                if( ( pv->symbol() == _terms[j]->symbol() ) && j > i ){
                  printf("\nfuck_term[%d]\n", j );
                  pv->match(*(_terms[j]));
                }

              }
          }// for
        }
        else if ( _currentToken == ';' ) {
          _rangeFirstIndex = _terms.size();
          Node* left = _expressionTree ;
          matchings();
          Node* right = _expressionTree ;
          _expressionTree = new Node(SEMICOLON, 0, left, right) ;
        }

      } // while
    } // if
  } // matchings()

  Node* expressionTree() {
    return  _expressionTree ;
  }

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }



  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  Node* _expressionTree;
  int _rangeFirstIndex;
};
#endif
