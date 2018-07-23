#include "std_lib_facilities.h"
#include "vars.cpp"

int main(){
	setValue("a", 5);
	setValue("b", 6.6);
	setValue("c", 7);
	setValue("d", 8.5);
	setValue("e", 9);

	setValue("d", 99.9);

	double d;
	d = getValue("d");
	cout << "d: " << d << endl;

	printVars();
	return 0;
}