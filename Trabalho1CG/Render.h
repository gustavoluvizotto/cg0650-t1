/* 
 * File:   Render.h
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#ifndef RENDER_H
#define	RENDER_H

#include "BasicFramework.h"
#include "CartesianCircle.h"
#include "PolarCircle.h"
#include "MidPoint.h"

#define NUM_MAX_INFORMATION 6
#define NUM_MAX_EXECUTION  1000

class RenderCircles : public BasicFramework {
private:

    GLint numberOfExecution;
    GLint value;
    
    GLint angleX, angleY, angleZ;
    GLfloat posMouseX, posMouseY;
    bool end, leftButtonMouse, rightButtonMouse;
    
    SizeRadiusDraw radius2Draw;
    Point3D point[NUM_MAX_INFORMATION];
    char strings[NUM_MAX_INFORMATION][100];

    CartesianCircle cartesian;
    PolarCircle polar;
    MidPoint mid;

    void updateCircleDraw();
    void letters();
    void grid();
    void vertex();


public:

    RenderCircles();

    void display();
    void handleKeyPress(unsigned char key, GLint x, GLint y);
    void drawInterest(GLint value);

    void handleMouse(GLint button, GLint state, GLint x, GLint y);
    void handleMouseMotion(GLint x, GLint y);
    
    void doSomethingInTime();
};

#endif	/* RENDER_H */

