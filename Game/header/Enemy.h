#pragma once
#include "Character.h"

class Enemy : public Character {
public:
	/*
	Constructor
	*/
	Enemy(const double powerAmount, const ECharacter characterTypes, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2);
	/*
	Distructor
	*/
	virtual ~Enemy();
	/*
	get character(hero) and attack him
	*/
	virtual void attack(Character* character) ;
	/*
	Constructor
	*/
	string toString() const;
};