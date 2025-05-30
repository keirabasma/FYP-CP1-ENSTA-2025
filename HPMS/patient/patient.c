#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

//Function to count number of patients
int patients_counter(patient_node *head)
{
    int c = 0;
    patient_node * current = head;
    while (current != NULL)
    {
        c++;
        current = current->next;
    }
    return c;
}

//Function to add a patient to the hospital system
void add_patient(patient_node **head)
{
    if(patients_counter(*head) >= MAX_PATIENTS)
    {
        printf("No more capacity, can not add patient. \n");
        return;
    }

    patient_node *p = (patient_node*)malloc(sizeof(patient_node));
    if(p == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }

    printf("Enter the patient information \n");
    printf("ID: ");
    scanf("%d", &p->data.id);
    printf("Name: ");
    scanf(" %[^\n]", p->data.name);
    printf("Age: ");
    scanf("%d", &p->data.age);
    printf("Gender (Enter F for female and M for male): ");
    scanf(" %c", &p->data.gender);
    printf("Blood group: ");
    scanf(" %[^\n]", p->data.bld_grp);
    printf("Address: ");
    scanf(" %[^\n]", p->data.address);
    printf("Email: ");
    scanf(" %[^\n]", p->data.email);
    printf("Phone number: ");
    scanf(" %[^\n]", p->data.phone);
    printf("Ailment: ");
    scanf(" %[^\n]", p->data.ailment);
    printf("Assigned doctor ID: ");
    scanf("%d", &p->data.assigned_doctor_id);
    p->data.status = waiting; //by default

    p->next = *head;
    *head = p;

    printf("Patient added successfully. \n");
}

//Function to update the patient information
void update_patient(patient_node *head, int patient_id)
{
    patient_node *current = head;
    while(current != NULL)
    {
        if(current->data.id == patient_id)
        {
            printf("Enter the new information \n");
            printf("Name: ");
            scanf(" %[^\n]", current->data.name);
            printf("Age: ");
            scanf("%d", &current->data.age);
            printf("Gender (Enter F for female and M for male): ");
            scanf(" %c", &current->data.gender);
            printf("Blood group: ");
            scanf(" %[^\n]", current->data.bld_grp);
            printf("Address: ");
            scanf(" %[^\n]", current->data.address);
            printf("Email: ");
            scanf(" %[^\n]", current->data.email);
            printf("Phone number: ");
            scanf(" %[^\n]", current->data.phone);
            printf("Ailment: ");
            scanf(" %[^\n]", current->data.ailment);
            printf("Assigned doctor ID: ");
            scanf("%d", &current->data.assigned_doctor_id);
            //print the status of the patient
            printf("Status: ");
            switch (current->data.status)
            {
                case waiting: printf("Waiting\n");
                break;
                case under_treatment: printf("Under treatment\n");
                break;
                case discharged: printf("Discharged\n");
                break;
                default: printf("Unknown\n");
            }

            printf("Patient information updated successfully. \n");
            return;
        }
        current = current->next;
    }
    printf("Patient not found! \n");
}

//Function to search by ID or name and show the patient information
void view_patient(patient_node *head, int patient_id)
{
    patient_node *current = head;
    while(current != NULL)
    {
        if(current->data.id == patient_id)
        {
            printf("\nThe patient information \n");
            printf("ID: %d\n", current->data.id);
            printf("Name: %s\n", current->data.name);
            printf("Age: %d\n", current->data.age);
            printf("Gender: %c\n", current->data.gender);
            printf("Blood group: %s\n", current->data.bld_grp);
            printf("Address: %s\n", current->data.address);
            printf("Email: %s\n", current->data.email);
            printf("Phone number: %s\n", current->data.phone);
            printf("Ailment: %s\n", current->data.ailment);
            printf("The assigned doctor ID: %d\n", current->data.assigned_doctor_id);
            printf("Status: ");
            switch (current->data.status)
            {
                case waiting: printf("Waiting\n");
                break;
                case under_treatment: printf("Under treatment\n");
                break;
                case discharged: printf("Discharged\n");
                break;
                default: printf("Unknown\n");
            }
            return;
        }
        current = current->next;
    }
    printf("Patient not found! \n");
}

//Function to delete a patient from the hospital system
void delete_patient(patient_node **head, int patient_id)
{
    if(*head == NULL)
    {
        printf("There is no patients! \n");
        return;
    }
    if((*head)->data.id == patient_id)
    {
        patient_node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Patient deleted successfully. \n");
        return;
    }
    patient_node *current = *head;
    while(current->next != NULL && current->next->data.id != patient_id)
    {
        current = current->next;
    }
    if(current->next == NULL)
    {
        printf("Patient not found! \n");
        return;
    }
    patient_node *temp = current->next;
    current->next = current->next->next;
    free(temp);

    printf("Patient deleted successfully. \n");
}

//Function to show the patients list
void patients_list(patient_node *head)
{
    if(head == NULL)
    {
        printf("Patients list is empty! \n");
        return;
    }
    patient_node *current = head;
    printf("The patients list \n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t", "ID", "Name", "Age", "Gender", "Blood Group", "Address", "Email", "Phone number", "Ailment", "Assigned doctor ID", "Status");
        printf("____________________________________________________________________________________________________________________________________________________________");
    while (current != NULL)
    {
        printf("%d\t%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\t%d\t", current->data.id, current->data.name, current->data.age, current->data.gender, current->data.bld_grp, current->data.address, current->data.email, current->data.phone, current->data.ailment, current->data.assigned_doctor_id);
        switch (current->data.status)
        {
            case waiting: printf("Waiting\n");
            break;
            case under_treatment: printf("Under treatment\n");
            break;
            case discharged: printf("Discharged\n");
            break;
            default: printf("Unknown\n");
        }
        current = current->next;
    }
    printf("_______________________________________________________________________________________________________________________________________________________________________________");
    printf("Patients list end \n");
}

//Function to free the patients list
void free_patients_list(patient_node **head)
{
    patient_node *current = *head;
    patient_node *temp;
    while(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}