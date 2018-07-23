#include <iostream>
#include <string>
#include "funcs.h"

using namespace std;

// test harness for funcs.cpp:
int main(){
    double d = .5;
    cout << "sin(d) = " << ExecFunc("sin", d) << '\n';
    cout << "cos(d) = " << ExecFunc("cos", d) << '\n';
    d = 1.5708;
    cout << "sin(d) = " << ExecFunc("sin", d) << '\n';
    cout << "cos(d) = " << ExecFunc("cos", d) << '\n';
    d = 0.0;
    cout << "sin(d) = " << ExecFunc("sin", d) << '\n';
    cout << "cos(d) = " << ExecFunc("cos", d) << '\n';
}