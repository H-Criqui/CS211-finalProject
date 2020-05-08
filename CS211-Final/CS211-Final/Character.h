#pragma once

#include <string>
#include <vector>
#include <map>
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
	int health = 25;
	vector<item*> inventory;
	int weapon = 2;
	int shield = 0;
	int maxHealth = 25;
	map<string, int> inven;

};

void inventory(character *player)
{
	int i = 0;
	while (i < player->inventory.size())
	{
		if (player->inventory[i] != nullptr)
		{
			cout << player->inventory[i]->name << endl;
		}
	}
}

