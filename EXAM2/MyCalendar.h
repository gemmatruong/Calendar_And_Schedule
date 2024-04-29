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


	void setCurrentYear(int y);
	unsigned short getCurrentYear() const;

	void setCurrentDay(int m);
	unsigned short getCurrentDay() const;

	unsigned short getDaysInMonth() const;

	string yearToWords() const;

	string getMonthName() const;
	string getDayOfWeek() const;
	int* getSystemDate() const;
	int updateDaysInMonth();

	bool isLeapYear() const;

	MyCalendar operator++();				// prefix(++)
	MyCalendar operator++(int);				// postfix(++)
	MyCalendar operator--();				// prefix(--)
	MyCalendar operator--(int);				// postfix(--)
	void jumpForward(int);			// jump forward a number of days
	void jumpBackward(int);			// jump forward a number of days

	string updateDaySuffix() const;


	friend ostream& operator<<(ostream& out, const MyCalendar& obj);

	void updateToSystemDate();

};

