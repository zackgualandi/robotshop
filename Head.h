/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

using namespace std;

class Head: public robotpart
{
	public:
		void Head::build_Head(string partType);
		string Head::get_type();
	protected:
		string type;
};