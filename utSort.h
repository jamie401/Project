#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

const double epsilon = 0.000001 ;

//vertex v1 = (0, 0) ;
//vertex v2 = (1, 0);
//vertex v3 = (1, 1);

TEST (Sort, sortByIncreasingPerimeter) {
    Rectangle r1( 0, 0, 1, 1 ) ;
    Rectangle t1( 0, 0, 2, 2 ) ;
    Rectangle c1( 0, 0, 3, 3 ) ;
//    Circle c1( 0, 0, 1 ) ;
//    Triangle( v1, v2, v3 ) ;

    std::list<Shape *> shapeList ;
    shapeList.push_back (&r1) ;
    shapeList.push_back (&c1) ;
    shapeList.push_back (&t1) ;
    Sort sortQ1 ;
    sortQ1.sortByIncreasingPerimeter (&shapeList);
//    std::cout << "-----shapeList.end:" << shapeList.back() -> perimeter() << "\n" ;
//    std::cout << "-----shapeList.front:" << shapeList.front() -> perimeter() << "\n" ;
    ASSERT_NEAR(12, shapeList.back() -> perimeter(), epsilon ); // compare the address
}

TEST (Sort, sortByDecreasingPerimeter) {
    Rectangle r2( 0, 0, 2, 2) ;
    Rectangle t2( 0, 0, 3, 3 ) ;
    Rectangle c2( 0, 0, 4, 4 ) ;
//    Circle c2( 0, 0, 6 ) ;
//    Triangle t2( ( 0, 0), ( 3, 0), ( 3, 4) ) ;

    std::list<Shape *> shapeList2 ;
    shapeList2.push_back (&r2 ) ;
    shapeList2.push_back (&t2) ;
    shapeList2.push_back (&c2) ;
    Sort sortQ2 ;
    sortQ2.sortByDecreasingPerimeter (&shapeList2);
//    std::cout << "-----shapeList.end:" << shapeList2.back() -> perimeter() << "\n" ;
//    std::cout << "-----shapeList.front:" << shapeList2.front() -> perimeter() << "\n" ;
    ASSERT_NEAR(16, shapeList2.back() -> perimeter(), epsilon );
}

TEST (Sort, sortByIncreasingArea) {
    Rectangle r3( 0, 0, 2, 2 ) ;
    Rectangle t3( 0, 0, 4, 4 ) ;
    Rectangle c3( 0, 0, 6, 6 ) ;
//    Circle c3( 0, 0, 3 ) ;
//    Triangle t3( ( 0, 0), ( 0, 5), ( 12, 5) ) ;

    std::list<Shape *> shapeList3 ;
    shapeList3.push_back (&r3) ;
    shapeList3.push_back (&c3) ;
    shapeList3.push_back (&t3) ;
    Sort sortQ3 ;
    sortQ3.sortByIncreasingArea (&shapeList3);
    ASSERT_NEAR(36, shapeList3.back() -> area(), epsilon );
}

TEST (Sort, sortByDecreasingArea) {
    Rectangle r4( 0, 0, 2, 2 ) ;
    Rectangle t4( 0, 0, 5, 5 ) ;
    Rectangle c4( 0, 0, 4, 4 ) ;
//    Circle c4( 0, 0, 4 ) ;
//    Triangle t4( ( 0, 0), ( 0, 6), ( 8, 6) ) ;

    std::list<Shape *> shapeList4 ;
    shapeList4.push_back (&r4) ;
    shapeList4.push_back (&c4) ;
    shapeList4.push_back (&t4) ;
    Sort sortQ4 ;
    sortQ4.sortByDecreasingArea (&shapeList4);
    ASSERT_NEAR(4, shapeList4.back() -> area(), epsilon );
}

TEST (Sort, sortByIncreasingCompactness) {
    Rectangle r5( 0, 0, 7, 7 ) ;
    Rectangle t5( 0, 0, 6, 6 ) ;
    Rectangle c5( 0, 0, 5, 5 ) ;
//    Circle c5( 0, 0, 5 ) ;
//    Triangle t5( ( 0, 0), ( 7, 0), ( 7, 24) ) ;

    std::list<Shape *> shapeList5 ;
    shapeList5.push_back (&r5) ;
    shapeList5.push_back (&c5) ;
    shapeList5.push_back (&t5) ;
    Sort sortQ5 ;
    sortQ5.sortByIncreasingCompactness (&shapeList5);
    ASSERT_NEAR(1.25, ( shapeList5.front() -> area() / shapeList5.front() -> perimeter() ), epsilon );
}

#endif
