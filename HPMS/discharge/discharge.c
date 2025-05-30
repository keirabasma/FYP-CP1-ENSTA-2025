#include <stdio.h>
#include <stdlib.h>
#include "discharge.h"
#include "patient/patient.h"

//Initialize the stack
void init_stack(stack *s)
{
    s->top = NULL;
}

//Function to check if the stack is empty
int is_empty_stack(stack *s)
{
    return (s->top == NULL);
}

//Function to push a patient to the stack
void push(stack *s, patient patient_data)
{
    stack_node *new_node = (stack_node*)malloc(sizeof(stack_node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }
    new_node->data = patient_data;
    new_node->next = s->top;
    s->top = new_node;
}

//Function to pop a patient from the stack
patient pop(stack *s)
{
    if(is_empty_stack(s))
    {
        printf("Stack underflow! \n");
        exit(1);
    }
    stack_node *temp = s->top;
    patient patient_data = temp->data;
    s->top = s->top->next;
    free(temp);
    return patient_data;
}

//Function to remove patient from patients list and push it to the stack
void discharge_patient(stack *s, patient_node **head)
{
    int patient_id;

    printf("Enter the patient ID: ");
    scanf("%d", &patient_id); 
    
    //Find the patient in patients list
    patient_node *prev = NULL;
    patient_node *current = *head;

    while(current != NULL && current->data.id != patient_id)
    {
        prev = current;
        current = current->next;
    }

    if(current == NULL)
    {
        printf("Patient not found! \n");
        return;
    }
    
    //Push the patient to stack
    push(s, current->data);
    //Remove patient from patients list
    if(prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);

    printf("Patient discharged successfully. \n");
}

//Function to pop patient from the stack and add it to the patients list (Undo)
void undo_lst_discharge(stack *s, patient_node **head)
{
    if(is_empty_stack(s))
    {
        printf("Stack underflow! \n");
        return;
    }

    patient patient_data = pop(s);

    //create a node for patient and insert it at the begining of the list
    patient_node *new_node = (patient_node*)malloc(sizeof(patient_node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }
    new_node->data = patient_data;
    new_node->next = *head;
    *head = new_node;
    
    printf("Patient added back successfully. \n");
}

//Show the patient in the stack 
void view_stack(stack *s)
{
    if(is_empty_stack(s))
    {
        printf("Stack is empty! \n");
        return;
    }
    printf("The stack elements \n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "ID", "Name", "Age", "Gender", "Blood Group", "Address", "Email", "Phone number", "Ailment", "Assigned doctor ID", "Status");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________");
    stack_node *current = s->top;
    while (current != NULL)
    {
        printf("%d\t%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n", current->data.id, current->data.name, current->data.age, current->data.gender, current->data.bld_grp, current->data.address, current->data.email, current->data.phone, current->data.ailment, current->data.assigned_doctor_id, current->data.status);

        current = current->next;
    }
    printf("____________________________________________________________________________________________________________________________________________________________________________________________");
    printf("Stack elements end \n");
}

//Function to free stack
void destroy_stack(stack *s)
{
    while(!is_empty_stack(s))
    {
        stack_node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}