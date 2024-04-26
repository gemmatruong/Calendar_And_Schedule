#pragma once
#include "MyScheduleDate.h"

class MyCalendar
{
private:
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;
	unsigned short daysInMonth;
	bool leapYear;
	MyScheduleDate scheduleDays[12][31];

public:
	MyCalendar();

	void setCurrentMonth(int m);
	unsigned short getCurrentMonth() const;

	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);

	void syncWithSys();

	string getMonthName();
	string getDayOfWeek();

	void updateDaysInMonth();
	bool isLeapYear() const;
};

