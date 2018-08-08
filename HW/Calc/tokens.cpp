#include "std_lib_facilities.h"
#include "tokens.h"

std::ostream &operator<<(std::ostream &os, Token const &t) { 
    return os << t.kind;
}

void Token_Stream::putback(Token t){
	buffer.push_back(t);
}

Token Token_Stream::get(){
	if(buffer.size() > 0){
		Token temp = buffer.back();
		buffer.pop_back();
		return temp;
	}
	char temp;
	cin >> temp;
	switch(temp){
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case '^':
		case '(':
		case ')':
		case '%':
		case print:
		case quit:
		case help:
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
			if(isalpha(temp)){
				string s;
				s += temp;
				while(cin.get(temp) && (isalpha(temp) || isdigit(temp))){
					s += temp;
				}
				cin.putback(temp);
				return Token{name, s};
			}else{
				return Token{invalid, double(temp)};
			}
	}

	return Token{'q'};
}

void Token_Stream::ignore(char c){
	while(buffer.size() > 0){
		Token t = buffer.back();
		buffer.pop_back();
		if(t.kind == c){
			return;
		}
	}
	
	char ch = 0;
	while(cin>>ch){
		if(ch == c){
			return;
		}
	}
}

////////////////////////////
///////OLD ASSIGNMENT///////
////////////////////////////
/*
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
}*/