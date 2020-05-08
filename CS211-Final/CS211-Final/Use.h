#pragma once

#include <string>
#include <map>
#include "Character.h"

using namespace std;

map<string, void(*)(character* player)> items
{
	make_pair("bandage", bandages),
	make_pair("shield", shields),
	make_pair("sword", swords)
};

void use(character* player, string item)
{
	items[item](player);
}

void (*bandages)(character*) = bandage;
void (*shields)(character*) = shield;
void (*swords)(character*) = sword;


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
		vector<item*>::iterator it = find(player->inventory.begin(), player->inventory.end(), bandage);
		int index = distance(player->inventory.begin(), it);
		player->inventory[index] = nullptr;
	}
}

void shield(character* player)
{
	player->shield += 2;
}

void sword(character* player)
{
	player->weapon += 5;
}