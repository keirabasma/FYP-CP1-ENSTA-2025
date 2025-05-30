#ifndef DAILY_SCHEDULE_H
#define DAILY_SCHEDULE_H

#define MAX_HOURS 24 
#define MAX_DOCTORS 10

//Structure contains the daily schedule
typedef struct daily_sched
{
    char schedule[MAX_HOURS][MAX_DOCTORS][50];
}daily_sched;

void init_schedule(daily_sched *d_s);
void add_appointment(daily_sched *d_s, int hour, int doctor_indx, char *doctor_name);
void view_schedule(daily_sched *d_s);
void delete_appointment(daily_sched *d_s, int hour, int doctor_indx);

#endif