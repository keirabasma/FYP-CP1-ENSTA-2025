#include "details.h"

// Shared arrays for hours and minutes
const int shared_hours[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
const int shared_minutes[60] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };

// Initialize the time object
const time_hours_mins appointment_time = {
    .hour = shared_hours,
    .min = shared_minutes
};

// Child Departments + Pregnant Departments
char *pediatric_departments[] = {"General Pediatrics", "Neonatology / NICU", "Pediatric Growth & Nutrition", "Pediatric Vaccination" };

// Clinical Departments
char *clinical_depts[] = { "Cardiology", "Neurology", "Pediatrics", "Obstetrics & Gynecology", "Orthopedics" };

// Diagnostic & Support Departments
char *diagnostic_depts[] = { "Radiology", "Pathology", "Pharmacy" };

// Administrative & Other Departments
char *admin_depts[] = { "Hospital Administration", "Medical Records", "Security" };

int generateID() {
    // Seed the random number generator using current time
    srand(time(NULL));
    // Generate a number between 1000 and 9999
    return (rand() % 9000) + 1000;
};