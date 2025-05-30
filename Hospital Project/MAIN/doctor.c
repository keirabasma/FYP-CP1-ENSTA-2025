#include "patient.h"
#include "details.h"
#include "doctor.h"
#include "departments.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

extern doctor_node *doctor_list_head;

doctor_node *add_new_doctor(doctor_node **head)
{
    doctor_node* new_doctor_node = (doctor_node*)malloc(sizeof(doctor_node));
    if (new_doctor_node == NULL)
    {
        printf("There is no space left!");
        return NULL;
    }
    new_doctor_node->dc = (doctor*)malloc(sizeof(doctor));
    if (new_doctor_node->dc == NULL) {
        printf("There is no space left for doctor data!\n");
        free(new_doctor_node);
        return NULL;
    }
    new_doctor_node->next = new_doctor_node->prev = NULL;
    memset(new_doctor_node->dc->schedule, 0, sizeof(new_doctor_node->dc->schedule)); // set shedule to be free

    printf(
    "+------------------------------------------------+\n"
    "|                                                |\n"
    "|       * Please, enter doctor details : *       |\n"
    "|                                                |\n"
    "+------------------------------------------------+\n"
    "                                                  \n"
    "1.> Enter FULL NAME: "
    );
    fgets(new_doctor_node->dc->full_name, sizeof(new_doctor_node->dc->full_name), stdin);
    new_doctor_node->dc->full_name[strcspn(new_doctor_node->dc->full_name, "\n")] = 0;
    capitalize_first_char(new_doctor_node->dc->full_name);

    printf("\n");
    printf("2.> Enter GENDER MALE / FEMALE : ");
    char gender_str[10];
    fgets(gender_str, sizeof(gender_str), stdin);
    gender_str[strcspn(gender_str, "\n")] = 0;
    if (gender_str[0] == 'M' || gender_str[0] == 'm') {
        new_doctor_node->dc->gen = GENDER_MALE;
    } else if (gender_str[0] == 'F' || gender_str[0] == 'f') {
        new_doctor_node->dc->gen = GENDER_FEMALE;
    } else {
        printf("Invalid gender entered. Defaulting to MALE.\n");
        new_doctor_node->dc->gen = GENDER_MALE;
    }

    printf("\n");
    int doctor_ID = generateID() ;
    new_doctor_node->dc->id = doctor_ID;
    printf("3.> Doctor ID is : %d ", doctor_ID);

    printf("\n");
    printf("4.> Enter AGE: ");
    char age_str[10];
    fgets(age_str, sizeof(age_str), stdin);
    new_doctor_node->dc->age = atoi(age_str);

    printf("\n");
    printf(
        "+---------------------------------------------+\n"
        "|                                             |\n"
        "|          * Choose a department : *          |\n"
        "|                                             |\n"
        "+---------------------------------------------+\n"
        "                                               \n"
        "> Departments list : \n"
    );
    display_department_tree(department_root, 0);
    


    new_doctor_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_doctor_node;
    }
    *head = new_doctor_node;
    return *head;
}

void display_free_day_hour(doctor_node *d, week day ,int hour)
{
    if (d->dc->schedule[day][hour] == 0) {
        switch (day) {
            case Saturday:
                printf("Doctor is free on Saturday at %dh\n", hour);
                break;
            case Sunday:
                printf("Doctor is free on Sunday at %dh\n", hour);
                break;
            case Monday:
                printf("Doctor is free on Monday at %dh\n", hour);
                break;
            case Tuesday:
                printf("Doctor is free on Tuesday at %dh\n", hour);
                break;
            case Wednesday:
                printf("Doctor is free on Wednesday at %dh\n", hour);
                break;
            case Thursday:
                printf("Doctor is free on Thursday at %dh\n", hour);
                break;
            case Friday:
                printf("Doctor is free on Friday at %dh\n", hour);
                break;
        }
    }
}

void display_free_hours(doctor_node *d, week day)
{
    for (int hour = 0; hour < 24; ++hour) {
        if (d->dc->schedule[day][hour] == 0) {
            printf("Doctor is free at %dh\n", hour);
        }
    }
}

void display_busy_hours(doctor_node *d, week day)
{
    for (int hour = 0; hour < 24; ++hour) {
        if (d->dc->schedule[day][hour] == 1) {
            printf("Doctor is busy at %dh\n", hour);
        }
    }
}

void display_free_intervals(doctor *d, week day) {
    int start = -1;
    for (int hour = 0; hour <= 24; ++hour) { 
        if (hour < 24 && d->schedule[day][hour] == 0) {
            if (start == -1) start = hour;
        } else {
            if (start != -1) {
                int end = hour - 1;
                printf("Doctor is free from %dh to %dh\n", start, end + 1);
                start = -1;
            }
        }
    }
}

void display_busy_intervals(doctor *d, week day) {
    int start = -1;
    for (int hour = 0; hour <= 24; ++hour) { 
        if (hour < 24 && d->schedule[day][hour] == 1) {
            if (start == -1) start = hour;
        } else {
            if (start != -1) {
                int end = hour - 1;
                printf("Doctor is busy from %dh to %dh\n", start, end + 1);
                start = -1;
            }
        }
    }
}

void display_doctor_schedule(doctor *d) {
    printf("+------------------------------------------------+\n"
           "|                                                |\n");
    printf("|         Schedule for Dr. %-22s|\n", d->full_name);
    printf("|                                                |\n"
           "+------------------------------------------------+\n");

    for (int day = 0; day < 7; ++day) {
        printf("| %-10s:\n", week_days[day]);
        int has_busy = 0, has_free = 0;
        for (int hour = 0; hour < 24; ++hour) {
            if (d->schedule[day][hour])
                has_busy = 1;
            else
                has_free = 1;
        }
        if (!has_busy)
            printf("|     Busy: None\n");
        else {
            printf("|     Busy: ");
            for (int hour = 0; hour < 24; ++hour) {
                if (d->schedule[day][hour])
                    printf("%02dh ", hour);
            }
            printf("\n");
        }
        if (!has_free)
            printf("|     Free: None\n");
        else {
            printf("|     Free: ");
            for (int hour = 0; hour < 24; ++hour) {
                if (!d->schedule[day][hour])
                    printf("%02dh ", hour);
            }
            printf("\n");
        }
    }
    printf("+------------------------------------------------+\n");
}

bool check_doctor_slot(doctor_node *d, week day, int hour){
    if (hour >= 0 && hour < 24) {
        if (d->dc->schedule[day][hour] == 0){
            return true;
        } else {
            return false;
        }
    }
}

void book_doctor_slot(doctor *d, week day, int hour) {
    if (day < Saturday || day > Friday || hour < 0 || hour > 23) {
        return;
    }
    if (d->schedule[day][hour] == 0) {
        d->schedule[day][hour] = 1;
    } else {
        printf("Doctor is busy. Closest free hour: ");
        int found = 0;
        for (int h = hour + 1; h < 24; ++h) {
            if (d->schedule[day][h] == 0) {
                printf("%dh\n", h);
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int h = hour - 1; h >= 0; --h) {
                if (d->schedule[day][h] == 0) {
                    printf("%dh\n", h);
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            printf("No free hours available on this day.\n");
        }
    }
}

void free_doctor_slot(doctor *d, week day, int hour) {
    if (day < Saturday || day > Friday || hour < 0 || hour > 23) return;
    d->schedule[day][hour] = 0;
}



