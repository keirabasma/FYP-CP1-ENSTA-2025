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
            // Safe for all systems, modern look:
            printf(
                "\n"
                "+---------------------------------------------+\n"
                "|                                             |\n"
                "|         * Amana's Medical Center *          |\n"
                "|                                             |\n"
                "+-----------------+---------------------------+\n"
                "|                 |                           |\n"
                "| [1] Login       | [2] Create Staff Account  |\n"
                "|                 |                           |\n"
                "+-----------------+---------------------------+\n"
                "|                                             |\n"
                "| [3] Exit                                    |\n"
                "|                                             |\n"
                "+---------------------------------------------+\n"
                "                                               \n"
                "> Select an option: "
            );
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%d", &option) != 1) { option = -1; } // Handle invalid input
            printf("\n");
            switch (option) {
                case 1: {
                    printf("\nEnter Staff ID: ");
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
                "        ✿ Amana's Medical Center ✿         \n"
                "===========================================\n"
                " [1] Patient Management\n"
                " [2] Doctor Management\n"
                " [3] Staff Management\n"
                " [4] Logout\n"
                " [5] Exit\n"
                "===========================================\n"
                "✱ Select an option: "
            );
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%d", &option) != 1) { option = -1; } // Set to an invalid option to trigger the default case
            switch (option) {
                case 1: {
                    int option_1;
                    do {
                        printf("Patient Management selected.\n");
                        printf(
                            "=================================="
                            "\n--- ✱ PATIENT MANAGEMENT ✱ ---\n"
                            "==================================\n"
                            " 1). Add New Patient\n"
                            " 2). View Patient List\n"
                            " 3). Assign Doctor to Patient\n"
                            " 4). Discharge Patient\n"
                            " 5). View Discharged Patients\n"
                            " 6). Undo Last Discharge\n"
                            " 0). Back to Main Menu\n"
                            "==============================\n"
                            "✱ Select an option: "
                        );
                        fgets(input, sizeof(input), stdin);
                        if (sscanf(input, "%d", &option) != 1) { option = -1; }
                        
                        switch (option_1) {
                            
                            case 1: {
                                printf("Add New Patient selected.\n");
                                break;
                            }
                            
                            case 2: {
                                printf("View Patient List selected.\n");
                                break;
                            }
                            
                            case 3: {
                                printf("Assign Doctor to Patient selected.\n");
                                break;
                            }
                            
                            case 4: {
                                printf("Discharge Patient selected.\n");
                                break;
                            }
                            
                            case 5: {
                                printf("View Discharged Patients selected.\n");
                                break;
                            }
                            
                            case 6: {
                                printf("Undo Last Discharge selected.\n");
                                break;
                            }
                            
                            case 0: {
                                printf("Returning to Main Menu...\n");
                                break;
                            }
                            
                            default: {
                                printf("Invalid option. Please try again.\n");
                            }
                        }
                    } while (option_1 != 0); // Exit submenu
                    break;
                }
                case 2: {
                    int option_2;
                    do {
                        printf("Doctor Management selected.\n");
                        printf(
                            "=============================="
                            "\n--- DOCTOR MANAGEMENT ---\n"
                            "==============================\n"
                            " 1). Add New Doctor\n"
                            " 2). View Doctor List\n"
                            " 3). View Doctor Availability\n"
                            " 0). Back to Main Menu\n"
                            "==============================\n"
                            "Select an option: "
                        );                          
                        fgets(input, sizeof(input), stdin);
                        if (sscanf(input, "%d", &option) != 1) { option = -1; }
                        
                        switch (option_2) {
                            
                            case 1: {
                                printf("Add New Doctor selected.\n");
                                break;
                            }
                            
                            case 2: {
                                printf("View Doctor List selected.\n");
                                break;
                            }
                            
                            case 3: {
                                printf("View Doctor Availability selected.\n");
                                break;
                            }

                            case 0: {
                                printf("Returning to Main Menu...\n");
                                break;
                            }
                            
                            default: {
                                printf("Invalid option. Please try again.\n");
                            }
                        }
                    } while (option_2 != 0); // Exit submenu
                    break;
                }
                case 3: {
                    int option_3;
                    do {
                        printf("Staff Management selected.\n");
                        printf(
                            "=============================="
                            "\n--- STAFF MANAGEMENT ---\n"
                            "==============================\n"
                            " 1). Add New Staff Member\n"
                            " 2). View Staff List\n"
                            " 0). Back to Main Menu\n"
                            "==============================\n"
                            "Select an option: "
                        );                          
                        fgets(input, sizeof(input), stdin);
                        if (sscanf(input, "%d", &option) != 1) { option = -1; }
                        
                        switch (option_3) {
                            
                            case 1: {
                                printf("Add New Staff Member selected.\n");
                                break;
                            }
                            
                            case 2: {
                                printf("View Staff List selected.\n");
                                break;
                            }
                            
                            case 0: {
                                printf("Returning to Main Menu...\n");
                                break;
                            }
                            
                            default: {
                                printf("Invalid option. Please try again.\n");
                            }
                        }
                    } while (option_3 != 0); // Exit submenu
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