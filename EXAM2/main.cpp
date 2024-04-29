// Exam 2
//main folder, the main menu of the program will be managed thru this file

//contributors: Armando Orozco, Thi Troung
//test

#include<iostream>
#include <ctime>
#include "declaration.h"
using namespace std;

int dayOfWeekTest(MyCalendar* c, int dayTest)
{
	int month = c->getCurrentMonth();
	int year = c->getCurrentYear();
	int day = dayTest;

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

	h -= 1;

	if (h == -1)//check getDayOfTheWeek in myCalendar class to see why is this
		return 6;
	return h;
}
void monthArray(MyCalendar* c, int(&validDay)[7][5]);

void monthArray(MyCalendar* c, int(&validDay)[7][5])
{
	int day = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j == dayOfWeekTest(c, day) && day <= c->getDaysInMonth())
			{
				validDay[j][i] = day;
				day++;
			}
			else
				validDay[j][i] = -1;
		}
	}
}

int main()
{

	
	MyCalendar* calendar = new MyCalendar();
	
	do
	{
		switch (menuOption(calendar))
		{
		case 'X': exit(1); break;
		case 'A': yearSetUp(calendar); break;
		case 'B': monthSetup(calendar); break;
		case 'C': daySetUp(calendar); break;
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
	cout << "\n\tCurrent day  : " << test->getCurrentDay() << test->updateDaySuffix() << " - " << test->getDayOfWeek();

	cout << "\n\n\t\t  Sunday   |  Monday   |  Tuesday  | Wednesday | Thursday  |   Friday  |  Saturday \n";

	int validDays[7][5] = {};
	monthArray(test, validDays);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << "\t\t" << validDays[j][i];
		}
		cout << "\n";
	}


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
		cout << "\n\n\tSet Current year Menu ";
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

void monthSetup(MyCalendar* c)
{
	do
	{
		system("cls");
		cout << "\n\n\tCurrent Month: " << c->getCurrentMonth() << " " + c->getMonthName();
		cout << "\n\n\tCalendar - Current Month Menu ";
		cout << "\n\t" << string(90, char(205));
		cout << "\n\t1. Set Current Month";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t0. Exit";
		cout << "\n\t" << string(65, char(205)) << "\n";
		switch (inputInteger("\n\tOption: ", 0, 1))
		{
		case 0: return; break;
		case 1:c->setCurrentMonth(inputInteger("\n\tSet enter the Month (1..12): ", 1, 12));  break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

}

void daySetUp(MyCalendar* c)
{
	do
	{
		system("cls");
		cout << "\n\n\tCurrent Day: " << c->getCurrentDay() << c->updateDaySuffix();
		cout << "\n\n\tSet Current Day Menu";
		cout << "\n\t" << string(90, char(205));
		cout << "\n\t1. Set Current Day";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t0. Exit";
		cout << "\n\t" << string(65, char(205)) << "\n";
		switch (inputInteger("\n\tOption: ", 0, 1))
		{
		case 0: return; break;
		case 1:c->setCurrentDay(inputInteger("\n\tSet enter the Day (1..." + to_string(int(c->getDaysInMonth())) + "): ", 1, c->getDaysInMonth()));  break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

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
		case 1:
		{
			cout << "\n\tpre - increment:(++)\n";
			cout << ++(*c);
			cout << "\n";
		}
		break;
		case 2: 
		{
			cout << "\n\tpost - increment:(++)\n";
			cout << (*c)++;
			cout << "\n";
		}
		break;
		case 3: 
		{
			int n = inputInteger("\n\tEnter an integer (n): ", true);
			c->jumpForward(n);
			cout << "\n\tjump forward(" << n << ")...\n";
		}
		break;
		case -1:
		{
			cout << "\n\tpre - decrement:(++)\n";
			cout << --(*c);
			cout << "\n";
		}
		break;
		case -2: 
		{
			cout << "\n\tpost - increment:(++)\n";
			cout << (*c)--;
			cout << "\n";
		}
		break;
		case -3: 
		{
			int n = inputInteger("\n\tEnter an integer (n): ", true);
			c->jumpBackward(n);
			cout << "\n\tjump backward(" << n << ")...\n";
		}
		break;
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
