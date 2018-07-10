#include "std_lib_facilities.h"

int main(){
	vector<int> v;

	//Input
	cout << "Type in some numbers: " << endl;
	for(double temp; cin >> temp; ){
		v.push_back(temp);
	}

	//Finding Mean
	double sum = 0.0;
	for(double i : v){
		sum += i;
	}
	double mean = sum / v.size();
	cout << "The mean of inputted numbers is: " << mean << endl;


	//Finding median
	sort(v);
	double median = 0;
	int ind = floor(v.size()/2);
	if(v.size() % 2 == 0){
		ind--;
		median = (v[ind] + v[(ind+1)]) / 2;
	}else{
		median = v[ind];
	}
	cout << "The median of inputted numbers is: " << median << endl;

	return 0;
}