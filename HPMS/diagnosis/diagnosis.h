#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

//Structure contains all the diagnosis information 
typedef struct 
{
    int id;
    int patient_id;
    char patient_name[50];
    int doctor_id;
    char doctor_name[50];
    char symptoms[50];
    char medicines[50];
}diagnosis;

//Declaring a node for the diagnosis
typedef struct diagnosis_node
{
    diagnosis data;
    struct diagnosis_node *next;
}diagnosis_node;

void add_diagnosis(diagnosis_node **head);
void update_diagnosis(diagnosis_node *head, int diagnosis_id);
void view_diagnosis(diagnosis_node *head, int diagnosis_id);
void delete_diagnosis(diagnosis_node **head, int diagnosis_id);
void diagnoses_list(diagnosis_node *head);
void free_diagnoses_list(diagnosis_node **head);

#endif