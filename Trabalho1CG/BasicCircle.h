/* 
 * File:   BasicCircle.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 1:45 PM
 */

#ifndef BASICCIRCLE_H
#define	BASICCIRCLE_H

#include "basicInformation.h"

class BasicCircle {
public:
    BasicCircle(GLint radius);
    BasicCircle(const BasicCircle& orig);
    virtual ~BasicCircle();

    virtual Point2D algorithm(void) = 0;
    void writeCircle(Point2D point);

    GLint getRadius();
    void setRadius(GLint radius);

    GLint getX();
    void setX(GLint x);

    GLfloat getTheta();
    void setTheta(GLfloat theta);

    void initializeRadiusAndX(GLint radius);

    void work();

private:
    GLint radius, x;
    GLfloat theta;
};

#endif	/* BASICCIRCLE_H */

