#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "doctor.h"
#include "processes.h"
#include "systems.h"
#include "patient.h"
#include "staff.h"

int loggedInStaffId = -1; // -1 indicates no staff is logged in

void createAccount() {
    StaffAccount account;
    FILE *file = fopen(ACCOUNT_FILE, "ab");
    if (!file) {
        printf("Error: Could not open account file.\n");
        return;
    }

    printf("Enter Staff ID: ");
    scanf("%d", &account.staffId);
    printf("Enter Password: ");
    scanf("%s", account.password);

    fwrite(&account, sizeof(StaffAccount), 1, file);
    fclose(file);

    printf("Account created successfully!\n");
}

int login(int staffId, const char* password) {
    StaffAccount account;
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (!file) {
        printf("Error: Could not open account file.\n");
        return 0;
    }

    while (fread(&account, sizeof(StaffAccount), 1, file)) {
        if (account.staffId == staffId && strcmp(account.password, password) == 0) {
            loggedInStaffId = staffId;
            fclose(file);
            printf("Login successful! Welcome, Staff ID: %d\n", staffId);
            return 1;
        }
    }

    fclose(file);
    printf("Invalid Staff ID or Password.\n");
    return 0;
}

void logout() {
    if (loggedInStaffId != -1) {
        printf("Staff ID %d logged out successfully.\n", loggedInStaffId);
        loggedInStaffId = -1;
    } else {
        printf("No staff is currently logged in.\n");
    }
}

