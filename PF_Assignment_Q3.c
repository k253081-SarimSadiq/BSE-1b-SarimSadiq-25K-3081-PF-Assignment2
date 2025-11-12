#include <stdio.h>
#include <stdlib.h>

void updateSector(int grid[3][3]);
void SectorStatus(int grid[3][3]);
void SystemDiagnostic(int grid[3][3]);
void Menu();
void clearInputBuffer();

int main() {
    int grid[3][3] = {0};
    int choice;

    while (1) {
        Menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                updateSector(grid);
                break;
            case 2:
                SectorStatus(grid);
                break;
            case 3:
                SystemDiagnostic(grid);
                break;
            case 4:
                printf("\nExiting system...\n");
                system("pause"); // keeps window open in Code::Blocks/Dev-C++
                return 0;
            default:
                printf("Invalid choice entered, try again.\n");
        }
    }

    return 0;
}

void Menu() {
    printf("\n~~~~~~~~~~~~~~~~IESCO POWER GRID MONITORING~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Update Sector Status\n");
    printf("2. Query Sector Status\n");
    printf("3. Run System Diagnostic\n");
    printf("4. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter your choice: ");
}

void updateSector(int grid[3][3]) {
    int row, col, flagChoice, action;

    printf("\nEnter sector coordinates (row col): ");
    if (scanf("%d %d", &row, &col) != 2) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates!\n");
        clearInputBuffer();
        return;
    }

    printf("\nSelect status flag to modify:\n");
    printf("1. Power Status\n");
    printf("2. Overload Warning\n");
    printf("3. Maintenance Required\n");
    printf("Enter choice: ");
    if (scanf("%d", &flagChoice) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }

    printf("Enter action (1 = Set, 0 = Clear): ");
    if (scanf("%d", &action) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }

    int bitFlag;
    switch (flagChoice) {
        case 1: bitFlag = 1; break; // Power
        case 2: bitFlag = 2; break; // Overload
        case 3: bitFlag = 4; break; // Maintenance
        default:
            printf("Invalid flag choice!\n");
            return;
    }

    if (action == 1)
        grid[row][col] |= bitFlag;   // set bit
    else
        grid[row][col] &= ~bitFlag;  // clear bit

    printf("\nSector (%d, %d) updated successfully!\n", row, col);
}

void SectorStatus(int grid[3][3]) {
    int row, col;

    printf("\nEnter sector coordinates (row col): ");
    if (scanf("%d %d", &row, &col) != 2) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates!\n");
        return;
    }

    int status = grid[row][col];
    printf("\n--- Sector (%d, %d) Status Report ---\n", row, col);
    printf("Power Status: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload Warning: %s\n", (status & 2) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & 4) ? "YES" : "NO");
    printf("Encoded Value: %d\n", status);
}

void SystemDiagnostic(int grid[3][3]) {
    int overloadCount = 0, maintenanceCount = 0;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row][col] & 2)
                overloadCount++;
            if (grid[row][col] & 4)
                maintenanceCount++;
        }
    }

    printf("\n=========== SYSTEM DIAGNOSTIC REPORT ===========\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Requiring Maintenance: %d\n", maintenanceCount);
    printf("================================================\n");
}

void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

