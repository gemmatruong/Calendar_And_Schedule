#include "MyScheduleDate.h"

MyScheduleDate::MyScheduleDate()
{
	type = 'U';
	description = "unscheduled";
}

void MyScheduleDate::setType(char newType)
{
	type = newType;
}

char MyScheduleDate::getType() const
{
	return type;
}

string MyScheduleDate::getDescription() const {
	return description;  // Return the description
}

void MyScheduleDate::setDescription(const string& desc) {
	description = desc;  // Set the description
}

void MyScheduleDate::clearDescription() {
	description.clear();  // Clear the description
}

void MyScheduleDate::clearDate() {
	type = 'U';  // Reset to undefined or a default 'unassigned' type
	description = "unscheduled";
}


ostream& operator<<(ostream& out, const MyScheduleDate& obj)
{
	string daySuffix;

	switch (obj.getValue())
	{
	case 1: daySuffix = "st"; break;
	case 2: daySuffix = "nd"; break;
	case 3: daySuffix = "rd"; break;
	case 21: daySuffix = "st"; break;
	case 22: daySuffix = "nd"; break;
	case 23: daySuffix = "rd"; break;
	case 31: daySuffix = "st"; break;
	default: daySuffix = "th"; break;
	}
	out << obj.getValue() << daySuffix;
	out << "- " << obj.getDescription();

	return out;
}
