/**
 * Please DO NOT modify this file.
 * It contains interface part of the library, and it HAS TO 
 * be compatible with declarations in the task description.
 */
#ifndef __CRECLIB_H
#define __CRECLIB_H

typedef enum __direction {vertical, horizontal} direction;

int dimension_x();
int dimension_y();
void cut(direction, int);

#endif
