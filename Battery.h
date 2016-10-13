/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Battery : public robotpart
{
	public:
		void Battery::build_Battery(double partEnergy, double partMaxPower);
		double Battery::get_energy();
		double Battery::get_maxPower();
	protected:
		double energy;
		double maxPower;
};