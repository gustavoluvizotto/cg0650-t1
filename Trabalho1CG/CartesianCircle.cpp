/* 
 * File:   CartesianCircle.cpp
 * Author: gilvolpe
 * 
 * Created on March 25, 2013, 3:00 PM
 */

#include "CartesianCircle.h"

CartesianCircle::CartesianCircle(GLint radius) : BasicCircle(radius) {
}

CartesianCircle::~CartesianCircle() {
}

void CartesianCircle::setColor() {
#ifdef _3D_
    glColor3f(0.0f, 1.0f, 1.0f);
#else
    glColor3f(1.0f, 0.0f, 0.0f);
#endif
}

Point2D CartesianCircle::algorithm2D() {

    GLint r = getRadius();
    GLint x = getX();

    GLfloat y = (GLfloat) sqrt(r * r - x * x);
    Point2D point(x, y);

    setX(x + 1);

    return point;
}

Point3D CartesianCircle::algorithm3D() {

    GLint r = getRadius();
    GLint x = getX();

    GLfloat y = (GLfloat) sqrt(r * r - x * x);
    Point3D point(x, y, 0, 0);

    setX(x + 1);

    return point;
}
