#include "std_lib_facilities.h"
#include "vars.h"

vector<Variable> varTable;

double getValue(string s){
	for(Variable v: varTable){
		if(v.name == s){
			return v.value;
		}
	}

	return 0.0;
}

void setValue(string s, double d){
	for(Variable& v: varTable){
		if(v.name == s){
			v.value = d;
			return;
		}
	}

	varTable.push_back(Variable{s, d});
}

void printVars(){
	cout << "Variables:" << endl;
	for(Variable v: varTable){
		cout << "  " <<v.name << ": " << v.value << endl;
	}
}