/* 
 * File:   Render.h
 * Authors: Gilberto Volpe Neto
 *          Gustavo Luvizotto Cesar
 * Created on March 22, 2013, 5:10 PM
 */

#ifndef RENDER_H
#define	RENDER_H

#include <GL/glut.h>

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
    static void handleKeyPress(unsigned char key, int x, int y);
};

#endif	/* RENDER_H */

