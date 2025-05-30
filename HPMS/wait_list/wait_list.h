#ifndef WAIT_LIST_H
#define WAIT_LIST_H
#include "patient/patient.h"

//Create a queue to hold waiting patients
typedef struct queue_node
{
    patient data;
    struct queue_node *next;
}queue_node;
typedef struct queue
{
    queue_node *front;
    queue_node *rear;
}queue;

void init_queue(queue *q);
int is_empty_queue(queue *q);
void enqueue_patient(queue *q, patient patient_data);
patient dequeue_patient(queue *q);
void view_waiting_list(queue *q);
void destroy_queue(queue *q);

#endif