/*

Zackery Gualandi 10/5/2016

*/


 #include <iostream>
 #include <string>
 #include <vector>
 #include "robotpart.h"
 
 using namespace std;
 
 int main()
 {
 	string testName;
 	string testDescription;
 	int testNumber;
 	double testCost;
 	double testWeight;
 	robotpart testpart;
	
	cout << "Name: ";
 	cin >> testName;
	cin.ignore();
 	cout << '\n' << "Number: ";
 	cin >> testNumber;
	cin.ignore();
 	cout << '\n' << "Cost: $";
 	cin >> testCost;
	cin.ignore();
 	cout << '\n' << "Weight :";
 	cin >> testWeight;
	cin.ignore();
 	cout << '\n' << "Description: ";
 	getline(cin, testDescription);
	cin.ignore();
 	
 	testpart.build_part(testName, testNumber, testCost, testWeight);
 	testpart.set_description(testDescription);
 	
 	cout << '\n' << testName << " " << testNumber << " " << testCost << " " << testWeight;
 	cout << '\n' << testDescription;
 	

	cin.get();
	return 0;
 }
