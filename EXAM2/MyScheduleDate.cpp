#include "MyScheduleDate.h"

MyScheduleDate::MyScheduleDate()
{
	type = 'U';
}

void MyScheduleDate::setType(char newType)
{
	type = newType;
}

char MyScheduleDate::getType() const
{
	return type;
}

ostream& operator<<(ostream& out, const MyScheduleDate& obj)
{
	out << "value: " << obj.getValue();
	out << "\ndescription: " << obj.getDescription();
	out << "\ntype: " << obj.getType();

	return out;
}
