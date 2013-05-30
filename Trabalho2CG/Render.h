/* 
 * File:   Render.h
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#ifndef RENDER_H
#define	RENDER_H

#include "BasicFramework.h"
#include "Objects.h"
#include "Sphere.h"
#include "SpaceShip.h"

#include <vector>
#include <cmath>

#define MAX_ELEM_ON_SCREEN 5;

class Render : public BasicFramework {
private:

    GLint numberOfExecution;
    GLint value;
    
    GLint angleX, angleY, angleZ;
    GLfloat posMouseX, posMouseY;
    bool end, leftButtonMouse, rightButtonMouse;
    SpaceShip *space;
    
    std::vector<Objects*> listOfElements;
    
public:

    Render();

    void display();
    void handleKeyPress(unsigned char key, GLint x, GLint y);
    void handleKeyPressNumber(int key, GLint x, GLint y);
    void drawInterest();

    void handleMouse(GLint button, GLint state, GLint x, GLint y);
    void handleMouseMotion(GLint x, GLint y);
    
    void doSomethingInTime();
    
    void setSpaceShip();
};

#endif	/* RENDER_H */

