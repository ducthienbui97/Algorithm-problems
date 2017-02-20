#ifndef __CRECLIB_H
#define __CRECLIB_H

/***********************
 * Public declarations *
 * known by contestant *
 ***********************/

typedef enum __direction {vertical, horizontal} direction;

int dimension_x();
int dimension_y();
void cut(direction, int);

#endif
