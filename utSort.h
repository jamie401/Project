#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
    Rectangle r1( 1, 1, 1, 1 ) ;
    Circle c1( 1, 1, 1 ) ;
    Triangle t1( ( 0, 0), ( 1, 1), ( 1, 0) ) ;

    std::list<Shape *> * shapeList ;
    shapeList.push_front (&r1) ;
    shapeList.push_front (&c1) ;
    shapeList.push_front (&t1) ;
    //std::vector<Shape * > Shapes ;
    //Shapes.push_back (&cir0);
    //Shapes.push_back (&square);
    //Shapes.push_back (&cir1);
    std::sort (shapeList.begin(),shapeList.end(),areaGreater);
    ASSERT_EQ(&cir1, Shapes[0]);  // compare the address
    ASSERT_EQ(&cir0, Shapes[1]);
    ASSERT_EQ(&square, Shapes[2]);
}

TEST (Sort, sortByDecreasingPerimeter) {
    Rectangle r2(1, 1, 2, 2) ;
    Circle c2( 1, 1, 2 ) ;
    Triangle t2( ( 0, 0), ( 3, 0), ( 3, 4) ) ;
}

TEST (Sort, sortByIncreasingArea) {
    Rectangle r3(1, 1, 2, 2) ;
    Circle c3( 1, 1, 3 ) ;
    Triangle t3( ( 0, 0), ( 0, 5), ( 12, 5) ) ;
}

TEST (Sort, sortByDecreasingArea) {
    Rectangle r4(1, 1, 2, 2) ;
    Circle c4( 1, 1, 4 ) ;
    Triangle t4( ( 0, 0), ( 0, 6), ( 8, 6) ) ;

}

TEST (Sort, sortByIncreasingCompactness) {
    Rectangle r5(1, 1, 2, 2) ;
    Circle c5( 1, 1, 5 ) ;
    Triangle t5( ( 0, 0), ( 7, 0), ( 7, 24) ) ;
}

#endif
