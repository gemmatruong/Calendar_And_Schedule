#pragma once
#include "MyScheduleDate.h"

class MyCalendar
{
private:
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;
	//MyScheduleDate scheduleDays[12][31];

public:
	MyCalendar();

	void setCurrentMonth(int m);
	unsigned short getCurrentMonth() const;

	string getMonthName();

	string getDayOfWeek();

	bool isLeapYear() const;

};

