#pragma once
#include "MyUnit.h"
class MyScheduleDate : public MyUnit
{
private:
	char type;

public:
	MyScheduleDate();

	void setType(char newType);
	char getType() const;

	friend ostream& operator<<(ostream& out, const MyScheduleDate& obj);
};

