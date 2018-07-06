//hw1.cpp     -- 3.9.2 Drills
#include "./../Basic/std_lib_facilities.h"

int main(){
	double orig = 1500125012381219289;
	int i = orig;
	char c = orig;
	bool b = orig;
	double io = i;
	double co = c;
	double bo = b;
	cout << "\nOriginal Double: " << orig << "\n";
	cout << "Double to int: " << io << "\n";
	cout << "Double to char: " << co << "\n";
	cout << "Double to bool: " << bo << "\n\n";

	int origInt = 2519115;
	c = origInt;
	b = origInt;
	int coi = c;
	int boi = b;
	cout << "Original Int: " << origInt << "\n";
	cout << "Int to char: " << coi << "\n";
	cout << "Int to bool: " << boi << "\n\n";

	char origChar = 'a';
	b = origChar;
	char bc = b;
	cout << "Original Int: " << origChar << "\n";
	cout << "Char to bool: " << bc << "\n\n";

	return 0;
}