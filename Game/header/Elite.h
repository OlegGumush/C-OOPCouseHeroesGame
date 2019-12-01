#pragma once
#include "Enemy.h"

class Elite : public Enemy {
public:
	/*
	Constructor
	*/
	Elite(const double powerAmount, const ECharacter characterTypes, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2);
	/*
	Distructor
	*/
	virtual ~Elite();
	/*
	To string
	*/
	string toString() const;

};