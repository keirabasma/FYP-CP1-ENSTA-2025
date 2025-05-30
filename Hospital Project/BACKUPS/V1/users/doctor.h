#ifndef DOCTOR_H
#define DOCTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "processes.h"
#include "systems.h"
#include "patient.h" 
/* #include "doctor.h" */

typedef struct doctor {
    int doctor_id;
    char name[50];
    gender gen;
    int age;
    char department[30];
    int schedule;
} doctor;

#define doctor doctor;


#endif