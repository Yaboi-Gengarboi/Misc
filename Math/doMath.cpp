

#include "doMath.h"

string simpleMath(double a, char op, double b)
{
	double c = 0.0;
	if (op == '+')
		c = a + b;
	else if (op == '-')
		c = a - b;
	else if (op == '*')
		c = a * b;
	else if (op == '/')
		c = a / b;
	else if (op == '^')
		c = pow(a, b);
	return to_string(c);
}