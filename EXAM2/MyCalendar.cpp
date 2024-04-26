#include "MyCalendar.h"


MyCalendar::MyCalendar()
{
	currentYear = 1999;
	currentMonth = 1;
	currentDay = 1;
	
	//for (int m = 0; m < 12; m++)
	//	for (int d = 0; d < 31; d++)
	//		scheduleDays[m][d].setValue(d + 1);
}


void MyCalendar::setCurrentMonth(int m)
{
	currentMonth = static_cast<unsigned short>(m);
}

unsigned short MyCalendar::getCurrentMonth() const
{
	return currentMonth;
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