/* 
 * File:   texture.h
 * Author: gilvolpe
 *
 * Created on May 29, 2013, 2:14 PM
 */

#ifndef TEXTURE_H
#define	TEXTURE_H



/*** Counter to keep track of the last loaded texture ***/
extern int num_texture;


/**********************************************************
 *
 * FUNCTION LoadBitmap(char *)
 *
 * This function loads a bitmap file and return the OpenGL reference ID to use that texture
 *
 *********************************************************/

extern int LoadBitmap(char *filename);

typedef struct /**** BMP file info structure ****/ {
    unsigned int biSize; /* Size of info header */
    int biWidth; /* Width of image */
    int biHeight; /* Height of image */
    unsigned short biPlanes; /* Number of color planes */
    unsigned short biBitCount; /* Number of bits per pixel */
    unsigned int biCompression; /* Type of compression to use */
    unsigned int biSizeImage; /* Size of image data */
    int biXPelsPerMeter; /* X pixels per meter */
    int biYPelsPerMeter; /* Y pixels per meter */
    unsigned int biClrUsed; /* Number of colors used */
    unsigned int biClrImportant; /* Number of important colors */
    char *data;
} BITMAPINFOHEADER;

#endif	/* TEXTURE_H */