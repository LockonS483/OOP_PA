#include "std_lib_facilities.h"
#include "tokens.h"
#include "parser.h"
#include "vars.h"

const string prompt = "> ";
const string result = "= ";

void Cleanup(Token_Stream& ts){
	ts.ignore(print);
}

void printHelp();

void Calculate(Token_Stream& ts){
	while(cin){
		try {
			bool skip = false;
			cout << prompt;
			Token t = ts.get();

			while(t.kind == print) t = ts.get();
			if(t.kind == quit) return;
			if(t.kind == help) {
				printHelp();
				skip = true;
			}
			if(!skip){
				ts.putback(t);
				cout << result << Statement(ts) << '\n';
			}

		}catch(exception& e){
			cerr << e.what() << '\n';
			Cleanup(ts);
		}
	}
}


void printHelp(){
	cout << endl;

	cout << "Help: " << endl
		<< "The calculator supports basic arithmetics, including '+, -, *, /, %, ^'. use ';' to print answer." << endl
		<< "   For example, you can type '5+6;' which will result in the console printing 11." << endl
		<< "Variables: " << endl
		<< "   Setting syntax: x=5" << endl
		<< "   After setting, it can be used by simply using it like a number: 'x+5;'" << endl
		<< "Functions: " << endl
		<< "   Functions can be called by using function name followed by (): sin(5)" << endl
		<< "   Available functions include: sin, cos, asin, acos, tan, atan, log, log2, and log10" << endl
		<< "Constants: " << endl
		<< "   Constants can be used by numbers. They behave exactly like variables." << endl
		<< "   Available constants: 'e', 'pi'" << endl << endl;
}

int main(){
	Token_Stream ts;

	// add some important constant to our variable table:
    setValue("pi", 3.1415926535);
    setValue("e", 2.7182818284);

	try{
		Calculate(ts);
		return 0;
	}catch(...){
		cerr << "unknown error!" << endl;
		return 2;
	}
}