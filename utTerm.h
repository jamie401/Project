#ifndef UTTERM_H
#define UTTERM_H

#include "number.h"
#include "atom.h"
#include "variable.h"

//test Number.value()
TEST (Number,ctor) {
    Number Num(1);
    ASSERT_EQ( "1", Num.value() ) ;
}
//test Number.symbol()
TEST (Number, symbol) {
    Number Num(5);
    ASSERT_EQ( "5", Num.symbol() ) ;
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number Num25(25);
    ASSERT_EQ( "25", Num25.value() );
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number Num25(25);
    ASSERT_NE( "0", Num25.value() ) ;
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
    Number Num25(25);
    Atom atom("tom");
    ASSERT_FALSE( Num25.match(atom) ) ;
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
    Number Num25(25);
    Variable X("X");
    ASSERT_TRUE( Num25.match(X) ) ;
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
    Atom tom("tom");
    ASSERT_NE( tom.symbol(), "25" ) ;
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
    Atom tom("tom");
    Variable X("X") ;
    ASSERT_TRUE( tom.match(X) ) ;
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
    Atom tom("tom");
    Variable X("X") ;
    ASSERT_TRUE( X.match(tom) ) ;
    ASSERT_TRUE( tom.match(X) ) ;
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
    Atom tom("tom") ;
    Atom jerry("jerry") ;
    Variable X("X") ;
    ASSERT_TRUE( X.match(jerry) ) ;
    ASSERT_FALSE( X.match(tom) ) ;
}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
    Variable X("X") ;
    Number Num5(5) ;
    ASSERT_TRUE( X.match(Num5) ) ;
}

// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
    Variable X("X") ;
    Number Num25(25) ;
    Number Num100(100) ;
    ASSERT_TRUE( X.match(Num25) ) ;
    ASSERT_FALSE( X.match(Num100) ) ;
}

// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
    Variable X("X") ;
    Atom tom("tom") ;
    Number num25(25) ;
    ASSERT_TRUE( X.match(tom) ) ;
    ASSERT_FALSE( X.match(num25) ) ;
}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
    Variable X("X") ;
    Atom tom("tom") ;
    Number num25(25) ;
    ASSERT_TRUE( tom.match(X) );
    ASSERT_FALSE( num25.match(X) );
}
//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){
    Variable X("X") ;
    Atom tom("tom") ;
    ASSERT_TRUE( X.match(tom) ) ;
    ASSERT_TRUE( X.match(tom) ) ;
}
#endif
