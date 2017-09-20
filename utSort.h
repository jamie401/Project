#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
    Rectangle r1( 0, 0, 1, 1 ) ;
    Circle c1( 0, 0, 1 ) ;
    Triangle t1( ( 0, 0), ( 1, 1), ( 1, 0) ) ;

    std::list<Shape *> shapeList ;
    shapeList.push_back (&r1) ;
    shapeList.push_back (&c1) ;
    shapeList.push_back (&t1) ;
    std::sortByIncreasingPerimeter (shapeList);
    ASSERT_NEAR(3.1415926, shapeListd.back() -> perimeter(), epsilon ); // compare the address
}

TEST (Sort, sortByDecreasingPerimeter) {
    Rectangle r2(0, 0, 2, 2) ;
    Circle c2( 0, 0, 2 ) ;
    Triangle t2( ( 0, 0), ( 3, 0), ( 3, 4) ) ;

    std::list<Shape *> shapeList2 ;
    shapeList2.push_back (&r2) ;
    shapeList2.push_back (&c2) ;
    shapeList2.push_back (&t2) ;
    std::sortByDecreasingPerimeter (shapeList2);
    ASSERT_NEAR(12.5663704, shapeListd2.front() -> perimeter(), epsilon );
}

TEST (Sort, sortByIncreasingArea) {
    Rectangle r3(0, 0, 2, 2) ;
    Circle c3( 0, 0, 3 ) ;
    Triangle t3( ( 0, 0), ( 0, 5), ( 12, 5) ) ;

    std::list<Shape *> shapeList3 ;
    shapeList3.push_back (&r3) ;
    shapeList3.push_back (&c3) ;
    shapeList3.push_back (&t3) ;
    std::sortByIncreasingArea (shapeList3);
    ASSERT_NEAR(30, shapeListd3.back() -> area(), epsilon );
}

TEST (Sort, sortByDecreasingArea) {
    Rectangle r4(0, 0, 2, 2) ;
    Circle c4( 0, 0, 4 ) ;
    Triangle t4( ( 0, 0), ( 0, 6), ( 8, 6) ) ;

    std::list<Shape *> shapeList4 ;
    shapeList4.push_back (&r4) ;
    shapeList4.push_back (&c4) ;
    shapeList4.push_back (&t4) ;
    std::sortByDecreasingArea (shapeList4);
    ASSERT_NEAR(4, shapeListd4.back() -> area(), epsilon );
}

TEST (Sort, sortByIncreasingCompactness) {
    Rectangle r5( 0, 0, 2, 2) ;
    Circle c5( 0, 0, 5 ) ;
    Triangle t5( ( 0, 0), ( 7, 0), ( 7, 24) ) ;

    std::list<Shape *> shapeList5 ;
    shapeList5.push_back (&r5) ;
    shapeList5.push_back (&c5) ;
    shapeList5.push_back (&t5) ;
    std::sortByIncreasingCompactness (shapeList5);
    ASSERT_NEAR(2.5, shapeListd5.back() -> perimeter(), epsilon );
}

#endif
