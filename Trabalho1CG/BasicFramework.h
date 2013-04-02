/* 
 * File:   BasicFramework.h
 * Author: gilvolpe
 *
 * Created on March 29, 2013, 6:28 PM
 */

#ifndef BASICFRAMEWORK_H
#define	BASICFRAMEWORK_H

#include "basicInformation.h"

class BasicFramework {
protected:
    static BasicFramework *instance;

private:
    void setColor(GLint color);
    GLint sizeX, sizeY;

public:

    BasicFramework();
    virtual ~BasicFramework();

    static void setInstance(BasicFramework *basicFramework);
    static void handleKeyPressWrapper(unsigned char key, int x, int y);
    static void handleMouseWrapper(GLint state,GLint button,GLint x,GLint y);
    static void handleMouseMotionWrapper(GLint x,GLint y);
    static void displayWrapper();
    static void timerWrapper(GLint unused);
    static void doSomethingInTimerWrapper();

    virtual void display() = 0;
    virtual void handleKeyPress(unsigned char key, GLint x, GLint y) = 0;
    virtual void handleMouse(GLint button,GLint state,GLint x,GLint y) = 0;
    virtual void handleMouseMotion(GLint x,GLint y) = 0;
    virtual void drawInterest(GLint value) = 0;
    virtual void doSomethingInTime() = 0;
    
    void timer(GLint unused);
    void start(int argc, char *argv[]);
    void printstring(char *string, Point3D point, GLint color);
};

#endif	/* BASICFRAMEWORK_H */

