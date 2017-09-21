#include <list>
#include "Shapes.h"
#include <list>

class Sort {

  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList);

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList);

  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);
  // Compactness = area/perimeter
};

//template <class T> bool compare_size ( const double comX, const double comY )


void Sort::sortByIncreasingPerimeter( std::list<Shape *> * shapeList) {

    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
            if (  (*iterX)->perimeter() < (*iterY)->perimeter() ) {
                std::swap( *iterX, *iterY ) ;
            }
        }
    }
}

void Sort::sortByDecreasingPerimeter( std::list<Shape *> * shapeList) {

//    shapeList->sort( compare_size ) ;

//    std::sort( shapeList->begin(), shapeList->end(), (*shapeList->begin())->perimeter() ) ;

    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
                std::cout << "----1XXX:" << (*iterX)->perimeter() << "\n" ;
                std::cout << "----1YYY:" << (*iterY)->perimeter() << "\n" ;
            if ( (*iterX)->perimeter() > (*iterY)->perimeter() ) {
                std::cout << "----2XX:" << (*iterX)->perimeter() << "\n" ;
                std::cout << "----2YY:" << (*iterY)->perimeter() << "\n" ;
                std::swap( *iterX, *iterY ) ;
                std::cout << "----3X:" << (*iterX)->perimeter() << "\n" ;
                std::cout << "----3Y:" << (*iterY)->perimeter() << "\n" ;
            }

        }
    }
}

void Sort::sortByIncreasingArea( std::list<Shape *> * shapeList) {

    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
            if (  (*iterX)->area() < (*iterY)->area() ) {
                std::swap( *iterX, *iterY ) ;
            }
        }
    }

//    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
//        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
 //           if ( iterY == shapeList->back() || iterX == shapeList->back() ) {
 //               if ( iterX != iterY && (*iterX)->area() < (*iterY)->area() )
 //                   std::swap( iterX, iterY ) ;
//                break ;
//            }
//            if ( iterX != iterY && (*iterX)->area() < (*iterY)->area() ) {
//                std::swap( iterX, iterY ) ;
//            }
//        }
//    }
}

void Sort::sortByDecreasingArea( std::list<Shape *> * shapeList) {

    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
            if ( iterX != iterY && (*iterX)->area() > (*iterY)->area() ) {
                std::swap( *iterX, *iterY ) ;
            }
        }
    }
}

void Sort::sortByIncreasingCompactness( std::list<Shape *> * shapeList) {

    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
            if ( iterX != iterY && (( (*iterX)->area() / (*iterX)->perimeter() ) < ( (*iterY)->area() / (*iterY)->perimeter()) ) ) {
                std::swap( *iterX, *iterY ) ;
            }
        }
    }
}
