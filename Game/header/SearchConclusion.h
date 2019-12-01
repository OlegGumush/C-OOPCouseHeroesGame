#pragma once
#include "Point2d.h"

class SearchConclusion {
public:
	/*
	Constractor
	*/
	SearchConclusion(const size_t x, const size_t y, const char symbol);
	/*
	Distractor
	*/
	virtual ~SearchConclusion();
	/*
	to String
	*/
	virtual string toString() const;
	/*
	getters
	*/
	Point2d* const getPoint() const;
	const char& getSymbol() const;

private:
	Point2d* point;
	char symbol;
};