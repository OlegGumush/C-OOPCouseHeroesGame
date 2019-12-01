#include "Elite.h"


/*
Constructor
*/
Elite::Elite(const double powerAmount, const  ECharacter characterTypes, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2) :
	Enemy(powerAmount, characterTypes, x1, y1, x2, y2)
{}

/*
Distractor
*/
Elite::~Elite() {}


/*
toString
*/
string Elite::toString() const {
	return "(Elite:)" + Character::toString();
}