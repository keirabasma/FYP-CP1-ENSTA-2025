#ifndef DOCTOR_H
#define DOCTOR_H

#include <stdbool.h>

typedef struct doctor {
    int id;
    char full_name[50];
    gender gen;
    int age;
    char department[30];
    bool schedule[7][24];
} doctor;

// All doctors list
typedef struct dc_node
{
    doctor *dc;
    struct doctor_node *next;
    struct doctor_node *prev;
} doctor_node;


void display_free_day_hour(doctor_node *d, week day ,int time);
void display_free_hours(doctor_node *d, week day);

void display_busy_hours(doctor_node *d, week day);

bool check_doctor_slot(doctor_node *d, week day, int hour);

void book_doctor_slot(doctor *d, week day, int hour);
void free_doctor_slot(doctor *d, week day, int hour);
void display_doctor_schedule(doctor *d);
void display_free_intervals(doctor *d, week day);
void display_busy_intervals(doctor *d, week day);


#endif