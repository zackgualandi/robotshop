/*

Zackery Gualandi 10/5/2016

*/

#include <iostream>
#include <string>
#include <vector>
#include "RobotModel.h"
#include "Menu.h"

using namespace std;

void Menu::openMainMenu()
{
	bool timeToQuit = false;
	char input;
	while (timeToQuit == false)
	{
		cout << "Main Menu" << endl;
		cout << "==========" << endl;
		cout << "(B)rowse" << endl;
		cout << "(C)reate" << endl;
		cout << "(O)rder" << endl;
		cout << "(Q)uit" << endl;

		cin >> input;
		cin.ignore();
		if (input == 'B' || input == 'b')
		{

		}

		else if (input == 'C' || input == 'c')
		{
			cout << endl << endl;
			openCreateMenu();
		}

		else if (input == 'O' || input == 'o')
		{

		}

		else if (input == 'Q' || input == 'q')
		{
			timeToQuit = true;
		}

		else
		{
			cout << "Please only input a single character to navigate the menu." << endl;
		}
	}
}

void Menu::openCreateMenu()
{
	int counter = 1; int k = 0;
	bool timeToQuit = false;
	int input;
	while (timeToQuit == false)
	{
		cout << "Create Menu" << endl;
		cout << "==========" << endl;
		cout << "Please select a number to build a new robot in that slot" << endl;
		while (k < maxModels)
		{
			cout << counter << ": " << Menu::ourModels[counter].get_model_name() << endl;
			counter++; k++;
		}

		cout << "Press '0' to exit to main menu." << endl;

		cin >> input;
		cin.ignore();

		if (input > 0 && input <= counter)
		{
			buildRobotModel(Menu::ourModels[input]);
		}


		else if (input == 0)
		{
			timeToQuit = true;
		}
		else
		{
			cout << "Please input a single number between 1 and the maximum with no decimal to select a model" << endl;
			cout << "or press '0' to exit." << endl;
		}
	}

}

void Menu::buildRobotModel(RobotModel selectedModel)
{
	string inputName; int inputNumber; double inputCost; double inputWeight; string inputDescript; // these variables can be used to store basic part values.
	int inputTorsoCompartments; int inputLocoMaxSpeed; int inputLocoEnergyConsumption; int inputArmEnergyConsumption; double inputBatteryPower;
	double totalWeight = 0; double totalCost = 0;
	cout << "Robot Model Building Menu" << endl;
	cout << "==========" << endl;

	cout << endl << "   >Torso<" << endl;
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars):";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight:";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	cout << "Torso Battery Compartments";
	cin >> inputTorsoCompartments;
	cin.ignore();
	totalCost += inputCost;
	totalWeight += inputWeight;
	RobotModel::build_Torso(inputName, inputNumber, inputCost, inputWeight, inputDescript, inputTorsoCompartments);

	cout << endl << "   >Locomotor<" << endl;
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars):";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight:";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	cout << "Locomotor Max Speed:";
	cin >> inputLocoMaxSpeed;
	cin.ignore();
	cout << "Locomotor Energy Consumption Rate:";
	cin >> inputLocoEnergyConsumption;
	cin.ignore();
	totalCost += inputCost;
	totalWeight += inputWeight;
	RobotModel::build_Locomotor(inputName, inputNumber, inputCost, inputWeight, inputDescript,inputLocoMaxSpeed, inputLocoEnergyConsumption);

	cout << endl << "   >Head<" << endl;
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars):";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight:";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	totalCost += inputCost;
	totalWeight += inputWeight;
	RobotModel::build_Head(inputName, inputNumber, inputCost, inputWeight, inputDescript);

	cout << endl << "   >Arms<" << endl; // two identical arms (not counting being left or right side)
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars):";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight:";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	cout << "Arms Energy Consumption Rate:";
	cin >> inputArmEnergyConsumption;
	cin.ignore();
	totalCost += inputCost * 2;
	totalWeight += inputWeight * 2;
	RobotModel::build_Arm(inputName, inputNumber, inputCost, inputWeight, inputDescript, inputArmEnergyConsumption);

	cout << endl << "   >Battery<" << endl; // 1-3 identical batteries
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars):";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight:";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	cout << "Battery Max Power:";
	cin >> inputBatteryPower;
	cin.ignore();
	totalCost += inputCost * inputTorsoCompartments;
	totalWeight += inputWeight * inputTorsoCompartments;
	RobotModel::build_Battery(inputName, inputNumber, inputCost, inputWeight, inputDescript, inputBatteryPower);

	cout << endl << "   >Overall Model<" << endl;
	cout << endl << "   >Battery<" << endl; // 1-3 identical batteries
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	RobotModel::define_model(inputName, inputNumber);


}