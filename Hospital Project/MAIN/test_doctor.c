#include <stdio.h>
#include <string.h>
#include "details.h"
#include "doctor.h"

int main() {
    doctor d;
    strcpy(d.full_name, "Test Doctor");
    memset(d.schedule, 0, sizeof(d.schedule)); // All slots free

    // Book some slots
    book_doctor_slot(&d, Monday, 9);
    book_doctor_slot(&d, Monday, 10);
    book_doctor_slot(&d, Monday, 15);

    // Free a slot
    free_doctor_slot(&d, Monday, 10);

    // Display schedule
    display_doctor_schedule(&d);

    // Display free intervals
    printf("\nFree intervals on Monday:\n");
    display_free_intervals(&d, Monday);

    // Display busy intervals
    printf("\nBusy intervals on Monday:\n");
    display_busy_intervals(&d, Monday);

    return 0;
}