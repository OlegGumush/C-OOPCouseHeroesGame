#include "Game.h"
#include "SearchConclusion.h"
#include "Archer.h"
#include "Wizard.h"
#include "Warrior.h"
#include <string.h>
#include <iostream>

/*
Constructor
*/
Game::Game(char * path)
{
	console = new Console();
	factory = new Factory();
	filePath = path;
}

/*
Distructor
*/
Game::~Game() {

	//delete console and factory objects
	delete console;
	delete factory;

	//delete all objects from mat
	for (size_t i = 0; i < worldSizeX; i++)
	{
		delete[] world[i];
	}
	delete[] world;

	//delete map
	for (unordered_map<Character*, Point2d*>::const_iterator it = characters.begin(); it != characters.end(); it++)
	{
		delete it->first;
		delete it->second;
	}

	//delete vector
	for (vector<Item*>::const_iterator it = items.begin(); it != items.end(); it++)
	{
		//(Item*)
		delete *it;
	}
	
	
}

/*
The function runs the game loop until all reach their destination or die
*/
void Game::play() {

	cout << "First configuration" << endl;
	read(filePath);
	console->fillData(items, characters, world, worldSizeX, worldSizeY);
	console->print(world, worldSizeX, worldSizeY);

	bool stopGame = false;

	while (!stopGame) {
		//If all the heroes finished or died stopGame will remain true and the game is OVER!!!
		stopGame = true;
		for (unordered_map<Character*, Point2d*>::const_iterator it = characters.begin(); it != characters.end(); it++)
		{
			Hero * hero = dynamic_cast<Hero*>(it->first);
			//If the pointer hero is an enemy or dead or finished I will continue.
			if (!hero || hero->getGameState() == DEAD || hero->getGameState() == FINISH) {
				continue; 
			}

			stopGame = false;
			
			vector<SearchConclusion*> enviroment = hero->ScanEnviroment(world, worldSizeX, worldSizeY);
			
			for (size_t i = 0; i < enviroment.size(); i++)
			{
				//search in vector
				if (enviroment[i]->getSymbol() == GLOB_ITEM) {
					sendHeroCollectItem(hero, enviroment[i]);
				}
				//search in map
				else if (enviroment[i]->getSymbol() == GLOB_ENEMY) {
					sendHeroToAttack(hero, enviroment[i]);
				}
			}
			moveHeroAndUpdateMap(hero);
			deleteVector(enviroment);
		}
	}

	console->printCharacters(characters);
	writeLastConfiguration();
}



/*
A function that reads the entire file get out the objects and inserted to data structures.
Factory class uses.
*/
void Game::read(char * filePath) {
	//open file
	ifstream file(filePath);

	//check if open correctly
	if (!file.is_open())
	{
		cout << "Unable to open file" << "\n";
		exit(-1);
	}

	//token represented each row in the file
	string line;

	while (getline(file, line))
	{	
		//get first string from the line
		string name = getName(line);

		//build matrix
		if (name == "matrix") {
			world = factory->buildWorld(line , worldSizeX , worldSizeY);
		}
		//build mana or health add to vector
		else if(name == "mana" || name == "health") {
			items.push_back(factory->buildPotion(line , name));
		}
		//build hero , factory return Character and only hero have 2 points so i do casting and add to map
		else if (name == "warrior" || name == "wizard" || name == "archer") {
			Character * hero = factory->buildActor(line, name);
			Point2d * point = new Point2d(hero->getLocationEnd()->getX(), hero->getLocationEnd()->getY());
			characters[hero] = point;
		}
		//build enemy or elite add to map
		else if (name == "enemy" || name == "elite") {
			Character * enemy = factory->buildEnemy(line, name);
			Point2d* point  = new Point2d(enemy->getLocationEnd()->getX(), enemy->getLocationEnd()->getY());
			characters[enemy] = point;
		}
		//build weapon and add to vector
		else if (name == "bow" || name == "sword" || name == "crossbow" || name == "staff" || name == "wand" || name == "hammer"  ) {
			items.push_back(factory->buildWeapon(line, name));
		}
		//build armor and add to vector
		else if (name == "bodyArmor" || name == "shieldArmor" ) {
			items.push_back(factory->buildArmor(line, name));
		}
	}

	file.close();
}

/*
get coordinate and symbol and set into matrix
*/
void Game::update(const size_t& x , const size_t&y, const char& symbol) {
	world[x][y] = symbol;
}

