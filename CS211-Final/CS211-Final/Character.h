#pragma once

#include <string>
#include <vector>
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

void inventory(character *player)
{
	int i = 0;
	while (i < player->inventory.size())
	{
		cout << player->inventory[i].name << endl;
	}
}