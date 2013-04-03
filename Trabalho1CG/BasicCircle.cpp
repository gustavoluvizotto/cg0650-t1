/* 
 * File:   BasicCircle.cpp
 * Author: gilvolpe
 * 
 * Created on March 25, 2013, 1:45 PM
 */

#include "BasicCircle.h"
#include "Statistic.h"

BasicCircle::BasicCircle(GLint radius = 0) : x(0) {
    this->radius = radius;
    char *jaca = "";
    stat = new Statistic(jaca);
}

BasicCircle::BasicCircle(GLint radius = 0, char *type = "") : x(0) {
    this->radius = radius;
    stat = new Statistic(type);
}

BasicCircle::BasicCircle(const BasicCircle& orig) {
}

BasicCircle::~BasicCircle() {
}

void BasicCircle::writeCircle(Point2D point) {

    GLfloat x = point._x;
    GLfloat y = point._y;

    setColor();

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

void BasicCircle::writeCircle(Point3D point) {

    GLfloat x = point._x;
    GLfloat y = point._y;
    GLfloat z = point._z;

    setColor();

    glBegin(GL_POINTS);

    switch (point._plane) {
        case 0:
            glVertex3f(x, y, z);
            glVertex3f(y, x, z);
            glVertex3f(x, -y, z);
            glVertex3f(y, -x, z);
            glVertex3f(-x, y, z);
            glVertex3f(-y, x, z);
            glVertex3f(-x, -y, z);
            glVertex3f(-y, -x, z);
            break;
        case 1:
            glVertex3f(x, y, z);
            glVertex3f(x, z, y);
            glVertex3f(x, y, -z);
            glVertex3f(x, z, -y);
            glVertex3f(x, -y, z);
            glVertex3f(x, -z, y);
            glVertex3f(x, -y, -z);
            glVertex3f(x, -z, -y);
            break;
        case 2:
            glVertex3f(x, y, z);
            glVertex3f(z, y, x);
            glVertex3f(x, y, -z);
            glVertex3f(z, y, -x);
            glVertex3f(-x, y, z);
            glVertex3f(-z, y, x);
            glVertex3f(-x, y, -z);
            glVertex3f(-z, y, -x);
            break;
    }
    glEnd();
}

void BasicCircle::work() {

#ifdef _3D_
    Point3D point;
    vector<Point3D> vPoint;
#else    
    Point2D point;
    vector<Point2D> vPoint;
#endif
    stat->setRadius(this->getRadius());

    stat->getTime("old");
    do {
        //stat->startCounter()
#ifdef _3D_
        point = algorithm3D();
#else
        point = algorithm2D();
#endif
        //stat->stopCounter();

        vPoint.push_back(point);

    } while (continous(point));
    stat->getTime("new");

#ifdef _3D_
    vector<Point3D>::iterator it;
#else
    vector<Point2D>::iterator it;
#endif

    for (it = vPoint.begin(); it != vPoint.end(); it++)
        writeCircle(*it);
}

void BasicCircle::initializeRadiusAndX(GLint radius) {
    setRadius(radius);
    setX(0);
    setY(radius);
    setTheta(M_PI);
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

GLint BasicCircle::getY() {
    return this->y;
}

void BasicCircle::setY(GLint y) {
    this->y = y;
}

GLfloat BasicCircle::getTheta() {
    return this->theta;
}

void BasicCircle::setTheta(GLfloat theta) {
    this->theta = theta;
}

bool BasicCircle::continous(Point2D point) {
    return point._y > point._x;
}

bool BasicCircle::continous(Point3D point) {
    switch (point._plane) {
        case 0:
            return point._y > point._x;
        case 1:
            return point._y > point._z;
        case 2:
            return point._z > point._x;
    }
}

void BasicCircle::callShowStatistic(int op) {
    stat->showStatistic();
    stat->plotStatistic(op);
}