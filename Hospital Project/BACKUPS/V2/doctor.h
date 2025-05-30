#ifndef DOCTOR_H
#define DOCTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "patient.h" 

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