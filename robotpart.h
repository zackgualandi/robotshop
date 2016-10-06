/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
class Robotpart 
{
	public:
		void build_part(string partName, string partDescript, int partNum, double partCost);
		void set_description();
		string get_name();
		string get_description();
		int get_part_number();
		double get_cost();
		double get_weight();
		
	private:
		string name;
		string description;
		int partNumber;
		double cost;
		double weight;
}
