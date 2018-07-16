#include "std_lib_facilities.h"
#include "tokens.h"
#include <cctype>
#include <string>

Token GetToken();

int main(){
	Vector<Token> tok;
	for(Token t=GetToken(); t.kind!='q'; t=GetToken()){
		tok.push_back(t);
	}

	for(Token t: tok){
		if(t.kind == '8'){
			cout << "A token with val: " << t.value << endl;
		}else{
			cout << "A token of kind: " << t.kind << endl;
		}
	}

	return 0;
}

Token GetToken(){
	char temp;
	cin >> temp;
	switch(temp){
		case '+':
		case '-':
		case '*':
		case '/':
		case print:
		case quit:
			return Token{temp};
		case '.':
		case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': case '0':
		{
			cin.putback(temp);
			double val;
			cin >> val;
			return Token{number, val};
		}
		default:
			return Token{'i'};
	}

	return Token{'q'};
}