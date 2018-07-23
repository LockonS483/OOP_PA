#include "std_lib_facilities.h"
#include "tokens.h"
#include "parser.h"
#include "vars.h"

const string prompt = "> ";
const string result = "= ";

void Cleanup(Token_Stream& ts){
	ts.ignore(print);
}

void Calculate(Token_Stream& ts){
	while(cin){
		try {
			cout << prompt;
			Token t = ts.get();

			while(t.kind == print) t = ts.get();
			if(t.kind == quit) return;
			ts.putback(t);
			cout << result << Statement(ts) << '\n';
		}catch(exception& e){
			cerr << e.what() << '\n';
			Cleanup(ts);
		}
	}
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