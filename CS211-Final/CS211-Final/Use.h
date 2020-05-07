#pragma once

#include <string>
#include <map>
#include "Character.h"

using namespace std;

map<string, void(*)(character* player)> items
{
	make_pair("bandage", bandages),
	make_pair("shield", shields)
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
}

void shield(character* player)
{
	player->shield += 2;
}

void sword(character* player)
{
	player->weapon += 5;
}