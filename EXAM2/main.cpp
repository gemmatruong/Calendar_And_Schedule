// Exam 2
//main folder, the main menu of the program will be managed thru this file

//contributors: Armando Orozco, Thi Troung


#include<iostream>
#include <ctime>
#include "declaration.h"
using namespace std;


void sysTime(MyCalendar& c) {
	time_t rawtime = time(0);
	tm timeinfo;
	localtime_s(&timeinfo, &rawtime); // Convert to local time

	// Print today's date
	cout << "Today's date: " << (timeinfo.tm_mon + 1) << '/' << timeinfo.tm_mday << '/' << (timeinfo.tm_year + 1900) << std::endl;
	
}

int main()
{

	
	MyCalendar* calendar = nullptr;
	do
	{
		switch (menuOption())
		{
		case 'X': exit(1); break;
		case 'A': yearSetUp(); break;
		case 'B': monthSetup(); break;
		case 'C': daySetUp(); break;
		case 'D': calendarSetUp(); break;
		case 'E': scheduleAndReport(); break;
		case 'F': syncSystemDate(); break;
		case 'G': saveCalendar(); break;
		case 'H': restoreCalendar(); break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;

}


char menuOption()
{
	system("cls");

	MyCalendar test;

	cout << "\n\tCurrent year : " << test.getCurrentYear() << " (" << (test.isLeapYear() ? "leap)" : "non-leap)");
	cout << "\n\t" << string(60, char(196));
	cout << "\n\tCurrent month: " << test.getCurrentMonth() << " - " << test.getMonthName();;
	cout << "\n\tAwareness    : ";
	cout << "\n\t" << string(65, char(196));
	cout << "\n\tCurrent day  : " << test.getCurrentDay() << " - " << test.getDayOfWeek();

	cout << "\n\t" << string(65, char(196));




	cout << "\n\n\tCMPR121: Exam#2 - MyCalendar - OOP implementations Armando Orozco, Thi Truong, add your names (03/05/24)";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\tA. Setting Current Year";
	cout << "\n\tB. Setting Current Month";
	cout << "\n\tC. Setting Current Day";
	cout << "\n\tD. Setting Current Calendar";
	cout << "\n\tE. Schedule and Report Dates";
	cout << "\n\t" << string(65, char(196));
	cout << "\n\tF. Sync to system's date";
	cout << "\n\tG. Save calendar to file";
	cout << "\n\tH. Restore calendar from file";
	cout << "\n\t" << string(65, char(196));
	cout << "\n\tX. Exit";
	cout << "\n\t" << string(65, char(205)) << "\n";

	return toupper(inputChar("\n\tOption: ", "ABCDEFGH"));
}



void yearSetUp()
{

}

void monthSetup()
{
}

void daySetUp()
{

}
void calendarSetUp()
{

}
void scheduleAndReport()
{

}
void syncSystemDate()
{

}
void saveCalendar()
{

}
void restoreCalendar()
{

}