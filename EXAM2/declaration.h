#pragma once

// in this header file you are going to set the prototypes of the functions you are using, 
// if you see a function that already does what you need, please use it, the main structure for the project is also here

#include "input.h"
#include "MyUnit.h"
#include <ctime>
#include "MyScheduleDate.h"
#include "MyCalendar.h"


char menuOption(MyCalendar*);

void yearSetUp(MyCalendar* c);
void monthSetup(MyCalendar* c);
void daySetUp(MyCalendar* c);
void calendarSetUp(MyCalendar* c);
void scheduleAndReport(MyCalendar* c);
void saveCalendar();
void restoreCalendar();
