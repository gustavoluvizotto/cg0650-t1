/* 
 * File:   BasicCircle.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 1:45 PM
 */

#ifndef BASICCIRCLE_H
#define	BASICCIRCLE_H

#include <basicInformation.h>

struct Point2D {
    GLfloat _x, _y;

    Point2D(GLint x = 0, GLint y = 0) {
        _x = scale(x);
        _y = scale(y);
    }
};

typedef struct Point2D Point2D;

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

    void initializeRadiusAndX(GLint radius);

    void work();

private:
    GLint radius, x;
};

#endif	/* BASICCIRCLE_H */

