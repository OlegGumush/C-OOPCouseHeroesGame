#pragma once

#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>

class Point2d;
class Item;
class Character;
class Console;
class Factory;

using namespace std;

class Console {
public:
	/*
	Constructor
	*/
	Console();
	/*
	Distructor
	*/
	~Console();
	/*
	A function that accepts a matrix and two data structures. And fills the matrix
	*/
	void fillData(const vector<Item*>& items,unordered_map<Character*, Point2d*>& chCaracters, char ** const world, const size_t& x, const size_t& y) const ;
	/*
	The function prints the matrix.
	*/
	void print(char ** const world, const size_t& x, const size_t& y) const;
	/*
	Function gets a item and returns the character that represents him.
	return '!' if is not suitable for anything. ERROR.
	*/
	char getTypeItem(Item* const item) const ;
	/*
	Function gets a character and returns the character that represents him.
	return '!' if is not suitable for anything. ERROR.
	*/
	char getTypeCharacter(Character* const ch) const ;
	/*
	The function receives a point and data structures.
	Returns a char/symbol if one object should be at this point.
	Returns a '.' if nothing found.
	*/
	char getSymbol(const size_t& i, const size_t& j, const vector<Item*>& items,  unordered_map<Character*, Point2d*>& characters) const ;
	/*
	print all characters to the screen
	*/
	void printCharacters(unordered_map<Character*, Point2d*>& characters);

};