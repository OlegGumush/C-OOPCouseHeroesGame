#pragma once
#include "Point2d.h"
#include <string>
#include "Enums.h"
using namespace std;

class Item {
public:
	/*
	Constructor
	*/	
	Item(const size_t x, const size_t y , EItems type);
	/*
	Distructor
	*/
	virtual ~Item();
	/*
	to String
	*/
	virtual string toString() const;

	/*
	getters
	*/
	const EItems& getType()const;
	Point2d* getPoint()const;

private:

	Point2d* place;
	EItems type;
};