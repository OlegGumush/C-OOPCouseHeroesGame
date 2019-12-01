#pragma once
#include <string>
using namespace std;

class Point2d {
public :
	/*
	Constructor
	*/
	Point2d(const size_t x, const size_t y);
	/*
	Distructor
	*/
	virtual ~Point2d();
	/*
	to String
	*/
	virtual string toString() const;
	/*
	getters
	*/
	const size_t& getX() const;
	const size_t& getY() const;
	/*
	setters
	*/
	void setX(size_t x);
	void setY(size_t y);

	double distance(const size_t& x , const size_t& y);
private:
	size_t x;
	size_t y;
};