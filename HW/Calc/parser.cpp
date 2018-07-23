#include "std_lib_facilities.h"
#include "tokens.h"
#include "parser.h"
#include "vars.h"

double Statement(Token_Stream& ts){
	/*

	Accepted:
	- Name = Expression
	- Name;
	*/

	Token left = ts.get();
	if(left.kind == name){
		Token checker = ts.get();
		if(checker.kind == '='){
			double d = Expression(ts);
			setValue(left.name, d);
			return getValue(left.name);
		}else if(checker.kind == print){
			ts.putback(checker);
			return getValue(left.name);
		}
		ts.putback(checker);
		ts.putback(left);
		return Expression(ts);
	}else{
		ts.putback(left);
		return Expression(ts);
	}
}

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

	double left = Expon(ts);
	Token t = ts.get();

	while(true){
		switch(t.kind){
		case '*':
			left *= Expon(ts);
			t = ts.get();
			break;
		case '/':
			{
				double d = Expon(ts);
				if(d == 0) error("Dividing by 0!");
				left /= d;
				t = ts.get();
				break;
			}
		case '%':
			{
				double d = Expon(ts);
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

double Expon(Token_Stream& ts){
	double left = Primary(ts);
	Token t = ts.get();
	if(t.kind == power){
		double d = Primary(ts);
		return pow(left, d);
	}else{
		ts.putback(t);
		return left;
	}
}

double Primary(Token_Stream& ts){
	Token t = ts.get();
	switch (t.kind){
	case '(':
		{
			double d = Statement(ts);
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
	case name:
		return getValue(t.name);
	default:
		error("expected primary");
		return 0.0;
	}
}