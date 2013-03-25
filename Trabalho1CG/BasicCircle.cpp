/* 
 * File:   BasicCircle.cpp
 * Author: gilvolpe
 * 
 * Created on March 25, 2013, 1:45 PM
 */

#include "BasicCircle.h"

BasicCircle::BasicCircle(GLint radius) {
    this->maxRadius = radius;
}

BasicCircle::BasicCircle(const BasicCircle& orig) {
}

BasicCircle::~BasicCircle() {
}

void BasicCircle::writeCircle(Point2D point) {

    GLfloat x = point._x;
    GLfloat y = point._y;

    glBegin(GL_POINTS);

    glVertex2f(x, y);
    glVertex2f(y, x);
    glVertex2f(x, -y);
    glVertex2f(y, -x);
    glVertex2f(-x, y);
    glVertex2f(-y, x);
    glVertex2f(-x, -y);
    glVertex2f(-y, -x);

    glEnd();
}

void BasicCircle::work() {

//    for (GLint i = 0; i <= this->maxRadius; i++) {
        Point2D point;

        do {
            
            point = algorithm();
            writeCircle(point);

        } while (point._y > point._x);
//    }
}

GLint BasicCircle::getRadius() {
    return this->maxRadius;
}