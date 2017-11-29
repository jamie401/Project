#ifndef NODE_H
#define NODE_H

#include "term.h"

enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};
            //  SEMICOLON ; COMMA , EQUALITY =
class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t, Node *l, Node *r):payload(op), term(t), left(l), right(r) {}

  bool evaluate() {
    switch(payload)
    {
      case SEMICOLON:
        {
          bool l = left->evaluate();
          bool r = right->evaluate();
          return l || r ;
        }
      case COMMA:
        {
          bool l = left->evaluate();
          bool r = right->evaluate();
          return l && r ;
        }
        return left->evaluate() && right->evaluate() ;
      case EQUALITY:
        return left->term->match(*(right->term)) ;
    }
  }
  Operators payload;
  Term* term;
  Node* left;
  Node* right;
};

#endif
