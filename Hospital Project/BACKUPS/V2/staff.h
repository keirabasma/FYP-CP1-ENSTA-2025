#ifndef STAFF_H
#define STAFF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "details.h"
//#include "systems.h"
//#include "patient.h"
//#include "doctor.h"
//#include "staff.h"

#define ACCOUNT_FILE "accounts.dat"
#define STAFF_FILE "staff.dat"

typedef struct {
    int staffId;
    char password[20];
} StaffAccount;

typedef struct {
    int id;
    char name[50];
    gender gen;
    int age;
    char department[30]; 
    char role[30]; 
    time_hours_mins *shiftStart; 
    time_hours_mins *shiftEnd;
} Staff;

void createAccount();
int login(int staffId, const char* password);
void logout();
int staffIdExists(int id);

void save_staff_data(const char* filename);
void read_staff_data(const char* filename);

#endif