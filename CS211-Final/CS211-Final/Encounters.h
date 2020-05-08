#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include "Character.h"
#include "Fights.h"
using namespace std;

map<string, void(*)> encounter
{
	make_pair("Goblins" , goblins)
};

void goblins(character* player, bool &gameover)
{
	cout << "A pack of goblins stands before you. Each equipped with a hog-pogged set of armor and weapons. Expect an intense battle!" << endl;
	Enemy* goblinTribe = new Enemy;
	goblinTribe->health = 15;
	goblinTribe->attack = 3;
	goblinTribe->defense = 0;
	goblinTribe->name = "goblins";
	Fight(player, goblinTribe, gameover);
	if (!gameover)
	{
		cout << "Congradulations for defeating the goblins! 1x bandages added to inventory." << endl;
		if (find(player->inventory.begin(), player->inventory.end(), bandage) != player->inventory.end())
		{
			item* bandage = new item;
			bandage->description = "A set of slightly dirty bandages. Heals player for 15HP.";
			bandage->name = "bandage";
			player->inventory.push_back(bandage);
			player->inven.insert(make_pair("bandage", 1));
		}
		else
		{
			player->inven["bandage"] += 1;
		}

	}
}


