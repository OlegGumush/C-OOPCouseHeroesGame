#pragma once
#include "Item.h"
#include "Enums.h"

class Potion : public Item{
public:
	/*
	Constractor
	*/
	Potion(const size_t x , const size_t y, const EPotion type , const double amount);
	/*
	Distractor
	*/
	virtual ~Potion();
	/*
	toString
	*/
	string toString() const;
	/*
	getters
	*/
	const EPotion& getType() const;
	const double& getAmount() const;

private:
	EPotion type;
	double amount;
};

