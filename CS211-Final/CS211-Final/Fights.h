#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Item.h"
#include "Options.h"
#include "Character.h"

using namespace std;


void Fight(character *player, Enemy *enemy, bool &gameover)
{
	bool run = false;
	cout << enemy->name + " has appeared!" << endl;
	while (enemy->health > 0 && player->health > 0) 
	{
		string option;
		cout << "what would you like to do?" << endl;
		getline(cin, option, ' ');
		FightOption(option, player, enemy, run);
		if (run)
		{
			enemy->health = 0;
		}
	}
	if (player->health == 0)
	{
		cout << "Game Over! to try again, reset program." << endl;
		gameover = true;
	}
}