#include <iostream>
#include <string>
using namespace std;


const int daysin[] = {0,  31,28,31,30,31,30,31,31,30,31,30,31};
const int daysinLeap[] = {0,  31,29,31,30,31,30,31,31,30,31,30,31};
const string monthNames[] = {"invalid", "January", "February", "March", "April", "May", "June",
								"July", "August", "September", "October", "Novermber", "December"};

class Date{
public:
	//Constructor
	Date();
	Date(int y, int m, int d);

	//Get/Set Methods
	void addDay(int n);
	void addMonth(int n);
	void addYear(int n);
	void setDay(int n);
	void setMonth(int n);
	void setYear(int n);
	int day();
	int month();
	int year();
	void FullPrint();

	string toString() const;
	bool isValid() const;
	bool leapYear() const; //is it a
	void ConvertValid();

	//Operators
	bool operator == (const Date& other);
	bool operator != (const Date& other);
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);

private:
	int y,m,d; //Year, Month, Day
};