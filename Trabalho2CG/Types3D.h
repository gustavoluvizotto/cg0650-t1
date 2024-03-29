/* 
 * File:   Types3D.h
 * Author: gilvolpe
 *
 * Created on May 29, 2013, 3:42 PM
 */

#ifndef TYPES3D_H
#define	TYPES3D_H

/**********************************************************
 *
 * TYPES DECLARATION
 *
 *********************************************************/

#define MAX_VERTICES 8000 // Max number of vertices (for each object)
#define MAX_POLYGONS 8000 // Max number of polygons (for each object)

// Our vertex type

typedef struct {
    float x, y, z;
} vertex_type;

// The polygon (triangle), 3 numbers that aim 3 vertices

typedef struct {
    int a, b, c;
} polygon_type;

// The mapcoord type, 2 texture coordinates for each vertex

typedef struct {
    float u, v;
} mapcoord_type;

// The object type

typedef struct {
    char name[20];

    int vertices_qty;
    int polygons_qty;

    vertex_type vertex[MAX_VERTICES];
    polygon_type polygon[MAX_POLYGONS];
    mapcoord_type mapcoord[MAX_VERTICES];
    int id_texture;
    
} obj_type, *obj_type_ptr;

#endif	/* TYPES3D_H */

