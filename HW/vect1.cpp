#include "std_lib_facilities.h"

class Vect{
	int size;
	double* elem;

public:
	Vect(int s) :size{s},elem{new double[s]} {
		for(int i=0; i<size; i++){
			elem[i] = 0;
		}
	}
	~Vect(){delete[] elem;}

	double get(int i){ return elem[i]; }

	void set(int i, double d){
		elem[i] = d;
	}
};

int main(){
	Vect v(3);
	v.set(2, 2.2);
	/*Vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);*/
	cout << v.get(0) << endl;//"  //  " << v2.get(1);
}