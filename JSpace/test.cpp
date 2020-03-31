#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <thread>
using std::thread;
using std::this_thread::sleep_for;

#include <chrono> 
using std::chrono::seconds;

void waitPrint()
{
	sleep_for((seconds)2);
	cout << "Printing from waitPrint." << endl;
}

int main()
{
	thread (waitPrint).detach();

	cout << "Printing from main." << endl;

	sleep_for((seconds)4);

	return 0;
}