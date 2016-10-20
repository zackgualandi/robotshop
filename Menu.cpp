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
			cout << endl << endl;
			openBrowseMenu();
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

//////////////////
// BROWSE MENU
//////////////////

void Menu::openBrowseMenu()
{
	int counter; int k;
	bool timeToQuit = false;
	int input;
	while (timeToQuit == false)
	{
		k = 0;
		counter = 1;
		cout << "Browse Menu" << endl;
		cout << "==========" << endl;
		cout << "Please select a number to view a robot" << endl;
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
			displayRobotModel(Menu::ourModels[input]);
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

void Menu::displayRobotModel(RobotModel selectedModel)
{
	cout << "Robot Name: " << selectedModel.get_model_name() << endl << " Model Number: " << selectedModel.get_model_number() << endl;
	cout << "Price: $ " << selectedModel.get_model_price() << " Weight: " << selectedModel.get_model_weight() << "kg" << endl; 
	cout << selectedModel.get_model_description() << endl << endl;
	cout << "Head: " << selectedModel.model_head.get_name() << endl;
	cout << "Torso: " << selectedModel.model_torso.get_name() << endl << "Battery Compartments: " << selectedModel.get_Compartments() << endl << endl;
	cout << "Battery: " << selectedModel.model_battery.get_name() << endl << "Max Power (in kilowatt hours): " << selectedModel.get_maxPower() << endl << endl;
	cout << "Locomotor: " << selectedModel.model_locomotor.get_name() << endl << "Max Speed (in mph): " << selectedModel.get_maxSpeed() << "Energy Consumption: " << selectedModel.model_locomotor.get_consumtionRate() << endl << endl;
	cout << "Arm: " << selectedModel.model_arm.get_name() << endl << "Energy Consumption" <<  selectedModel.model_arm.get_consumtionRate() << endl;
}

//////////////////
// CREATE MENU
//////////////////

void Menu::openCreateMenu()
{
	int counter; int k;
	bool timeToQuit = false;
	int input;
	while (timeToQuit == false)
	{
		k = 0;
		counter = 1;
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
	cout << "Part Cost (in US dollars): $";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight (in kg):";
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
	selectedModel.build_Torso(inputName, inputNumber, inputCost, inputWeight, inputDescript, inputTorsoCompartments);

	cout << endl << "   >Locomotor<" << endl;
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars): $";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight (in kg):";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	cout << "Locomotor Max Speed (in mph):";
	cin >> inputLocoMaxSpeed;
	cin.ignore();
	cout << "Locomotor Energy Consumption Rate:";
	cin >> inputLocoEnergyConsumption;
	cin.ignore();
	totalCost += inputCost;
	totalWeight += inputWeight;
	selectedModel.build_Locomotor(inputName, inputNumber, inputCost, inputWeight, inputDescript,inputLocoMaxSpeed, inputLocoEnergyConsumption);

	cout << endl << "   >Head<" << endl;
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars): $";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight (in kg):";
	cin >> inputWeight;
	cin.ignore();
	cout << "Part Description:";
	getline(cin, inputDescript);
	cin.ignore();
	totalCost += inputCost;
	totalWeight += inputWeight;
	selectedModel.build_Head(inputName, inputNumber, inputCost, inputWeight, inputDescript);

	cout << endl << "   >Arms<" << endl; // two identical arms (not counting being left or right side)
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars): $";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight (in kg):";
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
	selectedModel.build_Arm(inputName, inputNumber, inputCost, inputWeight, inputDescript, inputArmEnergyConsumption);

	cout << endl << "   >Battery<" << endl; // 1-3 identical batteries
	cout << "Part Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Part Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Part Cost (in US dollars): $";
	cin >> inputCost;
	cin.ignore();
	cout << "Part weight (in kg):";
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
	selectedModel.build_Battery(inputName, inputNumber, inputCost, inputWeight, inputDescript, inputBatteryPower);

	cout << endl << "   >Overall Model<" << endl;
	cout << endl << "   >Battery<" << endl; // 1-3 identical batteries
	cout << "Model Name: ";
	cin >> inputName;
	cin.ignore();
	cout << "Model Number:";
	cin >> inputNumber;
	cin.ignore();
	cout << "Model Description:";
	getline(cin, inputDescript);
	cin.ignore();
	selectedModel.define_model(inputName, inputNumber);
	selectedModel.set_description(inputDescript);
	selectedModel.set_price(totalCost);
	selectedModel.set_weight(totalWeight);

}

//////////////////
// Order MENU
//////////////////

void Menu::openOrderMenu()
{
	int counter; int k;
	bool timeToQuit = false;
	int input;
	while (timeToQuit == false)
	{
		k = 0;
		counter = 1;
		cout << "Order Menu" << endl;
		cout << "==========" << endl;
		cout << "Please select a number to view a robot" << endl;
		while (k < maxModels)
		{
			cout << counter << ": " << Menu::ourModels[counter].get_model_name() << Menu::ourModels[counter].get_model_price() << endl;
			counter++; k++;
		}

		cout << "Press '0' to exit to main menu." << endl;

		cin >> input;
		cin.ignore();

		if (input > 0 && input <= counter)
		{
			orderRobotModel(Menu::ourModels[input]);
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

void Menu::orderRobotModel(RobotModel selectedModel)
{
	int orderQuantity; string customerName; string customerAddress; string customerPhone;
	bool timeToQuit = false;
	char input;

	cout << "Customer Name: ";
	getline(cin, customerName);
	cin.ignore();
	cout << "Customer Address: ";
	getline(cin, customerAddress);
	cin.ignore();
	cout << "Customer Phone: ";
	getline(cin, customerPhone);
	cin.ignore();

	while (timeToQuit == false)
	{
		cout << "Input the number of " << selectedModel.get_model_name() << " being ordered.";
		cin >> orderQuantity;
		cin.ignore();
		cout << "Purchase " << orderQuantity << " order(s) of " << selectedModel.get_model_name() << "for: $" << orderQuantity*selectedModel.get_model_price() << endl;
		cout << "(Y)es (N)o (C)ancel" << endl;

		if (input == 'Y' || input == 'y')
		{
			timeToQuit = true;
		}

		else if (input == 'N' || input == 'n')
		{
			timeToQuit = false;
		}

		else if (input == 'C' || input == 'c')
		{
			customerName = "";
			customerAddress = ""; 
			customerPhone = "";
			timeToQuit = true;
		}

		else
		{
			cout << "Please only input a single character to navigate the menu." << endl;
		}

		cin >> input;
		cin.ignore();

	}
}