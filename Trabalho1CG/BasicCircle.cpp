/* 
 * File:   BasicCircle.cpp
 * Author: gilvolpe
 * 
 * Created on March 25, 2013, 1:45 PM
 */

#include "BasicCircle.h"

BasicCircle::BasicCircle(GLint radius) {
    this->radius = radius;
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

    Point2D point(getRadius(),0);
    
    do {
        point = algorithm();
        writeCircle(point);
    } while (point._y > point._x);

}

void BasicCircle::initializeRadiusAndX(GLint radius) {
    setRadius(radius);
    setX(0);
}

GLint BasicCircle::getRadius() {
    return this->radius;
}

void BasicCircle::setRadius(GLint radius) {
    this->radius = radius;
}

GLint BasicCircle::getX() {
    return this->x;
}

void BasicCircle::setX(GLint x) {
    this->x = x;
}