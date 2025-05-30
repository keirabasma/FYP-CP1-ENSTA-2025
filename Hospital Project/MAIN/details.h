#ifndef DETAILS_H
#define DETAILS_H
//#include "processes.h"
//#include "systems.h"
#include "patient.h"
//#include "doctor.h"
//#include "staff.h"


// Represents hours and minutes in a day
// typedef struct { 
//     const int* hour;  // Pointer to shared array for hours
//     const int* min;   // Pointer to shared array for minutes
// } time_hours_mins;

// Declaration of appointment_time as external
// extern const time_hours_mins appointment_time; 

// Enumerations for gender, status, days of the week
typedef enum { GENDER_MALE, GENDER_FEMALE } gender;
typedef enum { WAITING, UNDER_TREATMENT, DISCHARGED } status;
typedef enum { EMERGENCY, NON_CRITICAL } priority;
typedef enum { Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday } week;
extern const char *week_days[];

typedef enum { COMMON_COLD, EAR_INFECTION, FLU, STOMACH_FLU, STREP_THROAT, BRONCHITIS, RSV, HAND_FOOT_MOUTH, CHICKENPOX, PINK_EYE, CUSTOM_ILLNESS_CHILD } child_illness;
typedef enum { PCOS, BREAST_CANCER, OSTEOPOROSIS, ENDOMETRIOSIS, CERVICAL_CANCER, MENSTRUAL_DISORDERS, DEPRESSION_ANXIETY, AUTOIMMUNE_DISEASES, THYROID_DISORDERS, FIBROIDS, CUSTOM_ILLNESS_FEMALE } female_illness;
typedef enum { ALZHEIMERS, ARTHRITIS, HEART_DISEASE_ELDER, DIABETES, OSTEOPOROSIS_ELDERS, HYPERTENSION, PARKINSONS, COPD, CANCER_ELDERS, DEPRESSION_ELDERS, CUSTOM_ILLNESS_ELDER } elder_illness;
typedef enum { HYPERTENSION_MALE, DIABETES_MELLITUS, HEART_DISEASE_MALE, PROSTATE_PROBLEMS, RESPIRATORY_INFECTIONS, DEPRESSION_ANXIETY_MALE, OBESITY, BACK_PAIN, GASTROINTESTINAL_DISORDERS, SKIN_CONDITIONS, CUSTOM_ILLNESS_MALE } male_illness;

extern int valid;

extern char illnessName_men[200];

extern child_illness child_illness_selected;

extern female_illness female_illness_selected;

extern elder_illness elder_illness_selected;

extern male_illness male_illness_selected;

// Structure representing a date with day and time
// typedef struct date { 
//     week day; 
//     time_hours_mins appointment_time;
// } appointment_date;

// extern const char* clinical_depts[];
// extern const char* diagnostic_depts[];
// extern const char* admin_depts[];


// typedef struct deps_node
// {
//     char department_name[50];
//     struct deps_node *next;
// } departments_node;


void set_child_illness_name(child_illness child_illness_selected, char illnessName[]);


void set_female_illness_name(female_illness female_illness_selected, char illnessName[]);


void set_elder_illness_name(elder_illness elder_illness_selected, char illnessName[]);


void set_male_illness_name(male_illness male_illness_selected, char illnessName[]);


void capitalize_first_char(char *str);



#endif