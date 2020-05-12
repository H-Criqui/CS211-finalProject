#pragma once

#include <string>
#include <map>
#include "Character.h"

using namespace std;


void bandage(character* player)
{
	player->health += 15;
	if (player->health > player->maxHealth)
	{
		player->health = player->maxHealth;
	}
	player->inven["bandage"] += -1;
	if (player->inven["bandage"] < 1)
	{
		player->inven.erase("bandage");
		/*vector<item*>::iterator it = find(player->inventory.begin(), player->inventory.end(), bandage);
		int index = distance(player->inventory.begin(), it);
		player->inventory[index] = nullptr;*/
	}
}

void shield(character* player)
{
	player->shield += 1;
	player->inven["shield"] += -1;
	if (player->inven["shield"] <= 0)
	{
		player->inven.erase("shield");
	}
}

void sword(character* player)
{
	player->weapon += 1;
	player->inven["sword"] += -1;
	if (player->inven["sword"] <= 0)
	{
		player->inven.erase("sword");
	}
}

void (*bandages)(character*) = bandage;
void (*shields)(character*) = shield;
void (*swords)(character*) = sword;

map<string, void(*)(character* player)> items
{
	make_pair("bandage", bandages),
	make_pair("shield", shields),
	make_pair("sword", swords)
};

void use(character* player, string item)
{
	if (player->inven[item] > 0)
	{
		items[item](player);
	}
	else
	{
		cout << "You reach for your " + item + ", but it is not there." << endl;
		cout << "You either don't have this item or you have run out." << endl;
	}
}
