/* 
 * File:   Render.h
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#ifndef RENDER_H
#define	RENDER_H

#include "basicInformation.h"
#include "CartesianCircle.h"
#include "PolarCircle.h"
#include "MidPoint.h"

class Render {
private:
    
    GLint sizeX, sizeY;
    
public: 
    Render(int argc, char **argv);
    Render(const Render& orig);
    virtual ~Render();
    void start();
    static void drawScene();
    static void grid();
    static void vertex();
    static void handleKeyPress(unsigned char key, int x, int y);
    static void drawCircle(GLint value);
    static void timer(GLint unused);
    static void printstring(char *string, Point3D point, GLint color);
};

#endif	/* RENDER_H */