void Game::moveHeroAndUpdateMap(Hero * hero) {
	size_t x = hero->getLocationStart()->getX();
	size_t y = hero->getLocationStart()->getY();

	if (x>worldSizeX || y>worldSizeY || x<0 || y<0) {
		return;
	}

	//save my symbol on the map
	char symbol = world[x][y];

	//set my location as empty
	update(x, y, GLOB_EMPTY);

	//get destination point
	Point2d* p = characters[hero];

	//move one step to destination
	hero->move(p->getX(), p->getY() , worldSizeX , worldSizeY);

	//new location start
	x = hero->getLocationStart()->getX();
	y = hero->getLocationStart()->getY();

	//set my symbol in new location
	update(x, y, symbol);

	//print world
	cout << symbol <<" MOVE!!!" << endl;
	console->print(world, worldSizeX, worldSizeY);
}

/*
free vector
*/
void Game::deleteVector(vector<SearchConclusion*>& vec) const{
	//delete vector of pointers to SearchConclusion
	for (size_t i = 0; i < vec.size(); i++)
	{
		delete vec[i];
	}
	vec.clear();
}

/*
The function receives a line and returns the name that appears at the beginning of the line
return : name of attribute
*/
string Game::getName(const string& line) const{
	size_t i = 0;
	string temp = "";

	while(line[i] != GLOB_COMMA) {
		temp += line[i++];
	}
	return temp;
}

/*
The function receives a hero and the location of Item , finds item in the vector and gives him to a hero.
*/
void Game::sendHeroCollectItem(Hero * hero , SearchConclusion* itemPlace) {
	size_t x = itemPlace->getPoint()->getX();
	size_t y = itemPlace->getPoint()->getY();
	
	for (size_t i = 0; i < items.size(); i++)
	{	
		//If the coordinates of the item are equal to those in the vector.
		if (x == items[i]->getPoint()->getX() && y == items[i]->getPoint()->getY()) {
			//if use lift the item from the ground , need to update world.
			if (hero->use(items[i])) {
				cout << world[hero->getLocationStart()->getX()][hero->getLocationStart()->getY()] <<" take item " << world[x][y] <<endl;
				update(x, y, GLOB_EMPTY);
				console->print(world, worldSizeX, worldSizeY);
			}
		}
	}
}

/*
The function receives a hero and the location of Enemy , finds enemy in the map and gives him to a hero.
*/
void Game::sendHeroToAttack(Hero* hero, SearchConclusion* enemyPlace) {
	size_t x = enemyPlace->getPoint()->getX();
	size_t y = enemyPlace->getPoint()->getY();
	
	for (unordered_map<Character*, Point2d*>::const_iterator it = characters.begin(); it != characters.end(); it++)
	{


		//If the coordinates of the enemy are equal to those in the map.
		if (x == it->first->getLocationEnd()->getX() && y == it->first->getLocationEnd()->getY()) {

			Character* enemy = it->first;

			//ATTACK!!!!!
			if (enemy->getGameState() == ALIVE) {
				hero->attack(enemy);
				cout << world[hero->getLocationStart()->getX()][hero->getLocationStart()->getY()] <<" attack " << world[x][y] <<endl;
			}

			//hero die
			if (hero->getGameState() == DEAD) {
				update(hero->getLocationStart()->getX(), hero->getLocationStart()->getY(), GLOB_EMPTY);
				console->print(world, worldSizeX, worldSizeY);
			}
			//enemy die
			if (enemy->getGameState() == DEAD) {
				update(it->first->getLocationEnd()->getX(), it->first->getLocationEnd()->getY(), GLOB_EMPTY);
				console->print(world, worldSizeX, worldSizeY);
			}
		}
	}
}

/*
print last configuration to the file
*/
void Game::writeLastConfiguration(){
	size_t k=0;
	string path = filePath;
	string name = "";

	while(k < path.size() && path[k] != GLOB_KAV){
		name += path[k];
		if(path[k] ==GLOB_SLASH){
			name = "";
		}
		k++;
	}
	
	fstream file;
    file.open(name + GLOB_END_OF_FILE, fstream::out);

	//check if open correctly
	if (!file.is_open())
	{
		cout << "Unable to open file" << "\n";
		exit(-1);
	}
	
	for (size_t i = 0; i < worldSizeX; i++) {
		for (size_t j = 0; j < worldSizeY; j++) {
			file << world[i][j] <<  GLOB_SPACE;
		}
		file << '\n';
	}
	
	//print map
	for (unordered_map<Character*, Point2d*>::const_iterator it = characters.begin(); it != characters.end(); it++)
	{
		file << it->first->toString() <<'\n';
	}
	
	file << '\n';
	file.close();
}
