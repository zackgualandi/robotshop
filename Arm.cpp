/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Arm.h"

using namespace std;

void Arm::build_Arm(string partType)
{
	type = partType;
}

string Arm::get_type()
{
	return type;
}