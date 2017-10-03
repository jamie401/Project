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
TEST (Variable, matchSuccessToNumber) {
    Variable X("X") ;
    Number Num5(5) ;
    ASSERT_TRUE( X.match(Num5) ) ;
}

// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){

}
#endif
