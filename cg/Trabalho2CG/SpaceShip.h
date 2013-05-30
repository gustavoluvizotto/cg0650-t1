/* 
 * File:   SpaceShip.h
 * Author: gilvolpe
 *
 * Created on May 29, 2013, 2:25 PM
 */

#ifndef SPACESHIP_H
#define	SPACESHIP_H

#include "Objects.h"
#include "texture.h"
#include "Types3D.h"
#include "3dsloader.h"

class SpaceShip : public Objects {
public:

    SpaceShip(Point3D point, GLfloat angleUpdate);

    virtual ~SpaceShip();

    void specificDraw();
    void updatePosition(bool forward);
    void updateRotationAroundDirector(bool forward);
    void updateRotationAroundVersor(bool forward);
    
    void controlOfSpaceRotation(int key, int x, int y);
    void controlOfSpaceTranslation(unsigned char key, int x, int y);
private:

    obj_type spaceShip;
    GLfloat moveForward;
    GLfloat moveBackward;
    GLfloat angleX, angleY, angleZ;

    Point3D direction;
    Point3D versorAzimutal;
    Point3D versorElevation;

    void rotateShip();
    void translateShip();
    void updateDirection();
    void updateVersor();
    
    GLfloat error;
};

#endif	/* SPACESHIP_H */

