
// Exam 2
//main folder, the main menu of the program will be managed thru this file

//contributors: Armando Orozco, Thi Troung
//test

#include "declaration.h"


using namespace std;

int dayOfWeekTest(MyCalendar* c, int dayTest) {
	int month = c->getCurrentMonth();
	int year = c->getCurrentYear();
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
	if (h == -1)
		return 6;
	return h;
}

void monthArray(MyCalendar* c, int(&validDay)[7][5]) {
	int day = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (j == dayOfWeekTest(c, day) && day <= c->getDaysInMonth()) {
				validDay[j][i] = day;
				day++;
			}
			else {
				validDay[j][i] = -1;
			}
		}
	}
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

	return EXIT_SUCCESS;
}

char menuOption(MyCalendar* test) {
    system("cls");
    cout << "\n\tCurrent year : ";
    cout << "\033[34;1m" << test->getCurrentYear() << " - " << test->yearToWords() << (test->isLeapYear() ? " (leap)" : " (non-leap)") << "\033[0m";
    cout << "\n\t" << string(70, char(196));
    cout << "\n\tCurrent month: ";
    cout << "\033[34;1m" << test->getCurrentMonth() << " - " << test->getMonthName() << "\033[0m";
    cout << "\n\tAwareness    : ";
    cout << "\033[34;1m" << getAwarenessTheme(test->getCurrentMonth()) << "\033[0m";
    cout << "\n\t" << string(70, char(196));
    cout << "\n\tCurrent day  : ";
    cout << "\033[34;1m" << test->getCurrentDay() << test->updateDaySuffix() << " - " << test->getDayOfWeek() << "\033[0m";
	cout << "\n\t             : unschedule";

    cout << "\n\n\t\t  Sunday   |  Monday   |  Tuesday  | Wednesday | Thursday  |   Friday  |  Saturday \n";

    int validDays[7][5] = {};
    monthArray(test, validDays);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "\t\t";
            if (validDays[j][i] == -1) {
                cout << "░░";  // Display ?? for invalid days
            }
            else if (validDays[j][i] == test->getCurrentDay()) {
                cout << "\033[44m" << setw(2) << validDays[j][i] << "\033[0m";  // Highlight current day with blue background
            }
            else {
                cout << setw(2) << validDays[j][i];
            }
            if (j < 6) cout << " | ";
        }
        cout << "\n";
    }

    cout << "\n\t" << string(70, char(196));
    cout << "\n\n\tCMPR121: Exam#2 - MyCalendar - OOP implementations Armando O., Thi T., Christopher T. (add your names)";
    cout << "\n\t" << string(65, char(205));
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
	system("cls");
	int option;
	do {
		cout << "\n\tmonth       : " << calendar->getMonthName();
		cout << "\n\tday         : " << calendar->getCurrentDay();
		cout << "\n\ttype        : U";  // Assuming 'U' stands for unscheduled
		cout << "\n\tdescription : unschedule";  // Placeholder for description

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
		cout << "\n\tOption: ";
		cin >> option;

		switch (option) {
		case 1: {
			if (!calendar) {
				cout << "Calendar object is null." << endl;
				return;
			}

			int month, day;
			string description;
			char type;

			cout << "\n\tSpecify a month (1...12): ";
			cin >> month;
			cout << "\n\tSpecify a day (1..30): ";
			cin >> day;
			cin.ignore();  // Clear buffer after reading a number

			cout << "\n\tEnter a description: ";
			getline(cin, description);

			cout << "\n\tSpecify a type (R-return, A-Awareness, H-holiday, P-personal): ";
			cin >> type;
			type = toupper(type);

			if (type != 'R' && type != 'A' && type != 'H' && type != 'P') {
				cout << "Invalid type. Please enter one of R, A, H, or P." << endl;
				return;
			}

			if (month >= 1 && month <= 12 && day >= 1 && day <= 30) {
				MyScheduleDate& date = calendar->getScheduleDate(month, day);
				date.setDescription(description);
				date.setType(type);

				cout << "\n\tSuccess: Date has been successfully scheduled." << endl;
			}
			else {
				cout << "\n\tDate has NOT been scheduled or rescheduled." << endl;
			}
			system("pause");
			break;
		}
		case 2: {
			int month, day;
			cout << "\n\tSpecify a month (1...12): ";
			cin >> month;
			cout << "\n\tSpecify a day (1..30): ";
			cin >> day;
			if (month >= 1 && month <= 12 && day >= 1 && day <= 30) { // Simplified validation
				MyScheduleDate& date = calendar->getScheduleDate(month, day);
				date.clearDate();  // Clear the scheduled date
				cout << "\n\tSUCCESS: Date has successfully been unscheduled.\n";
			}
			else {
				cout << "\n\tDate has NOT been scheduled or rescheduled." << endl;
			}
			system("pause");
			break;
		}
		case 3:
			calendar->displayYearSchedules();
			break;
		case 4:
			calendar->displayMonthSchedules();
			break;
		case 5:
			calendar->displayDaySchedule();
			break;
		case 0:
			return;
		default:
			cout << "Invalid option. Please try again.\n";
			break;
		}
	} while (option != 0);
}

