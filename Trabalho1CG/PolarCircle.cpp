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

void PolarCircle::setColor(){
#ifdef _3D_
    glColor3f(1.0f, 1.0f, 0.0f);
#else
    glColor3f(0.0f, 1.0f, 0.0f);
#endif
}

Point2D PolarCircle::algorithm2D() {
   
    GLint r = getRadius();
    GLfloat theta = getTheta();
        
    GLfloat y = (GLfloat) (r*sin(theta));
    GLfloat x = (GLfloat) (r*cos(theta));
    
    Point2D point(x, y);
    
    theta -= exp10(-3);
    setTheta(theta);
    
    return point;
}

Point3D PolarCircle::algorithm3D() {
   
    GLint r = getRadius();
    GLfloat theta = getTheta();
        
    GLfloat y = (GLfloat) (r*sin(theta));
    GLfloat z = (GLfloat) (r*cos(theta));
    
    Point3D point(0,y, z, 1);
    
    theta -= exp10(-3);
    setTheta(theta);
    
    return point;
}
