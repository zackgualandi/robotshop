/*

Zackery Gualandi 10/5/2016

*/


#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include "RobotModel.h"
const int maxModels = 5; // sets the maximun number of robots to sell.

class Menu : public RobotModel
{
	public:
		void Menu::openMainMenu();
		void Menu::openCreateMenu();
		void Menu::buildRobotModel(RobotModel selectedModel);
	private:
		RobotModel ourModels[maxModels];
};
#endif
