#include "Item.h"


/*
Constructor
*/
Item::Item(const size_t x, const size_t y, const EItems type) : type(type)
{
	place = new Point2d(x,y);
}

/*
Distructor
*/
Item::~Item() {
	delete place;
}


/*
getters
*/
const EItems& Item::getType()const {
	return type;
}
Point2d* Item::getPoint() const{
	return place;
}

/*
toString
*/
string Item::toString() const {
	return "(Item:)(Location:(" + to_string(this->place->getX()) + "," + to_string(this->place->getY()) + "))";
}