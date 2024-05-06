#pragma once

// in this header file you are going to set the prototypes of the functions you are using, 
// if you see a function that already does what you need, please use it, the main structure for the project is also here
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "input.h"
#include "MyUnit.h"
#include "MyScheduleDate.h"
#include "MyCalendar.h"
#include <string>
#include <cstdlib>
#include <cctype>

// ANSI escape sequences for text color formatting
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char menuOption(MyCalendar*);

void monthArray(MyCalendar* c, int(&validDay)[7][5]);
int dayOfWeekTest(MyCalendar* c, int dayTest);
string getAwarenessTheme(int month);
void yearSetUp(MyCalendar* c);
void monthSetup(MyCalendar* c);
void daySetUp(MyCalendar* c);
void calendarSetUp(MyCalendar* c);
void scheduleAndReport(MyCalendar* c);
void saveCalendar(MyCalendar* c);
void restoreCalendar(MyCalendar* c);
