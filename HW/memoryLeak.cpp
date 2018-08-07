//Leaking memory:
#include "std_lib_facilities.h"

int main(){
	int memory = 0;
	int iterations = 0;
	while (true){
		int a = 0;
		iterations++;
		memory+=4;

		cout << "Memory Used: " << memory << " bytes in " << iterations << " iterations" << endl;
	}
}