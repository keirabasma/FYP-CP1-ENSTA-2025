#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 1000

//Enumerator for the patient status
typedef enum {waiting, under_treatment, discharged} patient_status;

//Structure contains all the patient information
typedef struct
{
    int id;
    char name[50];
    int age;
    char gender; //'F' for female & 'M' for male
    char bld_grp[10]; //blood group
    char address[50];
    char email[25];
    char phone[25];
    char ailment[50];
    int assigned_doctor_id;
    patient_status status;
}patient;

//Declaring a node for the patient
typedef struct patient_node
{
    patient data;
    struct patient_node *next;
}patient_node;

//Functions prototypes
int patients_counter(patient_node *head);
void add_patient(patient_node **head);
void update_patient(patient_node *head, int patient_id);
void view_patient(patient_node *head, int patient_id);
void delete_patient(patient_node **head, int patient_id);
void patients_list(patient_node *head);
void free_patients_list(patient_node **head);

#endif