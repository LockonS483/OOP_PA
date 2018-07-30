#include "std_lib_facilities.h"
#include "date.h"

void PrintHelp();

int main(){
	Date temp;
	Date date{2018,1,1};

	bool equalit = date == temp;
	cout << "Enter initial date (YYYY/MM/DD): ";
	cin >> date;
	cout << "OK! Today's date is: " << date;
	cout << "Above was date setting and printing with stream operator overloads '<<' and '>>'." << endl;

	cout << "Try interactions below:\n" << "Type 'h' for help." << endl;

	char cmd;
	while (cin){
		cout << "/>>";
		cin >> cmd;

		switch(cmd){
		case 'h':
			PrintHelp();
			break;
		case 'q':
			return 0;
			break;


		case 'p':
			cout << "Today's date is: " << date.toString() << endl;
			cout << "For long date display, use 'f'." << endl;
			break;
		case 'f':
			cout << "The full date is: " << endl;
			date.FullPrint();
			break;

		case 's':
			cout << "Enter set date (YYYY/MM/DD): ";
			cin >> date;
			cout << "The new date is: " << date << endl;
			break;
		case 'd':
			cout << "Enter days to add: ";
			int nd;
			cin >> nd;
			date.addDay(nd);
			cout << "The new date is: " << date << endl;
			break;
		case 'm':
			cout << "Enter months to add: ";
			int nm;
			cin >> nm;
			date.addMonth(nm);
			cout << "The new date is: " << date << endl;
			break;
		case 'y':
			cout << "Enter years to add: ";
			int ny;
			cin >> ny;
			date.addYear(ny);
			cout << "The new date is: " << date << endl;
			break;


		case 'e':
			cout << "Current date is: " << date << endl;
			cout << "Enter a date to compare with (YYYY/MM/DD): ";
			cin >> temp;
			equalit = (temp == date);
			cout << "Equality test result: " << equalit << endl;
			break;


		default:
			cout << "Invalid input. Input 'h' for help." << endl;
			break;
		}
	}
}

void PrintHelp(){
	cout << endl;
	cout << "The available commands are as follows:\n" << "h: help.\n"
		<< "p: print date.\n" << "f: full print date.\n" << "s: set date\n"
		<< "d,m,y: add to day, month, and year, respectively.\n" << "e: test equality\n"
		<< "q: QUIT\n";
	return;
}