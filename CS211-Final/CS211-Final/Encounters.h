#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include "Character.h"
#include "Fights.h"
using namespace std;

void goblins(character* player, bool* gameover)
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
		cout << "Congradulations for defeating the goblins! 1x bandage added to inventory." << endl;
		if (player->inven["bandage"] == NULL)
		{
			item* bandage = new item;
			bandage->description = "A set of slightly dirty bandages. Heals player for 15HP.";
			bandage->name = "bandage";
			player->inventory.push_back(bandage);
			player->inven.emplace(make_pair("bandage", 0));
			player->inven["bandage"] = 1;
		}
		else
		{
			player->inven["bandage"] += 1;
		}

	}
}



map<string, void(*)(character*, bool*)> encounter
{
	make_pair("goblins" , &goblins)
};
