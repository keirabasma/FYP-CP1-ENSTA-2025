#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
//#include "processes.h"
//#include "systems.h"
//#include "patient.h"
//#include "doctor.h"
//#include "staff.h"

// Function declarations
void mainMenu();
void patientManagementMenu();
void doctorManagementMenu();
void staffManagementMenu();
void appointmentMenu();
void reportsStatusMenu();
void systemSettingsMenu();


extern int loggedInStaffId;


#endif