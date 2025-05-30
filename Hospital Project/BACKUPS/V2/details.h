#ifndef DETAILS_H
#define DETAILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
//#include "processes.h"
//#include "systems.h"
#include "patient.h"
//#include "doctor.h"
//#include "staff.h"


// Represents hours and minutes in a day
typedef struct { 
    const int* hour;  // Pointer to shared array for hours
    const int* min;   // Pointer to shared array for minutes
} time_hours_mins;

typedef enum { GENDER_MALE, GENDER_FEMALE } gender;

// Declaration of appointment_time as external
extern const time_hours_mins appointment_time; 

// Enumerations for gender, status, and days of the week
typedef enum { GENDER_MALE, GENDER_FEMALE } gender;
typedef enum { WAITING, UNDER_TREATMENT, DISCHARGED } status;
typedef enum { EMERGENCY, NON_CRITICAL } priority;
typedef enum week { Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday } week;

// Structure representing a date with day and time
typedef struct date { 
    week day; 
    time_hours_mins appointment_time;
} appointment_date;

extern const char* clinical_depts[];
extern const char* diagnostic_depts[];
extern const char* admin_depts[];

#endif