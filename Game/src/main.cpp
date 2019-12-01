
//#pragma once
#include <iostream>
#include "Game.h"

/*
#include "Wizard.h"
#include "Enemy.h"
#include "Enums.h"
#include "Bow.h"
#include "Staff.h"
#include "Sword.h"
#include "Hammer.h"
#include "Wand.h"
#include "CrossBow.h"

void toStringTest() {
	cout << "Heroes" << endl;
	Archer a(5, 3, 2,1,2, ARCHER, MALE);
	cout << a.toString() << endl;
	Wizard a1(5, 3, 2, 1, 2, WIZARD, MALE);
	cout << a1.toString() << endl;
	Warrior a2(5, 3, 2, 1, 2, WARRIOR, FEMALE);
	cout << a2.toString() << endl;

	cout << "Armors" << endl;
	BodyArmor b(5, 3, 2, SHIELD_ARMOR);
	cout << b.toString() << endl;
	HandArmor b1(5, 3, 2, SHIELD_ARMOR);
	cout << b1.toString() << endl;

	cout << "Weapon" << endl;
	CrossBow c2(2, 2, CROSSBOW, 45);	
	cout << c2.toString() << endl;
	Bow c1(2, 2, BOW, 45);	
	cout << c1.toString() << endl;
	Sword c3(2, 2, SWORD, 45);
	cout << c3.toString() << endl;
	Hammer c6(2, 2, HAMMER, 45);
	cout << c6.toString() << endl;
	Wand c4(2, 2, WAND, 45);
	cout << c4.toString() << endl;
	Staff c5(2, 2, STAFF, 45);
	cout << c5.toString() << endl;


}
*/
void myMain(int argc, char* argv[]) {

	for (int i = 0; i < argc; i++) {
		cout << argv[i] <<endl;
	}

	if(argc < 2){
		cout << "Enter input file or enter command -help" <<endl;
		cout << "Example : ./run_game.o -help" <<endl;
		return ;
	}
	string s = argv[1];
	if(s == "-help"){
		cout << "Welcome to my game:" <<endl;
		cout << "To run the game please enter a \"build\" folder," <<endl;
		cout << "run a command \"cmake ..\" after that run a command \"make\"," <<endl;
		cout << "in \"build\" folder will be created an execution file \"run_game.o\" "<< endl;
		cout << "to run a configuration file you should run command : "<< endl;
		cout << "./run_game.o -n [number] -files [file1 file2 ...] ."<< endl;
		cout << "For example : ./run_game.o -n 2 -files ../inputs/g1_in.csv ../inputs/g2_in.csv "<< endl;

	}else{
		for (int i = 4; i < argc; i++)
		{
			Game g(argv[i]);
			g.play();
		}
	}
}
int main(int argc, char* argv[])
{
	myMain(argc, argv);
	return 0;
}