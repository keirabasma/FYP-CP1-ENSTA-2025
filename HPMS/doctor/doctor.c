#include <stdio.h>
#include <stdlib.h>
#include "doctor.h"

//Function to add a doctor to the hospital system
void add_doctor(doctor_node **head)
{
    doctor_node *dr = (doctor_node*)malloc(sizeof(doctor_node));
    if(dr == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }

    printf("Enter the doctor information \n");
    printf("ID: ");
    scanf("%d", &dr->data.id);
    printf("Name: ");
    scanf(" %[^\n]", dr->data.name);
    printf("Age: ");
    scanf("%d", &dr->data.age);
    printf("Gender (Enter F for female and M for male): ");
    scanf(" %c", &dr->data.gender);
    printf("Address: ");
    scanf(" %[^\n]", dr->data.address);
    printf("Email: ");
    scanf(" %[^\n]", dr->data.email);
    printf("Phone number: ");
    scanf(" %[^\n]", dr->data.phone);
    printf("Specialization: ");
    scanf(" %[^\n]", dr->data.specialization);
    dr->data.availability = available; //by default

    dr->next = *head;
    *head = dr;

    printf("Doctor added successfully. \n");
}

//Function to update the doctor information
void update_doctor(doctor_node *head, int doctor_id)
{
    doctor_node *current = head;
    while(current != NULL)
    {
        if(current->data.id == doctor_id)
        {
            printf("Enter the new information \n");
            printf("Name: ");
            scanf(" %[^\n]", current->data.name);
            printf("Age: ");
            scanf("%d", &current->data.age);
            printf("Gender (Enter F for female and M for male): ");
            scanf(" %c", &current->data.gender);
            printf("Address: ");
            scanf(" %[^\n]", current->data.address);
            printf("Email: ");
            scanf(" %[^\n]", current->data.email);
            printf("Phone number: ");
            scanf(" %[^\n]", current->data.phone);
            printf("Specialization: ");
            scanf(" %[^\n]", current->data.specialization);
            //print the doctor availability
            printf("Availability: ");
            switch (current->data.availability)
            {
                case available: printf("Available\n");
                break;
                case not_available: printf("Not available\n");
                break;
                default: printf("Unknown\n");
            }

            printf("Doctor information updated successfully. \n");
            return;
        }
        current = current->next;
    }
    printf("Doctor not found! \n");
}

//Function to search and show the doctor information
void view_doctor(doctor_node *head, int doctor_id)
{
    doctor_node *current = head;
    while(current != NULL)
    {
        if(current->data.id == doctor_id)
        {
            printf("The doctor information \n");
            printf("ID: %d\n", current->data.id);
            printf("Name: %s\n", current->data.name);
            printf("Age: %d\n", current->data.age);
            printf("Gender: %c\n", current->data.gender);
            printf("Address: %s\n", current->data.address);
            printf("Email: %s\n", current->data.email);
            printf("Phone number: %s\n", current->data.phone);
            printf("Specialization: %s\n", current->data.specialization);
            printf("Availability: %s\n", current->data.availability == available ? "Available" : "Not Available");
            return;
        }
        current = current->next;
    }
    printf("Doctor not found! \n");
}

//Function to delete a doctor from the hospital system
void delete_doctor(doctor_node **head, int doctor_id)
{
    if(*head == NULL)
    {
        printf("There is no doctors! \n");
        return;
    }
    if((*head)->data.id == doctor_id)
    {
        doctor_node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Doctor deleted successfully.\n");
        return;
    }
    doctor_node *current = *head;
    while(current->next != NULL && current->next->data.id != doctor_id)
    {
        current = current->next;
    }
    if(current->next == NULL)
    {
        printf("Doctor not found! \n");
        return;
    }
    doctor_node *temp = current->next;
    current->next = current->next->next;
    free(temp);

    printf("Doctor deleted successfully \n");
}

//Function to show the doctors list 
void doctors_list(doctor_node *head)
{
    if(head == NULL)
    {
        printf("Doctors list is empty!");
        return;
    }
    doctor_node *current = head;
    printf("The doctors list \n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t", "ID", "Name", "Age", "Gender", "Address", "Email", "Phone number", "Specialization", "Availability");
        printf("___________________________________________________________________________________________________________________________________________________________");
    while (current != NULL)
    {
        printf("%d\t%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\n", current->data.id, current->data.name, current->data.age, current->data.gender, current->data.address, current->data.email, current->data.phone, current->data.specialization, current->data.availability == available ? "Available" : "Not Available");

        current = current->next;
    }
    printf("______________________________________________________________________________________________________________________________________________________________________________");
    printf("doctors list end \n");
}

//Function to free the doctors list
void free_doctor_list(doctor_node **head)
{
    doctor_node *current = *head;
    doctor_node *temp;
    while(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}