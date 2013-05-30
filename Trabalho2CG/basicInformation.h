/* 
 * File:   basicInformation.h
 * Author: gilvolpe
 *
 * Created on March 25, 2013, 2:36 PM
 */

#ifndef BASICINFORMATION_H
#define	BASICINFORMATION_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sys/time.h>

using namespace std;

#define TIME_UPDATE_MS   10
#define SIDE_SIZE 700
#define RANDOM_NUMBER 10


#define RADIUS_SPHERE  250.0f
#define SLICES 300
#define STACKS 300

#define FORWARD_SPACE_SHIP 30.0f
#define BACKWARD_SPACE_SHIP 0.0f

struct Point3D {
    GLfloat _x, _y, _z;

    Point3D(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0) {
        _x = x;
        _y = y;
        _z = z;
    }
};

#endif	/* BASICINFORMATION_H */

