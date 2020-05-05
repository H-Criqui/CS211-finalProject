#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Item.h"

using namespace std;

class Enemy {
public:
	string name;
	int health;
	int attack;
	int defense;
};

class character {
public:
	int health;
	vector<item> inventory;
	int weapon;
	int shield;


};

void Fight(character player, Enemy enemy, bool &gameover)
{
	cout << enemy.name + " has appeared!" << endl;
	while (enemy.health != 0 && player.health != 0) 
	{
		string option;
		cout << "what would you like to do?" << endl;
		getline(cin, option, ' ');
		
	}
	if (player.health == 0)
	{
		cout << "Game Over! to try again, reset program." << endl;
		gameover = true;
	}
}