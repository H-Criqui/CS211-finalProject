#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Character.h"
#include "Fights.h"
#include "Encounters.h"
using namespace std;


class treeNode
{
public:
	treeNode* left; // 3x+1
	treeNode* right; // 3x+3
	treeNode* center; // 3x+2
	string text;
};

void Deconstructor(treeNode* start, int i, vector<string>& result)
{
	if (result.size() > i)
	{
		if (start == NULL)
		{
			result[i] = "";

		}
		else
		{
			result[i] = start->text;
			Deconstructor(start->left, (3 * i + 1), result);
			Deconstructor(start->center, (3 * i + 2), result);
			Deconstructor(start->right, (3 * i + 3), result);
		}
	}
}

treeNode* Constructor(vector<string> file, int i, treeNode* x)
{
	if (i < file.size())
	{
		if (file[i] == "")
		{
			return x;
		}
		else if (i % 3 == 1)
		{
			treeNode* temp = new treeNode;
			temp->text = file[i];
			x->left = temp;

			Constructor(file, (3 * i + 1), temp);
			Constructor(file, (3 * i + 2), temp);
			Constructor(file, (3 * i + 3), temp);

			return x;
		}
		else if (i % 3 == 2)
		{
			treeNode* temp = new treeNode;
			temp->text = file[i];
			x->center = temp;

			Constructor(file, (3 * i + 1), temp);
			Constructor(file, (3 * i + 2), temp);
			Constructor(file, (3 * i + 3), temp);

			return x;
		}
		else if (i % 3 == 0)
		{
			treeNode* temp = new treeNode;
			temp->text = file[i];
			x->right = temp;

			Constructor(file, (3 * i + 1), temp);
			Constructor(file, (3 * i + 2), temp);
			Constructor(file, (3 * i + 3), temp);

			return x;
		}
	}
	return x;

}

map<string, int> ints
{
	make_pair("1" , 1),
	make_pair("2" , 2),
	make_pair("3" , 3)
};

map<string, string> mobs
{
	make_pair("goblins" , "leads to a group of goblins, they seem like a reasonable fight."),
	make_pair("Dragon"  , "leads to a dragon's lair. Only those with a death wish would enter here."),
	make_pair("kobolds" , "leads to a dark cave, who knows what could be inside?")
};

void run(treeNode* x, character* player)
{
	if (x != nullptr)
	{


		string answer;
		cout << "Before you lies three paths..." << endl;
		cout << "(1) " << mobs[x->left->text] << endl;
		cout << "(2) " << mobs[x->center->text] << endl;
		cout << "(3) " << mobs[x->right->text] << endl;
		cout << "Type in 1, 2, or 3 to continue." << endl;

		getline(cin, answer);
		bool retry = true;
		while (retry)
		{
			retry = false;
			switch (ints[answer])
			{
			case 1:
				run(x->left, player);
				break;
			case 2:
				run(x->center, player);
				break;
			case 3:
				run(x->right, player);
				break;
			default:
				cout << "That is not a valid answer, please type 1, 2, or 3 to continue." << endl;
				retry = true;
			}
		}
	}
	cout << "Game over, You Win!!" << endl;
}