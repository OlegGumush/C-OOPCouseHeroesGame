#include "Point2d.h"
#include <cmath>
#include <iostream>
/*
Constructor
*/
Point2d::Point2d(const size_t x, const size_t y)
	:x(x),y(y)
{}

/*
Distructor
*/
Point2d::~Point2d(){
}

/*
getters
*/
const size_t& Point2d::getX() const{
	return x;
}
const size_t& Point2d::getY() const{
	return y;
}

/*
setters
*/
void Point2d::setX(size_t x) {
	this->x = x;
}
void Point2d::setY(size_t y) {
	this->y = y;

}

/*
toString
*/
string Point2d::toString() const {
	return "(Point2d:)("+ to_string(this->x)+  "," + to_string(this->y) + ")";
}

double Point2d::distance(const size_t& x , const size_t& y){
	
	double _x = ((double)this->x) - ((double)x);
	double _y = ((double)this->y) - ((double)y);

	return sqrt(_x*_x + _y*_y);
}
