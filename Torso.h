/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Torso : public robotpart
{
	public:
		void Torso::build_Torso(int partCompartments);
		int Torso::get_Compartments();
	protected:
		int batteryCompartments;
};