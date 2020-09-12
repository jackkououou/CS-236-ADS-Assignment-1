#include <iostream>
#include <string>
#include "LargeInt.h"
using namespace std;

int main()
{
	char choice;
	string num1 = "45879106595816971367851544743676474171235979148", num2 = "85161379134567892811671974197195671495364114146";
	LargeInt Num1, Num2;
	//TO DO: Check addition again and then go over bool again; ADD a resize element to the end of + and -
	do
	{
		//input
		cout << "Enter an integer of at most 50 digits: " << endl;
		cin >> Num1;
		cout << "Enter an integer of at most 50 digits: " << endl;
		cin >> Num2;

		//display numbers; if greater than 50 digits then make num 0
		cout << "num1: " << Num1 << endl;
		cout << "num2: " << Num2 << endl;

		//Addition - Subtraction
		cout << "num1 + num2 = " << Num1 + Num2 << endl;
		cout << "num1 - num2 = " << Num1 - Num2 << endl;

		//Bool - Equals
		cout << "num1 == num2: ";
		if (Num1 == Num2)
			cout << '1' << endl;
		else
			cout << '0' << endl;

		//Bool - not equal
		cout << "num1 != num2: ";
		if (Num1 != Num2)
			cout << '1' << endl;
		else
			cout << '0' << endl;

		//Bool- greater
		cout << "num1 > num2: ";
		if (Num1 > Num2)
			cout << '1' << endl;
		else
			cout << '0' << endl;

		//Bool- greater or equal
		cout << "num1 >= num2: ";
		if (Num1 >= Num2)
			cout << '1' << endl;
		else
			cout << '0' << endl;

		//Bool- less
		cout << "num1 < num2: ";
		if (Num1 < Num2)
			cout << '1' << endl;
		else
			cout << '0' << endl;

		//Bool- less or equal
		cout << "num1 <= num2: ";
		if (Num1 <= Num2)
			cout << '1' << endl;
		else
			cout << '0' << endl;

		cout << "Would you like to try again (y/n)?";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	return 0;
}