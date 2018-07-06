#include "std_lib_facilities.h"

int main(){
	cout << "Please enter your first name: \n";
	string first_name;
	cin >> first_name;
	int age;
	cout << "Please enter your age: \n";
	cin >> age;
	cout << "Profile: " << first_name << ", Age: " << age << "\n";
	return 0;
}