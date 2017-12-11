#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include <stack>
#include <queue>
using std::stack;
using std::queue;

template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};

template <class T>
class NullIterator :public Iterator<T>{
public:
  friend class Term;
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }
private:
  NullIterator(Term *n){}
};

template <class T>
class StructIterator :public Iterator<T> {
public:
  friend class Struct;

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
private:
  StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};

template <class T>
class ListIterator :public Iterator<T> {
public:
  friend class List;

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  ListIterator(List *list): _index(0), _list(list) {}
  int _index;
  List* _list;
};

template <class T>
class BFSIterator :public Iterator<T> {
public:
  friend class Struct;
  friend class List;

  void first(){
    _itQueue.push( _term->createIterator() ) ;
  }

  void next(){
    if( !isDone())
      if( haveChild() ){
        _itQueue.push( currentItem()->createIterator() ) ;
        _itQueue.front()->next();
        if( _itQueue.front()->isDone() )
          _itQueue.pop();
      } // haveChild()
      else {
        _itQueue.front()->next();
        if( _itQueue.front()->isDone() )
          _itQueue.pop();
      } // !haveChild()
  }

  Term* currentItem() const {
    return _itQueue.front()->currentItem();
  }

  bool isDone() const {
    return _itQueue.empty() ;
  }

private:
  BFSIterator(Term* term):_term(term) {}
  Term* _term;
  queue<Iterator<Term *> *> _itQueue ;
  bool haveChild() { return !currentItem()->createIterator()->isDone() ; }
};

template <class T>
class DFSIterator :public Iterator<T> {
public:
  friend class Struct;
  friend class List;

  void first(){
    _itStack.push( _term->createIterator() ) ;
  }

  void next(){
    if( !isDone())
      if( haveChild() ) _itStack.push( currentItem()->createIterator() ) ;
      else {
        _itStack.top()->next();
        while (!isDone() && _itStack.top()->isDone()) {
          _itStack.pop();
          if (!isDone())
            _itStack.top()->next();
        }
      } // !haveChild()
  }

  Term* currentItem() const {
    return _itStack.top()->currentItem();
  }

  bool isDone() const {
    return _itStack.empty() ;
  }

private:
  DFSIterator(Term* term):_term(term) {}
  Term* _term;
  stack<Iterator<Term *> *> _itStack ;
  bool haveChild() { return !currentItem()->createIterator()->isDone() ; }
};

#endif
