/* 
 * File:   Objects.h
 * Author: gilvolpe
 *
 * Created on May 25, 2013, 6:36 PM
 */

#ifndef OBJECTS_H
#define	OBJECTS_H

#include "basicInformation.h"

class Objects {
public:
    
    Objects(Point3D point,GLfloat angleUpdate);
    Objects(const Objects& orig);
    
    virtual ~Objects();
  
    void updatePosition();
    
    Point3D getPoint();
    void setPoint(Point3D point);
    
    GLfloat getUpdateAngle();
    GLfloat getAngle();
    void setAngle(GLfloat angle);
        
    void drawObject();
    
    virtual void specificDraw() = 0;
    
private:
       Point3D point;
       GLfloat angle, angleUpdate;
};

#endif	/* OBJECTS_H */

