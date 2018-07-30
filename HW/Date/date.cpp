#include "std_lib_facilities.h"
#include "date.h"

//Constructors
Date::Date(int yy, int mm, int dd):y{yy}, m{mm}, d{dd}{
	if(!isValid()){
		ConvertValid();
	}
}
Date::Date(){
	y=2018;
	m=1;
	d=1;
}


//Get/Set
void Date::addDay(int n){
	d += n;
	ConvertValid();
	return;
}
void Date::addMonth(int n){
	m += n;
	ConvertValid();
	return;
}
void Date::addYear(int n){
	y += n;
	ConvertValid();
	return;
}
void Date::setDay(int n){
	Date test = Date{y, m, n};
	if(test.isValid()){
		d = n;
		return;
	}
	cout << "Input is invalid. Day was not changed" << endl;
	return;
}
void Date::setMonth(int n){
	Date test = Date{y, n, d};
	if(test.isValid()){
		m = n;
		return;
	}
	cout << "Input is invalid. Month was not changed" << endl;
	return;
}
void Date::setYear(int n){
	y = n;
}
int Date::day(){return d;}
int Date::month(){return m;}
int Date::year(){return y;}
void Date::FullPrint(){
	cout << monthNames[m] << " " << d << ", " << y << endl;
	return;
}

//Other methods
string Date::toString() const{
	string temp = std::to_string(y) + "/";
	temp += std::to_string(m) + "/";
	temp += std::to_string(d);
	return temp;
}

bool Date::isValid() const{
	//Check Month Error
	if(m > 12){
		return false;
	}

	//Check Day Error
	if(d > daysin[m]){
		if(leapYear()){
			if(d > daysinLeap[m]){
				return false;
			}
		}
		return false;
	}

	return true;
}

bool Date::leapYear() const{
	return (y%4 == 0);
}

void Date::ConvertValid(){
	while(!isValid()){
		if(m > 12){
			y += 1;
			m -= 12;
		}else{
			if(d > daysin[m]){
				if(leapYear()){
					if(d > daysinLeap[m]){
						d -= daysinLeap[m];
						m++;
					}
				}else{
					d -= daysin[m];
					m++;
				}
			}
		}
	}
}

bool Date::operator == (const Date& other){
	if(this->d == other.d && this->m == other.m && this->y == other.y){
		return true;
	}
	return false;
}
bool Date::operator != (const Date& other){
	return !(*this == other);
}
std::ostream& operator << (std::ostream& out, const Date& d){
	out << d.toString() << endl;
	return out;
}

std::istream& operator >> (std::istream& in, Date& d){
	int inY, inM, inD;
	char s1, s2;
	in >> inY >> s1 >> inM >> s2 >> inD;
	Date test{inY, inM, inD};

	if(!test.isValid()){
		cout << "Invalid input. Date was not changed.\nUse the format YYYY/MM/DD" << endl;
		return in;
	}
	d.setYear(inY);
	d.setMonth(inM);
	d.setDay(inD);
	return in;
}