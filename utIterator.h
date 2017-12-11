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

// s( 1, t(X, 2), Y )
TEST(iterator, struct_BFS_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator<Term *> *itStruct = s.createBFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

// s( 1, t(X, 2), Y )
TEST(iterator, struct_DFS_iterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator<Term *> *itStruct = s.createDFSIterator();
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("X", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("2", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

// [ 1, [X, 2], Y ]
TEST(iterator, list_BFS_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  List l2( { &X, &two } );
  List l({ &one, &l2, &Y } );
  Iterator<Term *> *itList = l.createBFSIterator();
  itList->first();
  ASSERT_EQ("1", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("[X, 2]", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("Y", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("X", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("2", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_TRUE(itList->isDone());
}

// [ 1, [X, 2], Y ]
TEST(iterator, list_DFS_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  List l2( { &X, &two } );
  List l({ &one, &l2, &Y } );
  Iterator<Term *> *itList = l.createDFSIterator();
  itList->first();
  ASSERT_EQ("1", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("[X, 2]", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("X", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("2", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("Y", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_TRUE(itList->isDone());
}

// [ X, s1( Y, [1] ), W ]
TEST(iterator, list_struct_BFS_iterator) {
  Number one(1);
  Variable X("X"), Y("Y"), W("W") ;
  List l({&one});
  Struct s1(Atom("s1"), {&Y, &l});
  List l2({&X, &s1, &W}) ;
  Iterator<Term *> *itList = l2.createBFSIterator();
  itList->first();
  ASSERT_EQ("X", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("s1(Y, [1])", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("W", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("Y", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("[1]", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_EQ("1", itList->currentItem()->symbol());
  ASSERT_FALSE(itList->isDone());
  itList->next();
  ASSERT_TRUE(itList->isDone());
}

// s( X, [ Y, s1(1) ], W )
TEST(iterator, struct_list_DFS_iterator) {
  Number one(1);
  Variable X("X"), Y("Y"), W("W") ;
  Struct s1(Atom("s1"), {&one});
  List l({&Y, &s1}) ;
  Struct s(Atom("s"), {&X, &l, &W});
  Iterator<Term *> *itStruct = s.createDFSIterator();
  itStruct->first();
  ASSERT_EQ("X", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[Y, s1(1)]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("Y", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("s1(1)", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("W", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_TRUE(itStruct->isDone());
}

// combo1(bigMac(bun, beefPatty, shreddedLettuce, sauce, cheese, [pickleSlice1, pickleSlice2], [onion1, onion2]), coke, [fries1, fires2])
TEST(iterator, combo1_DFS_iterator) {
  Atom bun("bun"), beefPatty("beefPatty"), shreddedLettuce("shreddedLettuce");
  Atom sauce("sauce"), cheese("cheese"), pickleSlice1("pickleSlice1");
  Atom pickleSlice2("pickleSlice2"), onion1("onion1"), onion2("onion2");
  Atom coke("coke"), fries1("fries1"), fires2("fires2");
  List l3({&fries1, &fires2}) ;
  List l1({&pickleSlice1, &pickleSlice2}) ;
  List l2({&onion1, &onion2});
  Struct s2(Atom("bigMac"), {&bun, &beefPatty, &shreddedLettuce, &sauce, &cheese, &l1, &l2});
  Struct s1(Atom("combo1"), {&s2, &coke, &l3});
  Iterator<Term *> *itStruct = s1.createDFSIterator();
  itStruct->first();
  EXPECT_EQ("bigMac(bun, beefPatty, shreddedLettuce, sauce, cheese, [pickleSlice1, pickleSlice2], [onion1, onion2])", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("bun", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("beefPatty", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("shreddedLettuce", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("sauce", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("cheese", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[pickleSlice1, pickleSlice2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("pickleSlice1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("pickleSlice2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[onion1, onion2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("onion1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("onion2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("coke", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[fries1, fires2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("fries1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("fires2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_TRUE(itStruct->isDone());
}

// combo1(bigMac(bun, beefPatty, shreddedLettuce, sauce, cheese, [pickleSlice1, pickleSlice2], [onion1, onion2]), coke, [fries1, fires2])
TEST(iterator, combo1_BFS_iterator) {
  Atom bun("bun"), beefPatty("beefPatty"), shreddedLettuce("shreddedLettuce");
  Atom sauce("sauce"), cheese("cheese"), pickleSlice1("pickleSlice1");
  Atom pickleSlice2("pickleSlice2"), onion1("onion1"), onion2("onion2");
  Atom coke("coke"), fries1("fries1"), fires2("fires2");
  List l3({&fries1, &fires2}), l1({&pickleSlice1, &pickleSlice2}), l2({&onion1, &onion2});
  Struct s2(Atom("bigMac"), {&bun, &beefPatty, &shreddedLettuce, &sauce, &cheese, &l1, &l2});
  Struct s1(Atom("combo1"), {&s2, &coke, &l3});
  Iterator<Term *> *itStruct = s1.createBFSIterator();
  itStruct->first();
  EXPECT_EQ("bigMac(bun, beefPatty, shreddedLettuce, sauce, cheese, [pickleSlice1, pickleSlice2], [onion1, onion2])", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("coke", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[fries1, fires2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("bun", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("beefPatty", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("shreddedLettuce", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("sauce", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("cheese", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[pickleSlice1, pickleSlice2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("[onion1, onion2]", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("fries1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("fires2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("pickleSlice1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("pickleSlice2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("onion1", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_EQ("onion2", itStruct->currentItem()->symbol());
  ASSERT_FALSE(itStruct->isDone());
  itStruct->next();
  ASSERT_TRUE(itStruct->isDone());
}

#endif
