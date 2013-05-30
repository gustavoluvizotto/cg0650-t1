/* 
 * File:   Sphere.h
 * Author: gilvolpe
 *
 * Created on May 28, 2013, 4:18 PM
 */

#ifndef SPHERE_H
#define	SPHERE_H

#include "Objects.h"

class Sphere : public Objects{
public:
    Sphere(Point3D point,GLfloat update);
    virtual ~Sphere();
    
    void specificDraw();
    void updateRotation(bool update){}
private:
};

#endif	/* SPHERE_H */

