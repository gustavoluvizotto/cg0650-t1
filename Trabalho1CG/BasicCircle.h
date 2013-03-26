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

    virtual Point2D algorithm2D(void) = 0;
    virtual Point3D algorithm3D(void) = 0;
    virtual void setColor(void) =0;
    void writeCircle(Point2D point);
    void writeCircle(Point3D point);

    GLint getRadius();
    void setRadius(GLint radius);

    GLint getX();
    void setX(GLint x);

    GLint getY();
    void setY(GLint y);

    GLfloat getTheta();
    void setTheta(GLfloat theta);

    void initializeRadiusAndX(GLint radius);

    void work();

private:
    GLint radius, x, y;
    GLfloat theta;
    
    bool continous(Point2D point);
    bool continous(Point3D point);
};

#endif	/* BASICCIRCLE_H */

