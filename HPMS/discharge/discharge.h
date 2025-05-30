#ifndef DISCHARGE_H
#define DISCHARGE_H
#include "patient/patient.h"

//Create a stack to hold discharged patients
typedef struct stack_node
{
    patient data;
    struct stack_node *next;
}stack_node;
typedef struct stack
{
    stack_node *top;
}stack;

void init_stack(stack *s);
int is_empty_stack(stack *s);
void push(stack *s, patient patient_data);
patient pop(stack *s);
void discharge_patient(stack *s, patient_node **head);
void undo_lst_discharge(stack *s, patient_node **head);
void view_stack(stack *s);
void destroy_stack(stack *s);

#endif