#include "MyUnit.h"

MyUnit::MyUnit()
{
	value = 0;
	strncpy_s(description,"unknown", 99);
}

void MyUnit::setValue(int newValue)
{
	value = static_cast<unsigned short>(newValue);
}

int MyUnit::getValue() const
{
	return static_cast<int>(value);
}


void MyUnit::setDescription(string newDescription)
{
	strcpy_s(description, newDescription.c_str());
}

string MyUnit::getDescription() const
{
	return string(description);
}

ostream& operator<<(ostream& out, const MyUnit obj)
{
	out << "value: " << obj.getValue();
	out << "\ndescription: " << obj.getDescription();

	return out;
}


