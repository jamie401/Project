#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "iterator.h"
#include "number.h"

// s( 1, t(X, 2), Y )
TEST(iterator, struct_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    // StructIterator it(&s);
    Iterator<Term *> *itStruct = s.createIterator();
    // Iterator& itStruct = it;
    // ASSERT_EQ(it.first()->symbol());
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

// s(1, t(X, 2), Y)
TEST(iterator, nested_struct_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  Iterator<Term *> *it = s.createIterator();
  it->first();
  it->next();
  Struct *s2 = dynamic_cast<Struct *>(it->currentItem());

  Iterator<Term *> *it2 = s2->createIterator();
  it2->first();
  ASSERT_EQ("X", it2->currentItem()->symbol());
  ASSERT_FALSE(it2->isDone());
  it2->next();
  ASSERT_EQ("2", it2->currentItem()->symbol());
  ASSERT_FALSE(it2->isDone());
  it2->next();
  ASSERT_TRUE(it2->isDone());
}

// [ 1, t(X, 2), Y ]
TEST(iterator, list_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator<Term *> *itList = l.createIterator();
//    ListIterator it(&l);
//    Iterator* itList = &it;
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

// [ 1, [X, 2], Y ]
TEST(iterator, nested_list_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    List l2( { &X, &two } );
    List l({ &one, &l2, &Y } );
    Iterator<Term *> *itList = l.createIterator();
//    ListIterator it(&l);
//    Iterator* itList = &it;
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    List *pl = dynamic_cast<List *>(itList->currentItem());
    Iterator<Term *> *it2 = pl->createIterator();
    it2->first();
    ASSERT_EQ("X", it2->currentItem()->symbol());
    ASSERT_FALSE(it2->isDone());
    it2->next();
    ASSERT_EQ("2", it2->currentItem()->symbol());
    ASSERT_FALSE(it2->isDone());
    it2->next();
    ASSERT_TRUE(it2->isDone());
}

// 1
TEST(iterator, null_Iterator){
  Number one(1);
  // Iterator *itNum = one.createIterator();
  // // NullIterator nullIterator(&one);
  // nullIterator.first();
  // ASSERT_TRUE(nullIterator.isDone());
  Iterator<Term *> * it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}



#endif
