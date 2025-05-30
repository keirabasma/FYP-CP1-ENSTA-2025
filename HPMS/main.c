#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient/patient.h"
#include "doctor/doctor.h"
#include "diagnosis/diagnosis.h"
#include "search_BST/search_BST.h"
#include "dctr_pat_assign/dctr_pat_assign.h"
#include "discharge/discharge.h"
#include "wait_list/wait_list.h"
#include "hospital/hospital.h"
#include "d_schedule/d_schedule.h"

//Global variables
patient_node *patients = NULL;
doctor_node *doctors = NULL;
diagnosis_node *diagnoses = NULL;
stack discharged_stack;
queue waiting_queue;
hospital hospital_struct;
daily_sched schedule; 
tree_node *patient_BST = NULL;

//Function to initialize the system components
void init_syst()
{
    init_stack(&discharged_stack);
    init_queue(&waiting_queue);
    init_hospital(&hospital_struct, "Mercy Vale Clinic");
    init_schedule(&schedule);
}

//Function to free memory
void free_syst()
{
    free_patients_list(&patients);
    free_doctor_list(&doctors);
    free_diagnoses_list(&diagnoses);
    destroy_stack(&discharged_stack);
    destroy_queue(&waiting_queue);
    free_hospital(&hospital_struct);
    free_BST(patient_BST);
}

void display_menu()
{
    printf("\n------ Hospital Patient Management System ------\n");
    printf("1. Manage Patients\n");
    printf("2. Manage Doctors\n");
    printf("3. Manage Diagnoses\n");
    printf("4. Search Patient by ID or Name\n");
    printf("5. Assign a Doctor to a Patient\n");
    printf("6. Discharge Patient\n");
    printf("7. Manage Waiting Queue\n");
    printf("8. Hospital Structure Tree\n"); 
    printf("9. Daily Schedule\n");
    printf("10. Exit\n");
    printf("Choose an option: ");
}

