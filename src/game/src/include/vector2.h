/**
 * @file 	vector2.h
 * @brief	Header file defining vector2 datastruct.
 * @author	VoidScientist
 */

#ifndef VOID_VECTOR2_H
#define VOID_VECTOR2_H

#define VEC_LEFT	createVector2(-1, 0)
#define VEC_RIGHT	createVector2(1, 0)
#define VEC_UP		createVector2(0, -1)
#define VEC_DOWN	createVector2(0, 1)

typedef struct {

	int x;
	int y;

} vector2_t;


vector2_t 	createVector2	(int x, int y);

vector2_t	addVector2		(const vector2_t *vec1, const vector2_t *vec2);

int			cmpVector2		(const vector2_t *vec1, const vector2_t *vec2);


#endif /* VOID_VECTOR2_H */
