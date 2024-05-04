// Exam 2
//main folder, the main menu of the program will be managed thru this file
//contributors: Armando Orozco, Thi Truong, Christopher Truong
//test

#include "declaration.h"

using namespace std;

int main() {
	MyCalendar* calendar = new MyCalendar();
	do {
		switch (menuOption(calendar)) {
		case 'X': exit(1); break;
		case 'A': yearSetUp(calendar); break;
		case 'B': monthSetup(calendar); break;
		case 'C': daySetUp(calendar); break;
		case 'D': calendarSetUp(calendar); break;
		case 'E': scheduleAndReport(calendar); break;
		case 'F': calendar->updateToSystemDate(); break;
		case 'G': saveCalendar(calendar); break;
		case 'H': restoreCalendar(calendar); break;
		default: cout << "\n\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	delete calendar;

	return EXIT_SUCCESS;

}

char menuOption(MyCalendar* test) {
	system("cls");  // Clear the console screen
	cout << "\n\t" + string(1, char(218)) + string(84, char(196)) + string(1, char(191));
	cout << "\n\t" + string(1, char(179)) + " Current Year : " << "\033[34;1m" << test->getCurrentYear() << " - " << test->yearToWords() << (test->isLeapYear() ? " (leap)" : " (non-leap)") << "\033[0m" << setw(31) << right << string(1, char(179));
	cout << "\n\t" + string(1, char(195)) + string(84, char(196)) + string(1, char(180));
	cout << "\n\t" + string(1, char(179)) + " Current Month: " << "\033[34;1m" << test->getCurrentMonth() << " - " << test->getMonthName() << "\033[0m" << setw(62) << right << string(1, char(179));
	cout << "\n\t" + string(1, char(179)) + " Awareness    : " << "\033[34;1m" << getAwarenessTheme(test->getCurrentMonth()) << "\033[0m" << setw(50) << right << string(1, char(179));
	cout << "\n\t" + string(1, char(195)) + string(84, char(196)) + string(1, char(180));
	cout << "\n\t" + string(1, char(179)) + " Current Day  : " << "\033[34;1m" << test->getCurrentDay() << test->updateDaySuffix() << " - " << test->getDayOfWeek() << "\033[0m" << setw(55) << right << string(1, char(179));
	cout << "\n\t" + string(1, char(179)) << setw(10) << right << "              : " << (test->getSDay(test->getCurrentMonth() - 1, test->getCurrentDay() - 1).getDescription().empty() ? "Unscheduled" : test->getSDay(test->getCurrentMonth() - 1, test->getCurrentDay() - 1).getDescription()) << setw(65) << right << string(1, char(179));

	// Days of the week header with borders as specified
	cout << "\n\t" + string(1, char(195)) + string(11, char(196)) + string(1, char(194)) + string(11, char(196)) + string(1, char(194)) + string(11, char(196)) + string(1, char(194)) + string(11, char(196)) + string(1, char(194)) + string(11, char(196)) + string(1, char(194)) + string(12, char(196)) + string(1, char(194)) + string(11, char(196)) + string(1, char(180));
	cout << "\n\t" + string(1, char(179)) + "  Sunday   " + string(1, char(179)) + "  Monday   " + string(1, char(179)) + "  Tuesday  " + string(1, char(179)) + " Wednesday " + string(1, char(179)) + " Thursday  " + string(1, char(179)) + "   Friday   " + string(1, char(179)) + "  Saturday " + string(1, char(179));
	cout << "\n\t" + string(1, char(195)) + string(11, char(196)) + string(1, char(193)) + string(11, char(196)) + string(1, char(193)) + string(11, char(196)) + string(1, char(193)) + string(11, char(196)) + string(1, char(193)) + string(11, char(196)) + string(1, char(193)) + string(12, char(196)) + string(1, char(193)) + string(11, char(196)) + string(1, char(180));


	int validDays[7][5] = {};
	monthArray(test, validDays);

	for (int i = 0; i < 5; i++) {
		cout << "\n\t" + string(1, char(179));  // Start of the row with the left border
		for (int j = 0; j < 7; j++) {
			if (validDays[j][i] == -1) {
				cout << setw(11) << string(2, char(176));  // Display ░░ for invalid days
			}
			else {
				if (validDays[j][i] == test->getCurrentDay()) {
					// Highlight current day with blue background, ensure alignment
					cout << "\033[44m" << setw(11) << validDays[j][i] << "\033[0m";
				}
				else {
					// Display other days, properly aligned
					cout << setw(11) << validDays[j][i];
				}
			}
		}
		cout << setw(8) << string(1, char(179));  // End of the row with the right border
	}
	cout << "\n\t" + string(1, char(192)) + string(84, char(196)) + string(1, char(217));

	cout << "\n\n\tCMPR121: Exam#2 - MyCalendar - OOP implementations Armando O., Thi T., Christopher T.";
	cout << "\n\t" << string(84, char(205));
	cout << "\n\tA. Setting Current Year";
	cout << "\n\tB. Setting Current Month";
	cout << "\n\tC. Setting Current Day";
	cout << "\n\tD. Setting Current Calendar";
	cout << "\n\tE. Schedule and Report Dates";
	cout << "\n\t" << string(84, char(196));
	cout << "\n\tF. Sync to system's date";
	cout << "\n\tG. Save calendar to file";
	cout << "\n\tH. Restore calendar from file";
	cout << "\n\t" << string(84, char(196));
	cout << "\n\tX. Exit";
	cout << "\n\t" << string(84, char(205)) << "\n";

	return toupper(inputChar("\n\tOption: ", "ABCDEFGH"));
}

void yearSetUp(MyCalendar* c)
{

	do
	{
		system("cls");
		cout << "\n\n\tCurrent year: " << c->getCurrentYear() << " - " << c->yearToWords();
		cout << "\n\n\tSet Current year Menu ";
		cout << "\n\t" << string(65, char(205));
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
		cout << "\n\t" << string(65, char(205));
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
		cout << "\n\t" << string(65, char(205));
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

void scheduleAndReport(MyCalendar* calendar)
{
	struct dayMonth
	{
		int day = 1;
		int month = 1;
	} dayMonth;
	

	dayMonth.day = calendar->getCurrentDay();
	dayMonth.month = calendar->getCurrentMonth();
	MyScheduleDate sDate = calendar->getScheduleDate();

	do {
		system("cls");
		cout << "\n\tmonth       : " << calendar->getMonthName(dayMonth.month);
		cout << "\n\tday         : " << dayMonth.day;
		cout << "\n\ttype        : " << sDate.getType();
		cout << "\n\tdescription : " << sDate.getDescription();  // Placeholder for description

		cout << "\n\n\tScheduling Date";
		cout << "\n\t" << string(65, char(205));
		cout << "\n\t1. Schedule a date";
		cout << "\n\t2. Unschedule a date";
		cout << "\n\t" << string(65, char(196));
		cout << "\n\t3. Display year schedules";
		cout << "\n\t4. Display month schedules";
		cout << "\n\t5. Display day schedule";
		cout << "\n\t0. Return";
		cout << "\n\t" << string(65, char(205));

		switch (inputInteger("\n\tOption: ",0,5)) 
		{
		case 1: //schedule a date
		{
			if (!calendar) {
				cout << "Calendar object is null." << endl;
				return;
			}

			//ask for the day and month
			dayMonth.month = inputInteger("\n\tSpecify a month (1...12): ", 1, 12);
			int maxDays = calendar->getDaysInMonth(dayMonth.month);

			dayMonth.day = inputInteger("\n\tSpecify a day (1.." + to_string(maxDays) + ")", 1, maxDays);

			string description = inputString("\n\tEnter a description: ", true);
			char type = toupper(inputChar("\n\tSpecify a type (R-return, A-Awareness, H-holiday, P-personal): ", static_cast<string>("RAHP")));

			if (type == 'R')
			{
				cout << "\n\tThe date has been NOT scheduled";
				break;
			}

			cout << "\n\t\t";
			sDate = calendar->scheduleDate(dayMonth.day, dayMonth.month, description, type);//set the schedule date, ass well as updating the schedule date variable to 
			cout << "\n";																			//display in the top of the menu
			break;
		}
		case 2: //unschesdule 
		{
			dayMonth.month = inputInteger("\n\tSpecify a month (1...12): ", 1, 12);
			int maxDays = calendar->getDaysInMonth(dayMonth.month);
			dayMonth.day = inputInteger("\n\tSpecify a day (1.." + to_string(maxDays) + ")", 1, maxDays);
			
			sDate = calendar->unscheduleDate(dayMonth.day, dayMonth.month);

			break;
		}
		case 3://year schedules

			for (int month = 1; month <= 12; month++)
			{
				cout << "\n\t"<<calendar->getMonthName(month) << ": ";
				if (calendar->getMonthSchedules(month).empty())
					cout << "No scheduled dates for the month.";
				else
				{
					for (auto& i : calendar->getMonthSchedules(month))
					{
						cout <<"\n\t\t" << i;
					}
				}
				cout << "\n";
			}

			break;
		case 4://month schedules 
		{
			int month = inputInteger("\n\tSpecify a month (1...12): ", 1, 12);
			vector<MyScheduleDate> dates = calendar->getMonthSchedules(month);
			cout << "\n\t" << calendar->getMonthName(month) << ": \n";
			if(dates.empty())
				cout << "No scheduled dates for the month.";
			else
			{
				for (auto& i : dates)
				{
					cout << "\n\t\t" << i;
				}
			}
		}break;
		case 5://day schedule
		{
			int month = inputInteger("\n\tSpecify a month (1...12): ", 1, 12);
			int maxDays = calendar->getDaysInMonth(dayMonth.month);
			int day = inputInteger("\n\tSpecify a day (1.." + to_string(maxDays) + ")", 1, maxDays);

			cout << "\n\t\t" << calendar->getMonthName(month) + ": " << calendar->getScheduleDate(month, day);
			break;
		}
		case 0:
			return;
		default:
			cout << "Invalid option. Please try again.\n";
			break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	calendar->setCurrentMonth(dayMonth.month);
	calendar->setCurrentDay(dayMonth.day);
}

void saveCalendar(MyCalendar* c) 
{
	string filename = to_string(c->getCurrentYear()) + ".dat";

	if (c->saveToFile(filename))
	{
		cout << "\n\n\tSUCCESS: File, " << filename << " has been save.\n";
	}
	else
		cout << "\n\n\tERROR: Cannot save to file!\n";
}

void restoreCalendar(MyCalendar* c) 
{
	string filename = inputString("\n\tEnter a file name: ", false);

	if (c->restoreFromFile(filename))
	{
		cout << "\n\n\tSUCCESS: Restored calendar from " << filename << ".\n";
	}
	else
		cout << "\n\n\tERROR: Cannot save to file!\n";
}

void monthArray(MyCalendar* c, int(&validDay)[7][5])
{
	int day = 1;//set the day count to 1, since its the start day of every mont
	for (int i = 0; i < 5; i++)//iterate trough rows
	{
		for (int j = 0; j < 7; j++)//iterate trough the days of the wee
		{
			if (j == dayOfWeekTest(c, day) && day <= c->getDaysInMonth())// if the day is not in the correct day of the week, go to the next one
			{
				validDay[j][i] = day;//set a flag to know theres a day here
				day++;//try to the next day
			}
			else
				validDay[j][i] = -1;//set a flag that there's not a day of the month in this day of the week
		}
	}
}

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
	int q = dayTest;
	int m = month;
	int k = year % 100;
	int j = year / 100;
	int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	h = h % 7;
	h -= 1;
	if (h == -1)//check getDayOfTheWeek in myCalendar class to see why is this
		return 6;
	return h;

}

string getAwarenessTheme(int month) {
	static const vector<string> themes = {
		"Thyroid Month",  // January
		"Heart Failure Month",      // February
		"Multiple Sclerosis Month", // March
		"Oral Cancer Month",    // April
		"Mental Health Month",     // May
		"Migrane and Headache Month",        // June
		"Juvenile Arthrisis Month", // July
		"Immunization Month",      // August
		"Ovarian Cancer Month",  // September
		"Breast Cancer Month",     // October
		"Lung Cancer Month",  // November
		"HIV Aids Month"   // December
	};
	if (month < 1 || month > 12) {
		return "Unknown Awareness Month"; // Safety check for invalid month
	}
	return themes[month - 1];
}
