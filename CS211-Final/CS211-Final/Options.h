#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Fights.h"

using namespace std;

map<string, int> optionToInt
{
	make_pair("use", 1),
	make_pair("attack", 2),
	make_pair("run", 3),
	make_pair("inventory", 4),
	make_pair("go", 5)
};

void FightOption(string option, character& player, Enemy& enemy, bool &ranaway)
{
	bool finished = false;
	while (finished == false)
	{
		switch (optionToInt[option])
		{
		case 1:
			// unfinished
			finished = true;
			break;
		case 2:
			enemy.health == enemy.health - player.weapon;
			player.health == player.health - enemy.attack;
			finished = true;
			break;
		case 3:
			if (rand() % 100 < 25)
			{
				cout << "You outrun your opponent successfully, and make it to safety" << endl;
				ranaway = true;
			}
			else
			{
				cout << "You could not outrun your opponent, prepare to continue fighting." << endl;
			}
			finished = true;
			break;
		}

	}
}