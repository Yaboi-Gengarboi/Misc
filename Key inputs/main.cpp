#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

char getOperator(string line)
{
	char op = ' ';
	//[+][-][*][/][^][%][!][(][)] locations
	int operators[8];
	operators[0] == line.find('+');
	operators[1] == line.find('-');
	operators[2] == line.find('*');
	operators[2] == line.find('/');
	operators[3] == line.find('^');
	operators[4] == line.find('%');
	operators[5] == line.find('!');
	operators[6] == line.find('(');
	operators[7] == line.find(')');

	int opsFound = 0;
	for (int i = 0; i < 8; i++)
	{
		if (operators[i] != -1)
			opsFound++;
	}
		


	return op;
}

double doMath(string line)
{
	double ans = 0;
	return ans;
}

int main()
{
	string line = "";
	cout << "Enter line." << endl;
	cin >> line;
	getOperator(line);
	return 0;
}