void manage_patients()
{
    int option;

    do
    {
        printf("\n------ Patient Management ------\n");
        printf("1. Add Patient\n");
        printf("2. Update Patient\n");
        printf("3. View Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Patients List\n");
        printf("6. Back\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: 
            {
                add_patient(&patients);
                if(patients != NULL)
                {
                    patient_BST = insert(patient_BST, patients->data);
                }
                break;
            }
            case 2: 
            {
                int id;
                printf("Enter patient ID: ");
                scanf("%d", &id);
                update_patient(patients, id);
                break;
            }
            case 3: 
            {
                int id;
                printf("Enter patient ID: ");
                scanf("%d", &id);
                view_patient(patients, id);
                break;
            }
            case 4: 
            {
                int id;
                printf("Enter patient ID: ");
                scanf("%d", &id);
                delete_patient(&patients, id);
                break;
            }
            case 5: patients_list(patients);
            break;
            case 6: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 6);
}

void manage_doctors()
{
    int option;

    do
    {
        printf("\n------ Doctor Management ------\n");
        printf("1. Add Doctor\n");
        printf("2. Update Doctor\n");
        printf("3. View Doctor\n");
        printf("4. Delete Doctor\n");
        printf("5. Doctors List\n");
        printf("6. Back\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: add_doctor(&doctors);
            break;
            case 2: 
            {
                int id;
                printf("Enter doctor ID: ");
                scanf("%d", &id);
                update_doctor(doctors, id);
                break;
            }
            case 3: 
            {
                int id;
                printf("Enter doctor ID: ");
                scanf("%d", &id);
                view_doctor(doctors, id);
                break;
            }
            case 4: 
            {
                int id;
                printf("Enter doctor ID: ");
                scanf("%d", &id);
                delete_doctor(&doctors, id);
                break;
            }
            case 5: doctors_list(doctors);
            break;
            case 6: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 6);
}

void manage_diagnoses()
{
    int option;

    do
    {
        printf("\n------ Diagnosis Management ------\n");
        printf("1. Add diagnosis\n");
        printf("2. Update diagnosis\n");
        printf("3. View diagnosis\n");
        printf("4. Delete diagnosis\n");
        printf("5. diagnosis List\n");
        printf("6. Back\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: add_diagnosis(&diagnoses);
            break;
            case 2: 
            {
                int id;
                printf("Enter diagnosis ID: ");
                scanf("%d", &id);
                update_diagnosis(diagnoses, id);
                break;
            }
            case 3: 
            {
                int id;
                printf("Enter diagnosis ID: ");
                scanf("%d", &id);
                view_diagnosis(diagnoses, id);
                break;
            }
            case 4: 
            {
                int id;
                printf("Enter diagnosis ID: ");
                scanf("%d", &id);
                delete_diagnosis(&diagnoses, id);
                break;
            }
            case 5: diagnoses_list(diagnoses);
            break;
            case 6: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 6);
}

void search_patient_id_name()
{
    int option;

    do
    {
        printf("\n------ Search Patient ------\n");
        printf("1. By ID\n");
        printf("2. By Name\n");
        printf("3. Back\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            //Search by ID
            case 1: 
            {
                if(patient_BST == NULL)
                {
                    printf("No patients in the system!\n");
                    return;
                }
                int id;
                printf("Enter patient ID: ");
                scanf("%d", &id);
                tree_node *result = search(patient_BST, id, "");
                if(result)
                {
                    view_patient(patients, result->data.id);
                }
                else
                {
                    printf("Patient not found!\n");
                }
                break;
            }
            //Search by name
            case 2: 
            {
                char name[50];
                printf("Enter patient name: ");
                scanf(" %[^\n]", name);
                tree_node *result = search(patient_BST, -1, name);
                if(result)
                {
                    view_patient(patients, result->data.id);
                }
                else
                {
                    printf("Patient not found!\n");
                }
                break;
            }
            case 3: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 3);
}

void manage_waiting_queue()
{
    int option;

    do
    {
        printf("\n------ Waiting Queue ------\n");
        printf("1. Add Patient\n");
        printf("2. Process Next Patient\n");
        printf("3. View Queue\n");
        printf("4. Back\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            //add patient to queue
            case 1: 
            {
                int id;
                printf("Enter patient ID: ");
                scanf("%d", &id);
                patient_node *p = patients;
                while (p != NULL && p->data.id != id)
                {
                    p = p->next;
                }
                if(p != NULL)
                {
                    enqueue_patient(&waiting_queue, p->data);
                    printf("Patient added to queue\n");
                }
                else
                {
                    printf("Patient not found!\n");
                }
                break;
            }
            //Process next patient in queue
            case 2: 
            {
                if(!is_empty_queue(&waiting_queue))
                {
                    patient p = dequeue_patient(&waiting_queue);
                }
                else
                {
                    printf("Queue is empty!\n");
                }
                break;
            }
            case 3: view_waiting_list(&waiting_queue);
                break;
            case 4: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 4);
}

void hospital_structure()
{
    int option;

    do
    {
        printf("\n------ Hospital Structure ------\n");
        printf("1. Add Department\n");
        printf("2. Add Service\n");
        printf("3. Add Staff\n");
        printf("4. View Hospital Structure\n");
        printf("5. Back\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            //Add a department
            case 1: 
            {
                char name[50];
                printf("Enter the department name: ");
                scanf(" %[^\n]", name);
                add_department(&hospital_struct, name);
                break;
            }
            //Add a service
            case 2: 
            {
                int depart_indx;
                char name[50];
                printf("Enter department index: ");
                scanf("%d", &depart_indx);
                printf("Enter service name: ");
                scanf(" %[^\n]", name);
                add_service(&hospital_struct, depart_indx, name);
                break;
            }
            //Add a staff
            case 3: 
            {
                int depart_indx, serv_indx;
                char name[50], pos[50];
                printf("Enter department index: ");
                scanf("%d", &depart_indx);
                printf("Enter service index: ");
                scanf("%d", &serv_indx);
                printf("Enter staff name: ");
                scanf(" %[^\n]", name);
                printf("Enter position: ");
                scanf(" %[^\n]", pos);
                add_staff(&hospital_struct.departments[depart_indx].services[serv_indx], name, pos);
                break;
            }
            //View the hospital structure
            case 4: view_tree(&hospital_struct, 0);
                break;
            case 5: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 5);
}

void daily_schedule()
{
    int option;

    do
    {
        printf("\n------ Daily Schedule ------\n");
        printf("1. Add Appointment\n");
        printf("2. Delete Appointment\n");
        printf("3. View Schedule\n");
        printf("4. Back\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            //Add appointment
            case 1:
            {
                int hour, doctor_indx;
                char name[50];
                printf("Enter hour: ");
                scanf("%d", &hour);
                printf("Enter doctor index (0-%d): ", MAX_DOCTORS-1);
                scanf("%d", &doctor_indx);
                printf("Enter doctor name: ");
                scanf(" %[^\n]", name);
                add_appointment(&schedule, hour, doctor_indx, name);
                break;
            }
            //Delete appointment
            case 2: 
            {
                int hour, doctor_indx;
                printf("Enter hour: ");
                scanf("%d", &hour);
                printf("Enter doctor index (0-%d): ", MAX_DOCTORS-1);
                scanf("%d", &doctor_indx);
                delete_appointment(&schedule, hour, doctor_indx);
                break;
            }
            //View daily schedule
            case 3: view_schedule(&schedule);
            break;
            case 4: printf("Backing... \n");
            break;
            default: printf("choose a valid option!");
        }
    }while(option != 4);
}

int main()
{
    //Initialize the system components
    init_syst();

    int option;

    do
    {
        display_menu();
        scanf("%d", &option);
        switch(option)
        {
            case 1: manage_patients();
            break;
            case 2: manage_doctors();
            break;
            case 3: manage_diagnoses();
            break;
            case 4: search_patient_id_name();
            break;
            case 5: assign_doctor_patient(patients, doctors);
            break;
            case 6: discharge_patient(&discharged_stack, &patients);
            break;
            case 7: manage_waiting_queue();
            break;
            case 8: hospital_structure();
            break;
            case 9: daily_schedule();
            break;
            case 10: printf("Exiting...\n");
            break;
            default: printf("choose a valid option!");
        }
    } while (option != 10);

    //Free memory
    free_syst();
    
    return 0;
}