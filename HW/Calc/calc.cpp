#include "std_lib_facilities.h"
#include "tokens.h"
#include "parser.h"

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
			cout << result << Expression(ts) << '\n';
		}catch(exception& e){
			cerr << e.what() << '\n';
			Cleanup(ts);
		}
	}
}

int main(){
	Token_Stream ts;

	try{
		Calculate(ts);
		return 0;
	}catch(...){
		cerr << "unknown error!" << endl;
		return 2;
	}
}