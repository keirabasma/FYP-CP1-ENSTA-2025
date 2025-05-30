#include "details.h"
#include <string.h>
#include <stdio.h>

const char *week_days[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int valid = 0;

// Shared arrays for hours and minutes
// const int shared_hours[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
// const int shared_minutes[60] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };
// // Initialize the time object
// const time_hours_mins appointment_time = {
//     .hour = shared_hours,
//     .min = shared_minutes
// };

int generateID() {
    return (rand() % 9000) + 1000;
};

void set_child_illness_name(child_illness child_illness_selected, char illnessName[], size_t illnessNameSize) {
    switch (child_illness_selected) {
        case COMMON_COLD:
            strcpy(illnessName, "Common Cold");
            break;
        case EAR_INFECTION:
            strcpy(illnessName, "Ear Infection");
            break;
        case FLU:
            strcpy(illnessName, "Influenza");
            break;
        case STOMACH_FLU:
            strcpy(illnessName, "Stomach Flu");
            break;
        case STREP_THROAT:
            strcpy(illnessName, "Strep Throat");
            break;
        case BRONCHITIS:
            strcpy(illnessName, "Bronchitis");
            break;
        case RSV:
            strcpy(illnessName, "Respiratory Syncytial Virus");
            break;
        case HAND_FOOT_MOUTH:
            strcpy(illnessName, "Hand, Foot, and Mouth Disease");
            break;
        case CHICKENPOX:
            strcpy(illnessName, "Chickenpox");
            break;
        case PINK_EYE:
            strcpy(illnessName, "Pink Eye");
            break;
        default:
            printf("\nEnter a new illness name: ");
            fgets(illnessName, illnessNameSize, stdin);
            illnessName[strcspn(illnessName, "\n")] = '\0';
            break;
    }
}

void set_female_illness_name(female_illness female_illness_selected, char illnessName[], size_t illnessNameSize) {
    switch (female_illness_selected) {
        case PCOS:
            strcpy(illnessName, "Polycystic Ovary Syndrome");
            break;
        case BREAST_CANCER:
            strcpy(illnessName, "Breast Cancer");
            break;
        case OSTEOPOROSIS:
            strcpy(illnessName, "Osteoporosis");
            break;
        case ENDOMETRIOSIS:
            strcpy(illnessName, "Endometriosis");
            break;
        case CERVICAL_CANCER:
            strcpy(illnessName, "Cervical Cancer");
            break;
        case MENSTRUAL_DISORDERS:
            strcpy(illnessName, "Menstrual Disorders");
            break;
        case DEPRESSION_ANXIETY:
            strcpy(illnessName, "Depression and Anxiety");
            break;
        case AUTOIMMUNE_DISEASES:
            strcpy(illnessName, "Autoimmune Diseases");
            break;
        case THYROID_DISORDERS:
            strcpy(illnessName, "Thyroid Disorders");
            break;
        case FIBROIDS:
            strcpy(illnessName, "Fibroids");
            break;
        default:
            printf("\nEnter a new illness name: ");
            fgets(illnessName, illnessNameSize, stdin);
            illnessName[strcspn(illnessName, "\n")] = '\0';
            break;
    }
}

void set_elder_illness_name(elder_illness elder_illness_selected, char illnessName[], size_t illnessNameSize) {
    switch (elder_illness_selected) {
        case ALZHEIMERS:
            strcpy(illnessName, "Alzheimer's Disease");
            break;
        case ARTHRITIS:
            strcpy(illnessName, "Arthritis");
            break;
        case HEART_DISEASE_ELDER:
            strcpy(illnessName, "Heart Disease");
            break;
        case DIABETES:
            strcpy(illnessName, "Diabetes");
            break;
        case OSTEOPOROSIS_ELDERS:
            strcpy(illnessName, "Osteoporosis");
            break;
        case HYPERTENSION:
            strcpy(illnessName, "Hypertension");
            break;
        case PARKINSONS:
            strcpy(illnessName, "Parkinson's Disease");
            break;
        case COPD:
            strcpy(illnessName, "Chronic Obstructive Pulmonary Disease");
            break;
        case CANCER_ELDERS:
            strcpy(illnessName, "Cancer");
            break;
        case DEPRESSION_ELDERS:
            strcpy(illnessName, "Depression");
            break;
        default:
            printf("\nEnter a new illness name: ");
            fgets(illnessName, illnessNameSize, stdin);
            illnessName[strcspn(illnessName, "\n")] = '\0';
            break;
    }
}

void set_male_illness_name(male_illness selected, char illnessName[], size_t illnessNameSize) {
    switch (selected) {
        case HYPERTENSION_MALE:
            strcpy(illnessName, "Hypertension");
            break;
        case DIABETES_MELLITUS:
            strcpy(illnessName, "Diabetes Mellitus");
            break;
        case HEART_DISEASE_MALE:
            strcpy(illnessName, "Heart Disease");
            break;
        case PROSTATE_PROBLEMS:
            strcpy(illnessName, "Prostate Problems");
            break;
        case RESPIRATORY_INFECTIONS:
            strcpy(illnessName, "Respiratory Infections");
            break;
        case DEPRESSION_ANXIETY_MALE:
            strcpy(illnessName, "Depression and Anxiety");
            break;
        case OBESITY:
            strcpy(illnessName, "Obesity");
            break;
        case BACK_PAIN:
            strcpy(illnessName, "Back Pain");
            break;
        case GASTROINTESTINAL_DISORDERS:
            strcpy(illnessName, "Gastrointestinal Disorders");
            break;
        case SKIN_CONDITIONS:
            strcpy(illnessName, "Skin Conditions ");
            break;
        default:
            printf("\nEnter a new illness name: ");
            fgets(illnessName, illnessNameSize, stdin);
            illnessName[strcspn(illnessName, "\n")] = '\0';
            break;
    }
}

void capitalize_first_char(char *str) {
    if (str && str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - ('a' - 'A');
    }
}