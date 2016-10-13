/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Head.h"

using namespace std;

void Head::build_Head(string partType)
	{
		type = partType;
	}

string Head::get_type()
	{
		return type;
	}
