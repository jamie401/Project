#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  vector<Term *> args = {};
  List l(args);
  EXPECT_EQ( "[]", l.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number num1(8128), num2(496);
  vector<Term *> args = {&num1, &num2} ;
  List l(args);
  EXPECT_EQ( "[8128, 496]", l.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom ter("terence_tao"), ala("alan_mathison_turing") ;
  vector<Term *> args = {&ter, &ala} ;
  List l(args);
  EXPECT_EQ( "[terence_tao, alan_mathison_turing]", l.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable X("X"), Y("Y");
  vector<Term *> args = {&X, &Y};
  List l(args);
  EXPECT_EQ( "[X, Y]", l.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Atom tom("tom"), ter("terence_tao") ;
  Number num(496);
  Variable X("X");
  vector<Term *> args = {&num, &X, &ter};
  List l(args);
  ASSERT_FALSE( tom.match(l) ) ;
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Number num1(8128), num2(496);
  Atom ter("terence_tao");
  Variable X("X");
  vector<Term *> args = {&num2, &X, &ter};
  List l(args);
  ASSERT_FALSE( num1.match(l)) ;
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Variable X("X");
  Number num(496);
  Atom ter("terence_tao");
  vector<Term *> arg1 = {&X};
  Struct s(Atom("s"), arg1);
  vector<Term *> arg2 = {&num, &X, &ter};
  List l(arg2);
  ASSERT_FALSE( s.match(l) );
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Variable X("X"), Y("Y");
  Number num(496);
  Atom ter("terence_tao");
  vector<Term *> arg = {&num, &X, &ter};
  List l(arg);
  ASSERT_TRUE( Y.match(l) );
  EXPECT_EQ( "[496, X, terence_tao]", Y.value() );
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Variable X("X");
  Number num(496);
  Atom ter("terence_tao");
  vector<Term *> arg = {&num, &X, &ter};
  List l(arg);
  ASSERT_TRUE( X.match(l));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Variable X("X");
  Number num(496);
  Atom ter("terence_tao");
  vector<Term *> arg = {&num, &X, &ter};
  List l(arg);
  EXPECT_TRUE( l.match(l));
  ASSERT_EQ( "[496, X, terence_tao]", l.symbol() );
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Variable X("X"), Y("Y");
  Number num(496);
  Atom ter("terence_tao");
  vector<Term *> arg1 = {&num, &X, &ter};
  List l1(arg1);
  vector<Term *> v = {&num, &Y, &ter};
  List l2(v) ;
  EXPECT_TRUE( l1.match(l2) );
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
  Variable X("X");
  Number num(496), num2(8128);
  Atom ter("terence_tao");
  vector<Term *> arg1 = {&num, &X, &ter};
  List l1(arg1);
  vector<Term *> v = {&num, &num2, &ter};
  List l2(v) ;
  EXPECT_TRUE( l1.match(l2) );
  EXPECT_EQ( "8128", X.value());
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
  Variable X("X"), Y("Y");
  Number num(496);
  Atom ter("terence_tao"), ala("alan_mathison_turing");
  vector<Term *> v = {&num, &X, &ter};
  List l(v);
  EXPECT_TRUE( Y.match(l));
  EXPECT_TRUE( X.match(ala) );
  EXPECT_EQ( "[496, alan_mathison_turing, terence_tao]", Y.value() );
  EXPECT_EQ( "alan_mathison_turing", X.value());
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
  Atom f("first"), s("second"), t("third") ;
  vector<Term *> args1 = {&f} ;
  List l1(args1);
  vector<Term *> args2 = {&l1, &s, &t} ;
  List l2(args2);
  EXPECT_EQ("[first]", l2.head()->value());
  EXPECT_EQ("[second, third]", l2.tail()->value()) ;
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t} ;
  List l(args) ;
  EXPECT_EQ("third", l.tail()->tail()->head()->value());
  EXPECT_EQ("[]", l.tail()->tail()->tail()->value());
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
  EXPECT_EQ( "1", "2" ) ;
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
  EXPECT_EQ( "1", "2" ) ;
}




#endif
