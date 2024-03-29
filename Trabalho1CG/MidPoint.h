/* 
 * File:   MidPoint.h
 * Authors: Gustavo Luvizotto Cesar
 *          Gilberto Volpe Neto
 *
 * Created on March 23, 2013, 3:44 PM
 */

#ifndef MIDPOINT_H
#define	MIDPOINT_H

#include "BasicCircle.h"

class MidPoint : public BasicCircle {
private:
    GLint increment;
   
public:
    MidPoint(GLint radius = 0);
    virtual ~MidPoint();
    
    GLint getIncrement();
    void setIncrement(GLint increment);
   
    Point2D algorithm2D();
    Point3D algorithm3D();
    void setColor();
};

#endif	/* MIDPOINT_H */

