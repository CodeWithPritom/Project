#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "file_log.txt"

// Function prototypes
void writeFile();
void appendFile();
void readFile();
void listFiles();
void deleteFile();
void logFileName(const char *filename);

int main()
{
    int choice;

    while (1)
    {
        // Display menu
        printf("\nFile Manager Menu:\n");
        printf("1. Write (new data, old erased)\n");
        printf("2. Append (add new data)\n");
        printf("3. Read (see file content)\n");
        printf("4. List all created files\n");
        printf("5. Delete a file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice)
        {
            case 1:
                writeFile();
                break;
            case 2:
                appendFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                listFiles();
                break;
            case 5:
                deleteFile();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Write new content to a file
void writeFile()
{
    char filename[100], text[1000];
    FILE *file;

    printf("Enter File Name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    file = fopen(filename, "w");
    if (!file)
    {
        printf("Cannot open file!\n");
        return;
    }

    printf("Enter text to write:\n");
    fgets(text, sizeof(text), stdin);
    fputs(text, file);
    fclose(file);

    printf("Data written successfully!\n");

    logFileName(filename);
}

// Append content to an existing file
void appendFile()
{
    char filename[100], text[1000];
    FILE *file;

    printf("Enter File Name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    file = fopen(filename, "a");
    if (!file)
    {
        printf("Cannot open file!\n");
        return;
    }

    printf("Enter text to append:\n");
    fgets(text, sizeof(text), stdin);
    fputs(text, file);
    fclose(file);

    printf("Data appended successfully!\n");

    logFileName(filename);
}

// Read content from a file
void readFile()
{
    char filename[100];
    FILE *file;
    char ch;

    printf("Enter File Name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    file = fopen(filename, "r");
    if (!file)
    {
        printf("Cannot open file!\n");
        return;
    }

    printf("\n--- File Content ---\n");
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);
    printf("\n--- End of File ---\n");
}

// List all logged files
void listFiles()
{
    FILE *logFile;
    char filename[100];

    logFile = fopen(LOG_FILE, "r");
    if (!logFile)
    {
        printf("No files have been logged yet.\n");
        return;
    }

    printf("\n--- Created Files ---\n");
    while (fgets(filename, sizeof(filename), logFile))
    {
        printf("%s", filename); // fgets keeps newline
    }
    fclose(logFile);
    printf("--- End of List ---\n");
}

// Delete a file and remove from log
void deleteFile()
{
    char filename[100];
    FILE *logFile, *tempFile;
    char tempName[100];

    printf("Enter the file name to delete: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Delete the actual file
    if (remove(filename) == 0)
    {
        printf("File '%s' deleted successfully.\n", filename);
    }
    else
    {
        printf("Error: File '%s' could not be deleted or does not exist.\n", filename);
        return;
    }

    // Update log file
    logFile = fopen(LOG_FILE, "r");
    if (logFile == NULL)
        return;

    tempFile = fopen("temp_log.txt", "w");
    if (tempFile == NULL)
    {
        fclose(logFile);
        return;
    }

    // Copy all lines except the deleted file
    while (fgets(tempName, sizeof(tempName), logFile))
    {
        tempName[strcspn(tempName, "\n")] = 0; // remove newline
        if (strcmp(tempName, filename) != 0)
        {
            fprintf(tempFile, "%s\n", tempName);
        }
    }

    fclose(logFile);
    fclose(tempFile);

    // Replace old log with new log
    remove(LOG_FILE);
    rename("temp_log.txt", LOG_FILE);
}

// Log a file name (avoid duplicates)
void logFileName(const char *filename)
{
    FILE *logFile = fopen(LOG_FILE, "r");
    char temp[100];
    int exists = 0;

    if (logFile)
    {
        while (fgets(temp, sizeof(temp), logFile))
        {
            temp[strcspn(temp, "\n")] = 0; // remove newline
            if (strcmp(temp, filename) == 0)
            {
                exists = 1;
                break;
            }
        }
        fclose(logFile);
    }

    if (!exists)
    {
        logFile = fopen(LOG_FILE, "a");
        if (logFile)
        {
            fprintf(logFile, "%s\n", filename);
            fclose(logFile);
        }
    }
}
