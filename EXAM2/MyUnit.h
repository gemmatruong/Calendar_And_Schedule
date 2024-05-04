#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class MyUnit
{
private:
	unsigned short value;
	char description[100];

public:
	MyUnit();

	void setValue(int newValue);
	int getValue() const;

	void setDescription(string newDescription);
	string getDescription() const;

	friend ostream& operator<<(ostream& out, const MyUnit obj);
};

