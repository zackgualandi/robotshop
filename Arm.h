/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Arm : public robotpart
{
	public:
		void Arm::build_Arm(string partType);
		string Arm::get_type();
	protected:
		string type;
};