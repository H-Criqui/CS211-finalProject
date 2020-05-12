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
	if (player->health > 0)
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


void Arena(character* player, bool* gameover)
{
	cout << "You enter the arena. A large goliath towers above you, his shield at the ready. Upon his shoulder lies a goblin with a sling shot. Prepare to battle." << endl;
	Enemy* Goliath = new Enemy;
	Goliath->health = 22;
	Goliath->attack = 2;
	Goliath->defense = 1;
	Goliath->name = "Go and Gob";
	Fight(player, Goliath, gameover);
	if (player->health > 0)
	{
		cout << "Congradulations for defeating Gol and Gob! 1x shield added to inventory." << endl;
		if (player->inven["shield"] == NULL)
		{
			item* shield = new item;
			shield->description = "A better shield than the one you currently own. You should be able to block some more damage with this.";
			shield->name = "shield";
			player->inventory.push_back(shield);
			player->inven.emplace(make_pair("shield", 0));
			player->inven["shield"] = 1;
		}
		else
		{
			player->inven["shield"] += 1;
		}

	}
}

void assassin(character* player, bool* gameover)
{
	cout << "As you enter the forest an assassin jumps out at you. Prepare to fight for your life." << endl;
	Enemy* assassin = new Enemy;
	assassin->health = 20;
	assassin->attack = 5;
	assassin->defense = 0;
	assassin->name = "%^*(*&^";
	Fight(player, assassin, gameover);
	if (player->health > 0)
	{
		cout << "The assassin, now sufficiantly injured, dissapears into the thicket! 1x sword added to inventory." << endl;
		if (player->inven["sword"] == NULL)
		{
			item* sword = new item;
			sword->description = "A better sword than the one you currently own. You should be able to do some more damage with this.";
			sword->name = "sword";
			player->inventory.push_back(sword);
			player->inven.emplace(make_pair("sword", 0));
			player->inven["sword"] = 1;
		}
		else
		{
			player->inven["sword"] += 1;
		}

	}
}


map<string, void(*)(character*, bool*)> encounter
{
	make_pair("goblins" , &goblins),
	make_pair("assassin", &assassin),
	make_pair("arena", &Arena)
};
