#include <stdio.h>
#include <stdlib.h>
#include "diagnosis.h"

//Function to add a diagnosis to the hospital system
void add_diagnosis(diagnosis_node **head)
{
    diagnosis_node *g = (diagnosis_node*)malloc(sizeof(diagnosis_node));
    if(g == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }

    printf("Enter the diagnosis information \n");
    printf("ID: ");
    scanf("%d", &g->data.id);
    printf("Patient ID: ");
    scanf("%d", &g->data.patient_id);
    printf("Patient name: ");
    scanf(" %[^\n]", g->data.patient_name);
    printf("Doctor ID: ");
    scanf(" %d", &g->data.doctor_id);
    printf("Doctor name: ");
    scanf(" %[^\n]", g->data.doctor_name);
    printf("Symptoms: ");
    scanf(" %[^\n]", g->data.symptoms);
    printf("Medicines: ");
    scanf(" %[^\n]", g->data.medicines);

    g->next = *head;
    *head = g;

    printf("Diagnosis added successfully. \n");
}

//Function to update the diagnosis information
void update_diagnosis(diagnosis_node *head, int diagnosis_id)
{
    diagnosis_node *current = head;
    while(current != NULL)
    {
        if(current->data.id == diagnosis_id)
        {
            printf("Enter the new information ");
            printf("Patient ID: ");
            scanf("%d", &current->data.patient_id);
            printf("Patient name: ");
            scanf(" %[^\n]", current->data.patient_name);
            printf("Doctor ID: ");
            scanf(" %d", &current->data.doctor_id);
            printf("Doctor name: ");
            scanf(" %[^\n]", current->data.doctor_name);
            printf("Symptoms: ");
            scanf(" %[^\n]", current->data.symptoms);
            printf("Medicines: ");
            scanf(" %[^\n]", current->data.medicines);
            
            printf("Diagnosis information updated successfully. \n");
            return;
        }
        current = current->next;
    }
    printf("Diagnosis not found! \n");
}

//Function to search and show the diagnosis information
void view_diagnosis(diagnosis_node *head, int diagnosis_id)
{
    diagnosis_node *current = head;
    while(current != NULL)
    {
        if(current->data.id == diagnosis_id)
        {
            printf("The diagnosis information \n");
            printf("ID: %d\n", current->data.id);
            printf("Patient ID: %d\n", current->data.patient_id);
            printf("Patient name: %s\n", current->data.patient_name);
            printf("Doctor ID: %d\n", current->data.doctor_id);
            printf("Doctor name: %s\n", current->data.doctor_name);
            printf("Symptoms: %s\n", current->data.symptoms);
            printf("Medicines: %s\n", current->data.medicines);
            return;
        }
        current = current->next;
    }
    printf("Diagnosis not found! \n");
}

//Function to delete a diagnosis from the hospital system
void delete_diagnosis(diagnosis_node **head, int diagnosis_id)
{
    if(*head == NULL)
    {
        printf("There is no diagnoses! \n");
        return;
    }
    if((*head)->data.id == diagnosis_id)
    {
        diagnosis_node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Diagnosis deleted successfully. \n");
        return;
    }
    diagnosis_node *current = *head;
    while(current->next != NULL && current->next->data.id != diagnosis_id)
    {
        current = current->next;
    }
    if(current->next == NULL)
    {
        printf("diagnosis not found! \n");
        return;
    }
    diagnosis_node *temp = current->next;
    current->next = current->next->next;
    free(temp);

    printf("Diagnosis deleted successfully. \n");
}

//Function to show the diagnoses list
void diagnoses_list(diagnosis_node *head)
{
    if(head == NULL)
    {
        printf("Diagnoses list is empty! \n");
        return;
    }
    diagnosis_node *current = head;
    printf("The diagnoses list \n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "ID", "Patient ID", "Patient name", "Doctor ID", "Doctor name", "Symptoms", "Medicines");
        printf("_____________________________________________________________________________________________________________________________________________________________");
    while (current != NULL)
    {
        printf("%d\t%d\t%s\t%d\t%s\t%s\t%s\t", current->data.id, current->data.patient_id, current->data.patient_name, current->data.doctor_id, current->data.doctor_name, current->data.symptoms, current->data.medicines);

        current = current->next;
    }
    printf("___________________________________________________________________________________________________________________________________________________");
    printf("Diagnoses list end \n");
}

//Function to free the diagnoses list
void free_diagnoses_list(diagnosis_node **head)
{
    diagnosis_node *current = *head;
    diagnosis_node *temp;
    while(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}