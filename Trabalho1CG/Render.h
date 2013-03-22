/* 
 * File:   Render.h
 * Author: gilvolpe
 *
 * Created on March 22, 2013, 5:10 PM
 */

#ifndef RENDER_H
#define	RENDER_H

#include <GL/glut.h>

class Render {
public:
    Render(int argc, char **argv);
    Render(const Render& orig);
    virtual ~Render();
    
    void start(){
        glutMainLoop();
    }

    static void drawScene() {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glBegin(GL_LINES);
            glColor3f(1, 0, 0);

            glVertex2f(0, 0);

            glVertex2f(1, 1);
//            glVertex2f(0.125, 0.100);
//
//            glVertex2f(0.150, 0.125);
//            glVertex2f(0.100, 0.125);
        glEnd();
        
        glutSwapBuffers();
    }

    static void handleKeyPress(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                exit(0);
                break;
        }
    }


private:
    GLint sizeX, sizeY;

    
    
};

#endif	/* RENDER_H */

