/* 
 * File:   CartesianCircle.cpp
 * Author: gilvolpe
 * 
 * Created on March 25, 2013, 3:00 PM
 */

#include "CartesianCircle.h"

CartesianCircle::CartesianCircle(GLint radius): BasicCircle(radius) {
}

CartesianCircle::~CartesianCircle() {
}

Point2D CartesianCircle::algorithm() {
   
    GLint r = getRadius();
    GLint x = getX();
        
    GLfloat y = (GLfloat) sqrt(r * r - x * x);
    Point2D point(x, y);
    
    setX(x+1);

    return point;
}
