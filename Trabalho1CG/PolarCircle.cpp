/* 
 * File:   PolarCircle.cpp
 * Author: gilvolpe
 * 
 * Created on March 25, 2013, 3:01 PM
 */

#include "PolarCircle.h"

PolarCircle::PolarCircle(GLint radius) : BasicCircle(radius) {
    
    GLfloat theta = M_PI;
    setTheta(theta);
}

PolarCircle::~PolarCircle() {
}

Point2D PolarCircle::algorithm() {
   
    GLint r = getRadius();
    GLfloat theta = getTheta();
        
    GLfloat y = (GLfloat) (r*sin(theta));
    GLfloat x = (GLfloat) (r*cos(theta));
    
    Point2D point(x, y);
    
    theta -= exp10(-3);
    setTheta(theta);
    
    return point;
}
