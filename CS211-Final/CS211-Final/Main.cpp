#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Character.h"
#include "TreeNodes.h"
using namespace std;
bool b = false;
bool* GameOver = &b;



int main()
{
	vector<string> file;
	ifstream fin;
	fin.open("encounters.txt");

	cout << "Hello my name is Harve. I have built this text based game as a final project for my CS211 class." << endl;
	cout << "In this game you will be promted to select paths and fight monsters on your own little adventure." << endl;
	cout << "To select paths simply type the number corresponding to the path that you wish to travel." << endl;
	cout << "You will also be given options for combat including attack, inventory, use [item], and run." << endl;
	cout << "Each action takes up a turn of combat, except inventory; Inventory lists all the items you currently own." << endl;
	cout << "Beware that running will not always succeed, and if it does you will forfeit all loot drops from the encounter." << endl;
	cout << endl;
	cout << "Without further ado. Let your adventure begin." << endl;

	while (fin.good())
	{
		string temp;
		getline(fin, temp);
		file.push_back(temp);
	}
	treeNode* start = new treeNode;
	Constructor(file, 0, start);
	character* player = new character;
	while (*GameOver == false)
	{
		run(start->right, player, GameOver);
	}



	return 0;
}