#ifndef UTTERM_H
#define UTTERM_H

#include "include/Number.h"
#include "include/Atom.h"

//test Number.value()
TEST (Number,ctor) {
    Number Num("1");
    ASSERT_EQ( "1", Num.value() ) ;
}
//test Number.symbol()
TEST (Number, symbol) {
    Number Num("5");
    ASSERT_EQ( "5", Num.symbol() ) ;
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
    Number Num25("25");
    Atom atm25("25");
    ASSERT_TRUE( Num25.match(atm25) );
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
    Number Num25("25");
    Atom atm0("0");
    ASSERT_FALSE( Num25.match(atm0) ) ;
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {

}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {

}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {

}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {

}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {

}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {

}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
