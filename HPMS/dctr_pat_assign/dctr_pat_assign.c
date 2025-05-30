#include <stdio.h>
#include <stdlib.h>
#include "patient/patient.h"
#include "doctor/doctor.h"

//Function to find a return pointer to the patient with the ID
patient_node *find_patient(patient_node *head, int id)
{
    while (head != NULL)
    {
        if(head->data.id == id)
            return head;
        head = head->next;
    }
    return NULL;
}

//Function to find a return pointer to the doctor with the ID
doctor_node *find_doctor(doctor_node *head, int id)
{
    while (head != NULL)
    {
        if(head->data.id == id)
            return head;
        head = head->next;
    }
    return NULL;
}

//Function to assign a doctor to a patient
void assign_doctor_patient(patient_node *p_head, doctor_node *dr_head)
{
    int patient_id, doctor_id;

    printf("Enter the patient ID: ");
    scanf("%d", &patient_id);

    //Search for the patient
    patient_node *p = find_patient(p_head, patient_id);
    if(p == NULL)
    {
        printf("Patient not found! \n");
        return;
    }

    printf("Enter the doctor ID: ");
    scanf("%d", &doctor_id);

    //Search for the doctor
    doctor_node *dr = find_doctor(dr_head, doctor_id);
    if(dr == NULL)
    {
        printf("Doctor not found! \n");
        return;
    }
    
    p->data.assigned_doctor_id = doctor_id;

    printf("Doctor %s assigned to patient %s\n", dr->data.name, p->data.name);
}