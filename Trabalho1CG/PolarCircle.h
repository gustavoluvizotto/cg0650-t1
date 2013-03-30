/* 
 * File:   PolarCircle.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 3:01 PM
 */

#ifndef POLARCIRCLE_H
#define	POLARCIRCLE_H

#include "BasicCircle.h"

class PolarCircle : public BasicCircle{
public:
    PolarCircle(GLint radius = 0);
    virtual ~PolarCircle();
    
    Point2D algorithm2D();
    Point3D algorithm3D();
    void setColor();
private:

};

#endif	/* POLARCIRCLE_H */

