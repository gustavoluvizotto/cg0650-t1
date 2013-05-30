/* 
 * File:   Sphere.cpp
 * Author: gilvolpe
 * 
 * Created on May 28, 2013, 4:18 PM
 */

#include "Sphere.h"
#include "BasicFramework.h"

Sphere::Sphere(Point3D point, GLfloat update = 0) : Objects(point,update){
}

Sphere::~Sphere() {
}

void Sphere::specificDraw(){
    
    glColor3d(1,1,1);
    glutSolidSphere(RADIUS_SPHERE, SLICES, STACKS);
}

