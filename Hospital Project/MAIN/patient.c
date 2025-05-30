#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "patient.h"
#include "departments.h"
#include "details.h"

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
    new_patient_node->p->priority = NON_CRITICAL;
    new_patient_node->p->status = WAITING;
    new_patient_node->p->bed = new_patient_node->p->room = NULL;
    
    printf(
    "+------------------------------------------------+\n"
    "|                                                |\n"
    "|      * Please, enter patient details : *       |\n"
    "|                                                |\n"
    "+------------------------------------------------+\n"
    "                                                  \n"
    "1.> Enter FULL NAME: "
    );
    fgets(new_patient_node->p->full_name, sizeof(new_patient_node->p->full_name), stdin);
    new_patient_node->p->full_name[strcspn(new_patient_node->p->full_name, "\n")] = 0;
    capitalize_first_char(new_patient_node->p->full_name);

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
    int patient_ID = generateID() ;
    new_patient_node->p->id = patient_ID;
    printf("3.> Patient ID is : %d ", patient_ID);

    printf("\n");
    printf("4.> Enter AGE: ");
    char age_str[10];
    fgets(age_str, sizeof(age_str), stdin);
    new_patient_node->p->age = atoi(age_str);

    if (new_patient_node->p->age < 14) {
        // Child
        printf("\nThis patient is classified as a child and will be transferred to the child department.\n");
        printf(
            "+------------------------------------------------+\n"
            "|                                                |\n"
            "|     * pediatric department (child care) *      |\n"
            "|                                                |\n"
            "+------------------------------------------------+\n"
            "                                                  \n"
            "> Departments list : \n"
        );
        display_department_tree(pediatric, 1);
        while (!valid) {
            printf("> Choose a pediatric department: ");
            char deps_str[50];
            fgets(deps_str, sizeof(deps_str), stdin);
            deps_str[strcspn(deps_str, "\n")] = 0;
            if (department_child_exists(pediatric, deps_str)) {
                strcpy(new_patient_node->p->department, deps_str);
                valid = 1;
            } else {
                printf("Invalid department name. Please try again.\n");
            }
        }
        valid = 0;
        printf("> Child illness list : \n");
        printf(
            "+------------------------------------------------+\n"
            "|                                                |\n"
            "|    1.  Common Cold                             |\n"
            "|    2.  Ear Infections (Otitis Media)           |\n"
            "|    3.  Influenza (Flu)                         |\n"
            "|    4.  Stomach Flu (Gastroenteritis)           |\n"
            "|    5.  Strep Throat                            |\n"
            "|    6.  Bronchitis                              |\n"
            "|    7.  Respiratory Syncytial Virus (RSV)       |\n"
            "|    8.  Hand, Foot, and Mouth Disease           |\n"
            "|    9.  Chickenpox (Varicella)                  |\n"
            "|   10.  Pink Eye (Conjunctivitis)               |\n"
            "|   11.  Other +                                 |\n"
            "|                                                |\n"
            "+------------------------------------------------+\n"
            "                                                  \n"
            "> Choose Illness number: "
        );
        char illness_input[10];
        fgets(illness_input, sizeof(illness_input), stdin);
        int illness_choice = atoi(illness_input);
        char illnessName[100];
        if (illness_choice >= 1 && illness_choice <= 10) {
            child_illness_selected = (child_illness)(illness_choice - 1);
        } else {
            child_illness_selected = CUSTOM_ILLNESS_CHILD;
        }
        set_child_illness_name(child_illness_selected, illnessName);

    } else if (new_patient_node->p->age > 60) {

        // Elderly
        printf("\nThis patient is classified as an elderly.\n");
        printf(
            "+------------------------------------------------+\n"
            "|                                                |\n"
            "|    * Geriatric  department (elderly care) *    |\n"
            "|                                                |\n"
            "+------------------------------------------------+\n"
            "                                                  \n"
            "> Departments list : \n"
        );
        display_department_tree(geriatric, 1);
        while (!valid) {
            printf("> Choose an geriatric department: ");
            char deps_str[50];
            fgets(deps_str, sizeof(deps_str), stdin);
            deps_str[strcspn(deps_str, "\n")] = 0;
            if (department_child_exists(geriatric, deps_str)) {
                strcpy(new_patient_node->p->department, deps_str);
                valid = 1;
            } else {
                printf("Invalid department name. Please try again.\n");
            }
        }
        valid = 0;
        printf("> Elder illness list : \n");
        printf(
            "+------------------------------------------------+\n"
            "|                                                |\n"
            "|    1.  Alzheimer's Disease                     |\n"
            "|    2.  Arthritis                               |\n"
            "|    3.  Heart Disease                           |\n"
            "|    4.  Diabetes                                |\n"
            "|    5.  Osteoporosis                            |\n"
            "|    6.  Hypertension                            |\n"
            "|    7.  Parkinson's Disease                     |\n"
            "|    8.  Chronic Obstructive Pulmonary Disease   |\n"
            "|    9.  Cancer                                  |\n"
            "|   10.  Depression                              |\n"
            "|   11.  Other +                                 |\n"
            "|                                                |\n"
            "+------------------------------------------------+\n"
            "                                                  \n"
            "> Choose Illness number: "
        );
        char illness_input[10];
        fgets(illness_input, sizeof(illness_input), stdin);
        int illness_choice = atoi(illness_input);
        char illnessName[100];
        if (illness_choice >= 1 && illness_choice <= 10) {
            elder_illness_selected = (elder_illness)(illness_choice - 1);
        } else {
            elder_illness_selected = CUSTOM_ILLNESS_ELDER;
        }
        set_elder_illness_name(elder_illness_selected, illnessName);

    } else if (new_patient_node->p->gen == GENDER_FEMALE && new_patient_node->p->age < 60 && new_patient_node->p->age > 14) {

        // Female
        printf("\nThis patient is classified as a female and will be transferred to the Women's Wellness & Health Department.\n");
        printf(
            "+---------------------------------------------+\n"
            "|                                             |\n"
            "|   * Women's Wellness & Health Department *  |\n"
            "|                                             |\n"
            "+---------------------------------------------+\n"
            "                                               \n"
            "> Departments list : \n"
        );
        display_department_tree(femiatric, 1);
        while (!valid) {
            printf("> Choose a femiatric department: ");
            char deps_str[50];
            fgets(deps_str, sizeof(deps_str), stdin);
            deps_str[strcspn(deps_str, "\n")] = 0;
            if (department_child_exists(femiatric, deps_str)) {
                strcpy(new_patient_node->p->department, deps_str);
                valid = 1;
            } else {
                printf("Invalid department name. Please try again.\n");
            }
        }
        valid = 0;

        printf("> Female illness list : \n");
        printf(
            "+---------------------------------------------+\n"
            "|                                             |\n"
            "|    1.  Polycystic Ovary Syndrome (PCOS)     |\n"
            "|    2.  Breast Cancer                        |\n"
            "|    3.  Osteoporosis                         |\n"
            "|    4.  Endometriosis                        |\n"
            "|    5.  Cervical Cancer                      |\n"
            "|    6.  Menstrual Disorders                  |\n"
            "|    7.  Depression and Anxiety               |\n"
            "|    8.  Autoimmune Diseases                  |\n"
            "|    9.  Thyroid Disorders                    |\n"
            "|   10.  Fibroids                             |\n"
            "|   11.  Other +                              |\n"
            "|                                             |\n"
            "+---------------------------------------------+\n"
            "                                               \n"
            "> Choose Illness number: "
        );
        char illness_input[10];
        fgets(illness_input, sizeof(illness_input), stdin);
        int illness_choice = atoi(illness_input);
        char illnessName[100];
        if (illness_choice >= 1 && illness_choice <= 10) {
            female_illness_selected = (female_illness)(illness_choice - 1);
        } else {
            female_illness_selected = CUSTOM_ILLNESS_FEMALE;
        }
        set_female_illness_name(female_illness_selected, illnessName);
            
    } else if(new_patient_node->p->gen == GENDER_MALE && new_patient_node->p->age < 60 && new_patient_node->p->age > 14) {
        
        // Male
        printf(
            "+---------------------------------------------+\n"
            "|                                             |\n"
            "|          * Choose a department : *          |\n"
            "|                                             |\n"
            "+---------------------------------------------+\n"
            "                                               \n"
            "> Departments list : \n"
        );
        display_department_tree(department_root, 0);
        while (!valid) {
            printf("> Choose a department: ");
            char deps_str[50];
            fgets(deps_str, sizeof(deps_str), stdin);
            deps_str[strcspn(deps_str, "\n")] = 0;
            if (department_child_exists(department_root, deps_str)) {
                strcpy(new_patient_node->p->department, deps_str);
                valid = 1;
            } else {
                printf("Invalid department name. Please try again.\n");
            }
        }
        valid = 0;
        printf(
            "+---------------------------------------------+\n"
            "|                                             |\n"
            "|    1.  Hypertension                         |\n"
            "|    2.  Diabetes Mellitus                    |\n"
            "|    3.  Heart Disease                        |\n"
            "|    4.  Prostate Problems                    |\n"
            "|    5.  Respiratory Infections               |\n"
            "|    6.  Depression and Anxiety               |\n"
            "|    7.  Obesity                              |\n"
            "|    8.  Back Pain                            |\n"
            "|    9.  Gastrointestinal Disorders           |\n"
            "|   10.  Skin Conditions                      |\n"
            "|   11.  Other +                              |\n"
            "|                                             |\n"
            "+---------------------------------------------+\n"
            "                                               \n"
            "> Choose Illness number: "
        );
        char illness_input[10];
        fgets(illness_input, sizeof(illness_input), stdin);
        int illness_choice = atoi(illness_input);
        char illnessName[100];
        if (illness_choice >= 1 && illness_choice <= 10) {
            male_illness_selected = (male_illness)(illness_choice - 1);
        } else {
            male_illness_selected = CUSTOM_ILLNESS_MALE;
        }
        set_male_illness_name(male_illness_selected, illnessName);
    }


    
    new_patient_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_patient_node;
    }
    *head = new_patient_node;
    return *head;
}