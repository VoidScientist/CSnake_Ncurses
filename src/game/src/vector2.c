/**
 * @file   vector2.c
 * @brief  Implementation file defining vector2 datastruct.
 * @author VoidScientist
 */

#include "vector2.h"


vector2_t createVector2(int x, int y) {

	vector2_t result;
	result.x = x;
	result.y = y;

	return result;

}


vector2_t addVector2(const vector2_t *vec1, const vector2_t *vec2) {

	return createVector2(vec1->x + vec2->x, vec1->y + vec2->y);

}


int cmpVector2(const vector2_t *vec1, const vector2_t *vec2) {
	
	return (vec1->x == vec2->x) && (vec1->y == vec2->y);

}
