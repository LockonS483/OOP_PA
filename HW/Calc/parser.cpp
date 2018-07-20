#include "std_lib_facilities.h"
#include "tokens.h"
#include "parser.h"

double Expression(Token_Stream& ts){
	/*

	Accepted:
	- Term
	- Expression '+' Term
	- Expression '-' Term
	*/

	double left = Term(ts);
	Token t = ts.get();

	while(true){
		switch(t.kind){
		case '+':
			left += Term(ts);
			t = ts.get();
			break;
		case '-':
			left -= Term(ts);
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double Term(Token_Stream& ts){
	/*

	Accepted:
	- Primary
	- Term '*' Primary
	- Term '/' Primary
	- Term '%' Primary
	*/

	double left = Primary(ts);
	Token t = ts.get();

	while(true){
		switch(t.kind){
		case '*':
			left *= Primary(ts);
			t = ts.get();
			break;
		case '/':
			{
				double d = Primary(ts);
				if(d == 0) error("Dividing by 0!");
				left /= d;
				t = ts.get();
				break;
			}
		case '%':
			{
				double d = Primary(ts);
				if(d == 0) error("Dividing by 0!");
				left = fmod(left, d);
				t = ts.get();
				break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double Primary(Token_Stream& ts){
	Token t = ts.get();
	switch (t.kind){
	case '(':
		{
			double d = Expression(ts);
			t = ts.get();
			if(t.kind != '(') error("'(' expected");
			return d;
		}
	case number:
		return t.value;
	case '-':
		return -Primary(ts);
	case '+':
		return Primary(ts);
	default:
		error("expected primary");
	}
}