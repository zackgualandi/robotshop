/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Battery.h"

using namespace std;

void Battery::build_Battery(double partEnergy, double partMaxPower)
{
	energy = partEnergy;
	maxPower = partMaxPower;
}

double Battery::get_energy()
{
	return energy;
}

double Battery::get_maxPower()
{
	return maxPower;
}