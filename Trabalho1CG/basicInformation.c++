#include "basicInformation.h"

GLfloat scale(GLint number) {
    return (GLfloat) number / SCALE;
}

GLint unscale(GLfloat number) {
    return (GLint) number * SCALE;
}