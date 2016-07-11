#include <iostream>
using namespace std;
#include <cstring>

#include "MyString.h"

template <typename T>
void assertEqual(T expected, T actual, const char *message)
{
	if (expected != actual)
	{
		cout << "!!! FAILED !!! - " << message << endl;
		cout << "\t\t expected [" << expected << "] but got [" << actual << "]" << endl;
	}
	else
		cout << "--- PASSED --- - " << message << endl;
}

void assertEqual(const char* expected, const char*  actual, const char *message)
{
	if (strcmp(expected, actual) != 0)
	{
		cout << "!!! FAILED !!! - " << message << endl;
		cout << "\t\t expected [" << expected << "] but got [" << actual << "]" << endl;
	}
	else
		cout << "--- PASSED --- - " << message << endl;
}

void assertTrue(bool expression, const char *message)
{
	if (! expression)
	{
		cout << "!!! FAILED !!! - " << message << endl;
	}
	else
		cout << "--- PASSED --- - " << message << endl;
}


int main()
{
	MyString m;

	assertEqual(16, m.CurrentCapacity(), "Default ctor: sets capacity to 16");
	assertEqual(0, m.Length(), "Default ctor: sets length to 0");
	assertEqual("", m._cstr(), "Default ctor: sets string to empty string");


	m.Assign("Bob");
	cout << "capacity is " << m.CurrentCapacity() << endl;
	cout << "length is " << m.Length() << endl;
	cout << "string points to an ascii " << (m._cstr()) << endl;


	m.Assign("123456789012345678901234567890");

	assertTrue(m.CurrentCapacity() >= 30, "Assign('123456789012345678901234567890': capacity >= 30");
	assertEqual(30, m.Length(), "Assign('123456789012345678901234567890': sets length to 30");
	assertEqual("123456789012345678901234567890", m._cstr(), "Assign('123456789012345678901234567890')");
	char buffer[100] = "";


	cout << m << endl;
	cout << "Enter some text: ";
	cin >> m;
	cout << m << endl;

	MyString m2;
	cout << "Enter some text: ";
	cin >> m2;
	cout << m2 << endl;


	system("pause");
	return 0;
}
