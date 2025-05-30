#ifndef DOCTOR_H
#define DOCTOR_H

//Enumerator for the doctor availability
typedef enum {available, not_available} doctor_availability;

//Structure contains all the doctor information
typedef struct doctor
{
    int id;
    char name[50];
    int age;
    char gender; //'F' for female & 'M' for
    char address[50];
    char email[25];
    char phone[25];
    char specialization[50];
    doctor_availability availability;
}doctor;

//Declaring a node for the doctor
typedef struct doctor_node
{
    doctor data;
    struct doctor_node *next;
}doctor_node;

void add_doctor(doctor_node **head);
void update_doctor(doctor_node *head, int doctor_id);
void view_doctor(doctor_node *head, int doctor_id);
void delete_doctor(doctor_node **head, int doctor_id);
void doctors_list(doctor_node *head);
void free_doctor_list(doctor_node **head);

#endif