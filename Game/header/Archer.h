#pragma once
#include "Hero.h"
#include "Enums.h" 

class Archer : public Hero {
public:
	Archer(const double power, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2, const  ECharacter name, const  EGender gender);
	virtual ~Archer();

	virtual bool use(Item* const item);
	virtual string toString() const;
};
