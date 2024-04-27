#pragma once

// in this header file you are going to set the prototypes of the functions you are using, 
// if you see a function that already does what you need, please use it, the main structure for the project is also here

#include "input.h"
#include "MyUnit.h"
#include "MyScheduleDate.h"
#include "MyCalendar.h"

char menuOption();

void yearSetUp();
void monthSetup();
void daySetUp();
void calendarSetUp();
void scheduleAndReport();
void syncSystemDate();
void saveCalendar();
void restoreCalendar();