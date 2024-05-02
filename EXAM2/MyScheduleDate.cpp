#include "MyScheduleDate.h"

MyScheduleDate::MyScheduleDate()
{
	type = 'U';
	description = "none";
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
	description.clear();
}


ostream& operator<<(ostream& out, const MyScheduleDate& obj)
{
	out << "value: " << obj.getValue();
	out << "\ndescription: " << obj.getDescription();
	out << "\ntype: " << obj.getType();

	return out;
}
