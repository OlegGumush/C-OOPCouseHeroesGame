#pragma once
#include "Armor.h"

class BodyArmor : public Armor  {

public:
	/*
	Constructor
	*/
	BodyArmor(const size_t x, const  size_t y, const  double defenceAmount, const EArmor armorKind);
	/*
	Distructor
	*/
	virtual ~BodyArmor();
	/*
	to string
	*/
	virtual string toString() const;
};