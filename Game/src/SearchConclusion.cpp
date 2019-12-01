#include "SearchConclusion.h"

/*
Constractor
*/
SearchConclusion::SearchConclusion(const size_t x, const size_t y, const char symbol)
	: point(nullptr) ,symbol(symbol) 
{
	point = new Point2d(x,y);
}

/*
Distractor
*/
SearchConclusion::~SearchConclusion() {
	delete point;
}

/*
getters
*/
Point2d* const SearchConclusion::getPoint() const{
	return this->point;
}
const char& SearchConclusion::getSymbol() const{
	return this->symbol;
}

/*
toString
*/
string SearchConclusion::toString() const {
	return "(SearchConclusion:)(Point2d:)(" + to_string(this->point->getX()) + "," + to_string(this->point->getY()) + ")";
}
