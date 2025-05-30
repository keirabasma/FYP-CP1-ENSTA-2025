#include <stdio.h>
#include <stdlib.h>
#include "wait_list.h"
#include "patient/patient.h"

//Initialize the queue
void init_queue(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

//Function to check if the queue is empty
int is_empty_queue(queue *q)
{
    return (q->front == NULL);
}

//Function to add a patient at rear
void enqueue_patient(queue *q, patient patient_data)
{
    queue_node *new_node = (queue_node*)malloc(sizeof(queue_node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }
    new_node->data = patient_data;
    new_node->next = NULL;
    if(is_empty_queue(q))
    {
        q->front = new_node;
    }
    else
    {
        q->rear->next = new_node;
    }
    q->rear = new_node;
}

//Function to delete a patient from front
patient dequeue_patient(queue *q)
{
    if(is_empty_queue(q))
    {
        printf("Queue underflow! \n");
        exit(1);
    }
    queue_node *temp = q->front;
    patient patient_data = temp->data;
    q->front = q->front->next;
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return patient_data;
}

//Function show waiting patients (front -> rear)
void view_waiting_list(queue *q)
{
    if(is_empty_queue(q))
    {
        printf("Queue is empty! \n");
        return;
    }
    printf("The queue elements \n");
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "ID", "Name", "Age", "Gender", "Blood Group", "Address", "Email", "Phone number", "Ailment", "Assigned doctor ID", "Status");
    printf("____________________________________________________________________________________________________________________________________________________________________________________________");
    queue_node *current = q->front;
    while(current != NULL)
    {
        printf("%d\t%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\t%d\t%s\n", current->data.id, current->data.name, current->data.age, current->data.gender, current->data.bld_grp, current->data.address, current->data.email, current->data.phone, current->data.ailment, current->data.assigned_doctor_id, current->data.status);
        current = current->next;
    }
    printf("____________________________________________________________________________________________________________________________________________________________________________________________");
    printf("Queue elements end \n");
}

//Function to free queue
void destroy_queue(queue *q)
{
    queue_node *current = q->front;
    while(current != NULL)
    {
        queue_node *temp = current;
        current = current->next;
        free(temp);
    }
    q->front = NULL;
    q->rear = NULL;
}