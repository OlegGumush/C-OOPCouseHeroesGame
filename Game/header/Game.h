#pragma once
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "Console.h"
#include  "Factory.h"

class SearchConclusion;
class Hero;
class Potion;
class Item;
class Character;

using namespace std;

class Game {
public:
	/*
	Constructor
	*/
	Game(char * path);
	/*
	Distructor
	*/
	~Game();

	/*
	The function runs the game loop until all reach their destination or die
	*/
	void play();	

protected:

	Console * console;
	Factory * factory;

	char ** world;
	size_t worldSizeX;
	size_t worldSizeY;

	vector<Item*> items;
	unordered_map<Character*, Point2d*> characters;

	/*
	A function that reads the entire file get out the objects and inserted to data structures.
	Factory class uses.
	*/
	void read(char * filePath);
	/*
	get coordinate and symbol and set into matrix
	*/
	void update(const size_t& x, const size_t&y, const char& symbol);
	/*
	hold path of input file
	*/
	char * filePath;
	/*
	getters
	*/
	string getName(const string& line) const;
	/*
	The function receives a hero and the location of Item , finds item in the vector and gives him to a hero.
	*/
	void sendHeroCollectItem(Hero *  hero , SearchConclusion* itemPlace);
	/*
	The function receives a hero and the location of Enemy , finds enemy in the map and gives him to a hero.
	*/
	void sendHeroToAttack(Hero* hero , SearchConclusion* enemyPlace);
	/*
	move hero to his location delete his old mark and update to new location
	*/
	void moveHeroAndUpdateMap(Hero * hero);
	/*
	free vector
	*/
	void deleteVector(vector<SearchConclusion*>& vec)const;
	/*
	print last configuration to the file
	*/
	void writeLastConfiguration();

};