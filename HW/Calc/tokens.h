#include "std_lib_facilities.h"

const char number = '8';
const char invalid = 'i';
const char name = 'a';
const char quit = 'q';
const char help = 'h';
const char power = '^';
const char print = ';';

class Token{
public:
    char kind;
    double value;
    string name;
    Token(char ch) :kind{ch} {}
    Token(char ch, double val) :kind{ch}, value{val} {}
    Token(char ch, string n) :kind{ch}, name{n} {}
};

class Token_Stream{
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	//bool full{false};
	vector<Token> buffer;
};

Token LastBuffer();