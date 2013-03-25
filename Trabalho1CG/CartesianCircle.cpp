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
   
    static GLint r = getRadius();
    static GLint x = 0;
    
    GLfloat y = (GLfloat) sqrt(r * r - x * x);
    Point2D point(x, y);
    x++;
    
    return point;
}
