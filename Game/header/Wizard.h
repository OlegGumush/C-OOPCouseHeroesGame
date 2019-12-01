#pragma once
#include "Hero.h"
#include "Enums.h"

class Wizard : public Hero {
	
public:
	/*
	Constractor
	*/
	Wizard(const double power, const size_t x1, const size_t y1, const size_t x2, const size_t y2, const ECharacter name, const EGender gender);
	/*
	Distractor
	*/
	virtual ~Wizard();
	/*
	to String
	*/
	string toString() const;
	/*
	get some item and need to decide if itake him or not
	*/
	virtual bool use(Item* const item);

	
};


