// Exam 2
//main folder, the main menu of the program will be managed thru this file
//contributors: Armando Orozco,

#include<iostream>
#include "declaration.h"
using namespace std;

int main()
{
	MyCalendar test;
	test.setCurrentMonth(inputInteger("\nEnter a month number (1...12): ", 1,12));

	cout << test.getCurrentMonth() << ": " << test.getMonthName() << "\n";

	cout << test.getDayOfWeek() << '\n';

	cout << test.isLeapYear();



	return 0;
}

