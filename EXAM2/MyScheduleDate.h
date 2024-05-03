#pragma once
#include "MyUnit.h"
class MyScheduleDate : public MyUnit
{
private:
	char type;
	string description; //To hold description of the schedule
public:
	MyScheduleDate();

	void setType(char newType);
	char getType() const;

	void setDescription(const string& desc);  // Set the description
	string getDescription() const;            // Get the description
	void clearDescription();                  // Clear the description
	void clearDate();					      // Clears scheduled date

	friend ostream& operator<<(ostream& out, const MyScheduleDate& obj);
};
