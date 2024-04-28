// Exam 2
//main folder, the main menu of the program will be managed thru this file

//contributors: Armando Orozco, Thi Troung
//test

#include<iostream>
#include <ctime>
#include "declaration.h"
using namespace std;


int main()
{

	
	MyCalendar* calendar = new MyCalendar();
	
	do
	{
		switch (menuOption(calendar))
		{
		case 'X': exit(1); break;
		case 'A': yearSetUp(calendar); break;
		case 'B': monthSetup(); break;
		case 'C': daySetUp(); break;
		case 'D': calendarSetUp(calendar); break;
		case 'E': scheduleAndReport(); break;
		case 'F': calendar->updateToSystemDate(); break;
		case 'G': saveCalendar(); break;
		case 'H': restoreCalendar(); break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;

}


char menuOption(MyCalendar* test)
{
	system("cls");


	cout << "\n\tCurrent year : " << test->getCurrentYear() << " - " << test->yearToWords() << " (" << (test->isLeapYear() ? "leap)" : "non-leap)");
	cout << "\n\t" << string(70, char(196));
	cout << "\n\tCurrent month: " << test->getCurrentMonth() << " - " << test->getMonthName();;
	cout << "\n\tAwareness    : ";
	cout << "\n\t" << string(70, char(196));
	cout << "\n\tCurrent day  : " << test->getCurrentDay() << " - " << test->getDayOfWeek();


	cout << "\n\t" << string(70, char(196));

	cout << "\n\n\tCMPR121: Exam#2 - MyCalendar - OOP implementations Armando Orozco, Thi Truong, add your names (03/05/24)";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\tA. Setting Current Year";
	cout << "\n\tB. Setting Current Month";
	cout << "\n\tC. Setting Current Day";
	cout << "\n\tD. Setting Current Calendar";
	cout << "\n\tE. Schedule and Report Dates";
	cout << "\n\t" << string(70, char(196));
	cout << "\n\tF. Sync to system's date";
	cout << "\n\tG. Save calendar to file";
	cout << "\n\tH. Restore calendar from file";
	cout << "\n\t" << string(70, char(196));
	cout << "\n\tX. Exit";
	cout << "\n\t" << string(70, char(205)) << "\n";

	return toupper(inputChar("\n\tOption: ", "ABCDEFGH"));
}

void yearSetUp(MyCalendar* c)
{

	do
	{
		system("cls");
		cout << "\n\n\tCurrent year: " << c->getCurrentYear()<< " - " << c->yearToWords();
		cout << "\n\t" << string(90, char(205));
		cout << "\n\t1. Set Current Year";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t0. Exit";
		cout << "\n\t" << string(65, char(205)) << "\n";
		switch (inputInteger("\n\tOption: ", 0, 1))
		{
		case 0: return; break;
		case 1:c->setCurrentYear(inputInteger("\n\tSet enter the year (1..9999): ", 1, 9999));  break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

}

void monthSetup()
{
}

void daySetUp()
{

}
void calendarSetUp(MyCalendar* c)
{
	do
	{
		system("cls");
		cout << (*c);
		cout << "\n\n\tMy Calendar Menu";
		cout << "\n\t" << string(65, char(205));
		cout << "\n\t 1. ++ (pre-increment)";
		cout << "\n\t 2. ++ (post-increment)";
		cout << "\n\t 3. jump forward (+n)";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t-1. -- (pre-decrement)";
		cout << "\n\t-2. -- (post-decrement)";
		cout << "\n\t-3. jump backward (-n)";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t0. Exit";
		cout << "\n\t" << string(65, char(205)) << "\n";
		switch (inputInteger("\n\tOption: ", -3, 3))
		{
		case 0: return; break;
		case 1: cout << ++(*c); break;
		case 2: cout << (*c)++; break;
		case 3: break;
		case -1: cout << --(*c); break;
		case -2: cout << (*c)--; break;
		case -3: break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}
void scheduleAndReport()
{

}

void saveCalendar()
{

}
void restoreCalendar()
{

}