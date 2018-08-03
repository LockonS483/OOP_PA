//Assignment 6B
#include "std_lib_facilities.h"

int main(){
	//Initialize pointers
	char* pChar;
	int* pInt;
	double* pDouble;

	char c[] = "M";
	int i = 15;
	double d = 1.5;

	//assign pointers to address
	pChar = c;
	pInt = &i;
	pDouble = &d;

	//test print
	cout << "char pointer: " << &pChar << endl;
	cout << "char dereferenced value: " << *pChar << endl << endl;
	
	cout << "int pointer: " << pInt << endl;
	cout << "int dereferenced value: " << *pInt << endl << endl;

	cout << "double pointer: " << pDouble << endl;
	cout << "double dereferenced value: " << *pDouble << endl << endl;
}