#include "std_lib_facilities.h"

class Vect{
	int size;
	double* elem;

public:
	//Constructor with size
	Vect(int s) :size{s},elem{new double[s]} {
		for(int i=0; i<size; i++){
			elem[i] = 0;
		}
	}
	//Copy Constructor
	Vect(const Vect& other) :size{other.size}, elem{new double[other.size]} {
		copy(other.elem, other.elem+other.size, elem);
	}

	//Destructor
	~Vect(){delete[] elem;}

	double get(int i){ return elem[i]; }

	void set(int i, double d){
		elem[i] = d;
	}

	//Copy Assignment
	Vect& operator=(const Vect& other){
		double* temp = new double[other.size];
		copy(other.elem, other.elem+other.size, temp);
		delete[] elem;
		elem = temp;
		size = other.size;
		return *this; //Self reference return
	}

	//Vector Access
	double operator[](int n) const{
		return elem[n];
	}
};

int main(){
	Vect v(3);
	v.set(0, 7);
	Vect v2 = v;
	v.set(1, 9.9);
	v2.set(1, 5);
	cout << "V1: " << v.get(0) << ",    V2: " << v2.get(1) << endl;
}