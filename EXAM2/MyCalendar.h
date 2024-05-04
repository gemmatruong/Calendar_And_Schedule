#pragma once
#include "MyScheduleDate.h"
#include <fstream>
#include<vector>


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

	MyScheduleDate getSDay(int m, int d);
	unsigned short getDaysInMonth() const;
	unsigned short getDaysInMonth(int month) const;

	string yearToWords() const;
	string getMonthName() const;
	string getMonthName(int month) const;
	string getDayOfWeek() const;
	string updateDaySuffix() const;
	int* getSystemDate() const;
	int updateDaysInMonth();

	bool isLeapYear() const;

	MyCalendar operator++();				// prefix(++)
	MyCalendar operator++(int);				// postfix(++)
	MyCalendar operator--();				// prefix(--)
	MyCalendar operator--(int);				// postfix(--)
	void jumpForward(int);			// jump forward a number of days
	void jumpBackward(int);			// jump forward a number of days


	MyScheduleDate scheduleDate(int day, int month, const std::string& description, char type); //schedule a date by given month an day
	MyScheduleDate unscheduleDate(int day, int month);	//clears the given date

	MyScheduleDate getScheduleDate(int month, int day) const;
	std::vector<MyScheduleDate> getMonthSchedules(int month) const;

	MyScheduleDate& getScheduleDate(); //int month, int day New function to access specific schedule dates
	void updateToSystemDate();

	bool saveToFile(string& filename);		// Function to save data to a binary file

	bool restoreFromFile(string& filename);	// Function to restore data from a file

	friend ostream& operator<<(ostream& out, const MyCalendar& obj);


};