void saveCalendar(MyCalendar* calendar)
{
	if (calendar == nullptr) {
		cout << "Error: Calendar object is null." << endl;
		return;
	}

	string filename = inputString("Enter filename to save the calendar (default: calendar_data.txt): ", true);
	if (filename.empty()) {
		filename = "calendar_data.txt";  // Default filename if nothing is entered
	}

	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Failed to open file for writing." << endl;
		return;
	}

	// Write basic calendar information
	file << "Year: " << calendar->getCurrentYear() << endl;
	file << "Month: " << calendar->getCurrentMonth() << endl;
	file << "Day: " << calendar->getCurrentDay() << endl;

	// Iterate over all months and days to serialize scheduled dates
	for (int m = 1; m <= 12; ++m) {  // Assuming months are 1-indexed
		for (int d = 1; d <= calendar->getDaysInMonth(); ++d) {  // Assuming `getDaysInMonth()` returns the correct days count for each month
			MyScheduleDate& date = calendar->getScheduleDate(m, d);
			if (!date.getDescription().empty()) {  // Only serialize days with a description
				file << "Date: " << m << "/" << d << " - "
					<< "Type: " << date.getType() << " - "
					<< "Description: " << date.getDescription() << endl;
			}
		}
	}

	file.close();
	cout << "Calendar has been successfully saved to '" << filename << "'." << endl;
}

void restoreCalendar(MyCalendar* calendar)
{
	if (calendar == nullptr) {
		cout << "Error: Calendar object is null." << endl;
		return;
	}

	string filename = inputString("Enter filename to load the calendar from (default: calendar_data.txt): ", true);
	if (filename.empty()) {
		filename = "calendar_data.txt";  // Default filename if nothing is entered
	}

	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Failed to open file for reading." << endl;
		return;
	}
	string line;
	while (getline(file, line)) {
		size_t pos = line.find(':');
		if (pos == string::npos) continue; // Skip if no colon found

		string key = trim(line.substr(0, pos));
		string value = trim(line.substr(pos + 1));

		if (key == "Year") {
			calendar->setCurrentYear(stoi(value));
		}
		else if (key == "Month") {
			calendar->setCurrentMonth(stoi(value));
		}
		else if (key == "Day") {
			calendar->setCurrentDay(stoi(value));
		}
		else if (key == "Date") {
			size_t dashPos = value.find('-');
			if (dashPos == string::npos) continue; // Skip if no dash found

			string datePart = trim(value.substr(0, dashPos));
			size_t slashPos = datePart.find('/');
			if (slashPos == string::npos) continue; // Skip if no slash found

			int month = stoi(trim(datePart.substr(0, slashPos)));
			int day = stoi(trim(datePart.substr(slashPos + 1)));

			size_t typePos = value.find("Type: ", dashPos + 1);
			if (typePos == string::npos) continue; // Skip if no "Type: " found

			size_t descPos = value.find(" - ", typePos + 6);
			if (descPos == string::npos) continue; // Skip if no " - " found

			char type = trim(value.substr(typePos + 6, descPos - (typePos + 6)))[0];
			string description = trim(value.substr(descPos + 3));

			// Set the schedule
			MyScheduleDate& scheduleDate = calendar->getScheduleDate(month, day);
			scheduleDate.setDescription(description);
			scheduleDate.setType(type);
		}
	}

	file.close();
	cout << "Calendar has been successfully restored from '" << filename << "'." << endl;

}
