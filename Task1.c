/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Function to create a new file
void createFile() {
    char fileName[100];
    // Prompt the user for the file name
    printf("Enter the name of the file to create: ");
    scanf("%s", fileName);
    // Open the file in write mode
    FILE *file = fopen(fileName, "w");
    if (file == NULL) { // Check if the file was created successfully
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully!\n");
    fclose(file); // Close the file
}

// Function to read and display the contents of a file
void readFile() {
    char fileName[100];
    // Prompt the user for the file name
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);
    // Open the file in read mode
    FILE *file = fopen(fileName, "r");
    if (file == NULL) { // Check if the file was opened successfully
        printf("Error opening file!\n");
        return;
    }
    char ch;
    // Read and display the file character by character
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character to the console
    }
    printf("\n");
    fclose(file); // Close the file
}

// Function to write data to a file
void writeFile() {
    char fileName[100];
    // Prompt the user for the file name
    printf("Enter the name of the file to write: ");
    scanf("%s", fileName);
    // Open the file in write mode
    FILE *file = fopen(fileName, "w");
    if (file == NULL) { // Check if the file was opened successfully
        printf("Error opening file!\n");
        return;
    }
    char data[1000];
    // Prompt the user for the data to write
    printf("Enter data to write to the file: ");
    scanf(" %[^\n]s", data); // Read a full line of input
    fprintf(file, "%s", data); // Write the data to the file
    printf("Data written successfully!\n");
    fclose(file); // Close the file
}

// Function to append data to a file
void appendFile() {
    char fileName[100];
    // Prompt the user for the file name
    printf("Enter the name of the file to append: ");
    scanf("%s", fileName);
    // Open the file in append mode
    FILE *file = fopen(fileName, "a");
    if (file == NULL) { // Check if the file was opened successfully
        printf("Error opening file!\n");
        return;
    }
    char data[1000];
    // Prompt the user for the data to append
    printf("Enter data to append to the file: ");
    scanf(" %[^\n]s", data); // Read a full line of input
    fprintf(file, "%s", data); // Append the data to the file
    printf("Data appended successfully!\n");
    fclose(file); // Close the file
}

// Main function to display a menu and perform file operations
int main() {
    int choice;
    do {
        // Display the menu of file operations
        printf("\nFile Operations:\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write File\n");
        printf("4. Append File\n");
        printf("5. Exit\n");
        // Prompt the user to enter their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Create a new file
                createFile();
                break;
            case 2: // Read an existing file
                readFile();
                break;
            case 3: // Write data to a file
                writeFile();
                break;
            case 4: // Append data to a file
                appendFile();
                break;
            case 5: // Exit the program
                printf("Exiting...\n");
                break;
            default: // Handle invalid menu choices
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5); // Repeat until the user chooses to exit
    return 0; // Indicate successful execution
}