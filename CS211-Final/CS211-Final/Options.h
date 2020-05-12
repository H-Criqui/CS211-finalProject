#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include "Character.h"
#include "Use.h"


using namespace std;

map<string, int> optionToInt
{
	make_pair("use", 1),
	make_pair("attack", 2),
	make_pair("run", 3),
	make_pair("inventory", 4)
};

void FightOption(character* player, Enemy* enemy, bool &ranaway)
{
	bool finished = false;
	string temp;
	
	while (finished == false)
	{
		string option;
		getline(cin, option);
		istringstream ss{ option };
		getline(ss, temp, ' ');
		string item;
		switch (optionToInt[temp])
		{
		case 1:
			getline(ss, item);
			use(player, item);
			finished = true;
			break;
		case 2:
			cout << "You attack! ";
			cout << "You deal " + to_string(player->weapon - enemy->defense) + " damage!" << endl;
			enemy->health = enemy->health - (player->weapon - enemy->defense);
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
		case 4:
			inventory(player);
			break;
		}

	}
	if (!ranaway)
	{
		if (enemy->health > 0)
		{
			player->health += -(enemy->attack - player->shield);
			cout << "Your enemy attacks! You take " + to_string(enemy->attack - player->shield);
			cout << " damage!" << endl;
			cout << "Your health is now: " + to_string(player->health) << endl;
			cout << "Your enemy's health is now: " + to_string(enemy->health) << endl;
		}
	}
}