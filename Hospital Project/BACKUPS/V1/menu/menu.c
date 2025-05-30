#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "staff.h"

void display_main_menu() {
    int option;
    char input[10];
    int staffId;
    char password[20];
    bool isLoggedIn = false; // Track login status
    do {
        if (!isLoggedIn) {
            // Login menu
            printf(
                "\n"
                "===========================================\n"
                "          Amana's Medical Center           \n"
                "===========================================\n"
                " [1] Login\n"
                " [2] Create Staff Account\n"
                " [3] Exit\n"
                "===========================================\n"
                "Select an option: "
            );
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%d", &option) != 1) { option = -1; } // Handle invalid input
            
            switch (option) {
                case 1: {
                    printf("Enter Staff ID: ");
                    scanf("%d", &staffId);
                    getchar();
                    printf("Enter Password: ");
                    fgets(password, sizeof(password), stdin);
                    password[strcspn(password, "\n")] = '\0'; // Remove newline character
                    
                    login(staffId, password);
                    if (login(staffId, password)) { isLoggedIn = true; }
                    break; }

                case 2: {
                    createAccount();
                    break; }

                case 3: {
                    printf("Exiting...\n");
                    return; } // Exit the program

                default: {
                    printf("Invalid option. Please try again.\n");
                }
            }
        } else {
            // Logged-in menu
            printf(
                "\n"
                "===========================================\n"
                "          Amana's Medical Center           \n"
                "===========================================\n"
                " [1] Patient Management\n"
                " [2] Doctor Management\n"
                " [3] Staff Management\n"
                " [4] Logout\n"
                " [5] Exit\n"
                "===========================================\n"
                "Select an option: "
            );
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%d", &option) != 1) { option = -1; } // Set to an invalid option to trigger the default case
            switch (option) {
                case 1: {
                    printf("Patient Management selected.\n");
                    break;
                }
                case 2: {
                    printf("Doctor Management selected.\n");
                    break;
                }
                case 3: {
                    printf("Staff Management selected.\n");
                    break;
                }
                case 4: {
                    logout();
                    isLoggedIn = false; // Update login status
                    printf("You have been logged out.\n");
                    break;
                }
                case 5: {
                    printf("Exiting...\n");
                    return; // Exit the program
                }
                default: {
                    printf("Invalid option. Please try again.\n");
                }
            }
        }
    } while (true);
} 