#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "doctor.h"
#include "details.h"
#include "processes.h"
#include "systems.h"
// #include "patient.h"

typedef enum { EMERGENCY, NON_CRITICAL } priority;

typedef struct patient {
    int id;
    int doctor_id;
    int nurse_id;
        char full_name[50];
        int age;
        gender gen;
        char illness[200];
    appointment_date date;
    status status;
    priority priority;
    int room;
    int bed;
} patient;

#endif