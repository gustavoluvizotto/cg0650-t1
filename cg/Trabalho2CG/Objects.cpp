/* 
 * File:   Objects.cpp
 * Author: gilvolpe
 * 
 * Created on May 25, 2013, 6:36 PM
 */

#include <vector>

#include "Objects.h"

Objects::Objects(Point3D point,GLfloat angleUpdate) {
    this->point = point;
    this->angleUpdate = angleUpdate;
}

Objects::Objects(const Objects& orig) {
}

Objects::~Objects() {
}

void Objects::drawObject(){
    
    glPushMatrix();
        
    specificDraw();
    
    glPopMatrix();
}

Point3D Objects::getPoint(){
     return this->point;   
}

void Objects::setPoint(Point3D point){
    this->point = point;
}

GLfloat Objects::getAngle(){
     return this->angle;   
}

void Objects::setAngle(GLfloat angle){
    this->angle = angle;
}

GLfloat Objects::getUpdateAngle(){
    return this->angleUpdate;
}