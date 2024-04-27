#include "MyCalendar.h"


MyCalendar::MyCalendar()
{

    int* date = getSystemDate();

	currentMonth = date[0];
	currentDay = date[1];
    currentYear = date[2];
	leapYear = isLeapYear();
	//for (int m = 0; m < 12; m++)
	//	for (int d = 0; d < 31; d++)
	//		scheduleDays[m][d].setValue(d + 1);
}

void MyCalendar::setCurrentYear(int y)
{
    currentYear = y;
    leapYear = isLeapYear();
    updateDaysInMonth();
    return;
}

unsigned short MyCalendar::getCurrentYear() const
{
    return currentYear;
}

void MyCalendar::setCurrentMonth(int m)
{
	 if (m > 12)
    {
        setYear(currentYear + 1);
        currentMonth = 1;
    }
    else if (m < 1)
    {
        setYear(currentYear - 1);
        currentMonth = 12;
    }
    else
        currentMonth = m;
    updateDaysInMonth();

    return;
}

unsigned short MyCalendar::getCurrentMonth() const
{
	return currentMonth;
}


void MyCalendar::setCurrentDay(int d)
{
     if (d > daysInMonth)
    {
        currentDay = 1;
        setMonth(currentMonth + 1);
    }else if (d < 1)
    {
        setMonth(currentMonth - 1);
        currentDay = daysInMonth;
    }
    else
    {
        currentDay = d;
    }
    return;
}

unsigned short MyCalendar::getCurrentDay() const
{
    return currentDay;
}

string  MyCalendar::getMonthName()
{
	const string months[13] = { "unknown", "January", "February", "March" , "April", "May", "June", "July", "August", "September", "October" ,"November", "December" };

	if (currentMonth >= 1 && currentMonth <= 12)
		return months[currentMonth];
	else
		return months[0];
	
}

string MyCalendar::getDayOfWeek()
{
    int month = currentMonth;
    int year = currentYear;
    int day = currentDay;

    if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h
        = q + 13 * (m + 1) / 5 + k + k / 4 +
        j / 4 + 5 * j;
    h = h % 7;
    switch (h) {
    case 0:
        return "Saturday";
        break;
    case 1:
        return "Sunday";
        break;
    case 2:
        return "Monday";
        break;
    case 3:
        return "Tuesday";
        break;
    case 4:
        return "Wednesday";
        break;
    case 5:
        return "Thursday";
        break;
    case 6:
        return "Friday";
        break;
    }
    return "unknown";

}

bool MyCalendar::isLeapYear() const
{
    return (currentYear % 400 == 0) || (currentYear % 100 != 0) && (currentYear % 4 == 0);
}


// Precondition: NA
// Postcondition: return an array of integers holding month, day, year of the system date
int* MyCalendar::getSystemDate() const
{
    int date[3];

    // Get current time
    time_t t = time(nullptr);

    // initialize a tm structure which is used to break down time object into month, day, year, etc.
    tm today;

    // localtime_s() function is called to convert time value to a structure of tm
    localtime_s(&today, &t);

    date[0] = today.tm_mon + 1;		// tm structure uses 0 for January and so on
    date[1] = today.tm_mday;
    date[2] = today.tm_year + 1900;	// tm structure uses year from 1900

    return date;
}

void MyCalendar::updateDaysInMonth()
{
    int month = currentMonth;
    int year = currentYear;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth= 30; // Months with 30 days
    }
    else if (month == 2) {
        if (leapYear) {
            daysInMonth = 29; // February in a leap year
        }
        else {
            daysInMonth = 28; // February in a non-leap year
        }
    }
    else {
        daysInMonth = 31; // Months with 31 days
    }
}
