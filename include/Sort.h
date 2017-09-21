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

    for ( std::list<Shape *>::iterator iterX = shapeList->begin(); iterX != shapeList->end() ; iterX++ ) {
        for ( std::list<Shape *>::iterator iterY = shapeList->begin(); iterY != shapeList->end() ; iterY++ ) {
            if ( iterX != iterY && (*iterX)->perimeter() > (*iterY)->perimeter() ) {
                std::swap( *iterX, *iterY ) ;
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
