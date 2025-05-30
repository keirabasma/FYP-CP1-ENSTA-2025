#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

typedef struct p_node
{
    patient *p;
    struct p_node *next;
    struct p_node *prev;
} patient_node;

patient_node *add_new_patient(patient_node **head)
{
    patient_node* new_patient_node = (patient_node*)malloc(sizeof(patient_node));
    if (new_patient_node == NULL)
    {
        printf("There is no space left!");
        return;
    }
    new_patient_node->p = (patient*)malloc(sizeof(patient));
    if (new_patient_node->p == NULL) {
        printf("There is no space left for patient data!\n");
        free(new_patient_node);
        return;
    }
    new_patient_node->next = new_patient_node->prev = NULL;

    printf(
    "+---------------------------------------------+\n"
    "|                                             |\n"
    "|     * Please, enter patient details : *     |\n"
    "|                                             |\n"
    "+---------------------------------------------+\n"
    "                                               \n"
    "1.> Enter FULL NAME: "
    );
    fgets(new_patient_node->p->full_name, sizeof(new_patient_node->p->full_name), stdin);
    new_patient_node->p->full_name[strcspn(new_patient_node->p->full_name, "\n")] = 0; // Remove newline

    printf("\n");
    printf("2.> Enter GENDER MALE / FEMALE : ");
    char gender_str[10];
    fgets(gender_str, sizeof(gender_str), stdin);
    gender_str[strcspn(gender_str, "\n")] = 0;
    if (gender_str[0] == 'M' || gender_str[0] == 'm') {
        new_patient_node->p->gen = GENDER_MALE;
    } else if (gender_str[0] == 'F' || gender_str[0] == 'f') {
        new_patient_node->p->gen = GENDER_FEMALE;
    } else {
        printf("Invalid gender entered. Defaulting to MALE.\n");
        new_patient_node->p->gen = GENDER_MALE;
    }

    printf("\n");
    int ID = generateID() ;
    new_patient_node->p->id = ID;
    printf("3.> Patient ID is : %d ", ID);

    printf("\n");
    printf("4.> Enter AGE: ");
    char age_str[10];
    fgets(age_str, sizeof(age_str), stdin);
    new_patient_node->p->age = atoi(age_str);
    if (new_patient_node->p->age < 14)
    {
        printf("\nThis patient is classified as a child and will be transferred to the child department.\n");

    } else {
    
        
    }
    // Insert at the beginning of the list
    new_patient_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_patient_node;
    }
    *head = new_patient_node;
    return *head;
}