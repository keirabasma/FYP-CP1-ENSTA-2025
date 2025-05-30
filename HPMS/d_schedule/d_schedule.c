#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "d_schedule.h"
#include "doctor/doctor.h"

//Function to initialize the daily schedule
void init_schedule(daily_sched *d_s)
{
    for(int i = 0; i < MAX_HOURS; i++)
    {
        for(int j = 0; j < MAX_DOCTORS; j++)
        {
            strcpy(d_s->schedule[i][j], ""); //Copy an empty string to schedule
        }
    }
}

//Function to add an appointment
void add_appointment(daily_sched *d_s, int hour, int doctor_indx, char *doctor_name)
{
    //check if hour & doctor index are valid
    if(hour >= 0 && hour < MAX_HOURS && doctor_indx >= 0 && doctor_indx < MAX_DOCTORS)
    {
        strcpy(d_s->schedule[hour][doctor_indx], doctor_name); //Copy the name of the doctor in the hour and doctor index
    }
    else
    {
        printf("Wrong hour or doctor index! \n");
    }
}

//Function to show the daily schedule
void view_schedule(daily_sched *d_s)
{
    printf("Daily schedule \n");
    for(int i = 0; i < MAX_HOURS; i++)
    {
        printf("%02d:00 - ", i);
        for(int j = 0; j < MAX_DOCTORS; j++)
        {
            //Check if doctor name is not empty
            if(strlen(d_s->schedule[i][j]) > 0)
            {
                printf("%s", d_s->schedule[i][j]);
            }
            else
            {
                printf("Free"); //If no appointment scheduled
            }
            if(j < MAX_DOCTORS - 1)
                printf(", ");
        }
        printf("\n");
    }
}

//FUnction to delete an appointment
void delete_appointment(daily_sched *d_s, int hour, int doctor_indx)
{
    //check if hour & doctor index are valid
    if(hour >= 0 && hour < MAX_HOURS && doctor_indx >= 0 && doctor_indx < MAX_DOCTORS)
    {
        //Copy an empty string to schedule to clear appointment
        strcpy(d_s->schedule[hour][doctor_indx], "");
    }
    else
    {
        printf("Wrong hour or doctor index! \n");
    }
}