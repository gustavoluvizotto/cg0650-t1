/* 
 * File:   MidPoint.cpp
 * Authors: Gustavo Luvizotto Cesar
 *          Gilberto Volpe Neto
 * Created on March 23, 2013, 3:44 PM
 */

#include "MidPoint.h"

MidPoint::MidPoint(GLint radius) : BasicCircle(radius) {
    this->increment = 1 - radius;
    setY(radius);
    setX(0);
}

MidPoint::~MidPoint() {
}

void MidPoint::setColor() {
#ifdef _3D_
    glColor3f(1.0f, 0.0f, 1.0f);
#else
    glColor3f(1.0f, 1.0f, 1.0f);
#endif
}

Point2D MidPoint::algorithm2D() {
    GLint x = getX();
    GLint y = getY();

    if (this->increment < 0) {
        /* Selecione E */
        setIncrement(this->increment + 2 * x + 3);
    } else {
        /* Selecione SE */
        setIncrement(this->increment + 2 * (x - y) + 5);
        y--;
    }
    x++;

    setX(x);
    setY(y);

    Point2D point(x, y);
    return point;
}

Point3D MidPoint::algorithm3D() {
    GLint x = getX();
    GLint z = getY();

    if (this->increment < 0) {
        /* Selecione E */
        setIncrement(this->increment + 2 * x + 3);
    } else {
        /* Selecione SE */
        setIncrement(this->increment + 2 * (x - z) + 5);
        z--;
    }
    x++;

    setX(x);
    setY(z);

    Point3D point(x, 0, z, 2);
    return point;
}

GLint MidPoint::getIncrement() {
    return this->increment;
}

void MidPoint::setIncrement(GLint increment) {
    this->increment = increment;
}
