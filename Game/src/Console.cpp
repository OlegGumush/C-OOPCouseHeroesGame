#include "Console.h"
#include "Potion.h"
#include "Item.h"
#include "Character.h"
#include "Console.h"
#include "Factory.h"
#include "Point2d.h"

/*
Constructor
*/
Console::Console() {}

/*
Distructor
*/
Console::~Console() {}

/*
A function that accepts a matrix and two data structures. And fills the matrix
*/
void Console::fillData(const vector<Item*>& items, unordered_map<Character*, Point2d*>& characters, char ** const world ,const size_t& x ,const size_t& y)  const{

	//Passing the matrix
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{				
			world[i][j] = getSymbol(i,j,items,characters);
		}

	}
}

/*
The function receives a point and data structures.
Returns a char/symbol if one object should be at this point.
Returns a '.' if nothing found.
*/
char Console::getSymbol(const size_t& i, const size_t& j , const vector<Item*>& items, unordered_map<Character*, Point2d*>& characters)  const {

	//Passing the vector
	for (size_t n = 0; n < items.size(); n++) {
		//If i have an object that is at this point than mark within the matrix
		if (items[n]->getPoint()->getX() == i && items[n]->getPoint()->getY() == j)
		{
			return getTypeItem(items[n]);
		}
	}
	//Passing the map
	for (unordered_map<Character*, Point2d*>::iterator it = characters.begin(); it != characters.end(); it++) {
		//If i have an object that is at this point than mark within the matrix
		if (it->first->getLocationStart()->getX() == i && it->first->getLocationStart()->getY() == j)
		{
			return getTypeCharacter(it->first);
		}
	}
	//If i do not mark anything return GLOB_EMPTY  that represent '.'
	return GLOB_EMPTY;
}

/*
The function prints the matrix.
*/
void Console::print(char ** const world, const size_t& x, const size_t& y)  const {
	
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			cout << world[i][j] << " ";
		}
		cout << "" << endl;
	}
	cout << "" << endl;
}

/*
Function gets a item and returns the character that represents him.
return '!' if is not suitable for anything. ERROR.
*/
char Console::getTypeItem(Item* const item) const  {

	if (item->getType() == POTION) {
		return GLOB_POTION;
	}
	else if (item->getType() == WEAPON) {
		return GLOB_WEAPON;
	}
	else if (item->getType() == ARMOR) {
		return GLOB_ARMOR;
	}
	return GLOB_ERROR;
}

/*
Function gets a character and returns the character that represents him.
return '!' if is not suitable for anything. ERROR.
*/
char Console::getTypeCharacter(Character* const character) const  {
	if (character->getCharacterType() == WARRIOR) {
		return GLOB_WARRIOR;
	}
	else if (character->getCharacterType() == ARCHER) {
		return GLOB_ARCHER;
	}
	else if (character->getCharacterType() == WIZARD) {
		return GLOB_WIZARD;
	}
	else if (character->getCharacterType() == ENEMY) {
		return GLOB_ENEMY;
	}
	else if (character->getCharacterType() == ELITE) {
		return GLOB_ELITE;
	}
	return GLOB_ERROR;
}

/*
print all characters to the screen
*/
void Console::printCharacters(unordered_map<Character*, Point2d*>& characters){
	
	for (unordered_map<Character*, Point2d*>::const_iterator it = characters.begin(); it != characters.end(); it++)
	{
		std::cout << it->first->toString() << std::endl;
	}
	
	std::cout << "\n\n" << std::endl;

}