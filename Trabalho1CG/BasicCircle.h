/* 
 * File:   BasicCircle.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 1:45 PM
 */

#ifndef BASICCIRCLE_H
#define	BASICCIRCLE_H

#include <basicInformation.h>
#include <Render.h>

struct Point2D {
    GLfloat _x, _y;

    
    Point2D(GLint x=0, GLint y=0) {
        _x = Render::scale(x);
        _y = Render::scale(y);
    }
};

typedef struct Point2D Point2D;

class BasicCircle {
public:
    BasicCircle(GLint radius);
    BasicCircle(const BasicCircle& orig);
    virtual ~BasicCircle();

    virtual Point2D algorithm(void)=0;
    void writeCircle(Point2D point);

    GLint getRadius();

    void work();

private:
    GLint maxRadius;
};

#endif	/* BASICCIRCLE_H */

