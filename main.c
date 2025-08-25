#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int login()
{
    char username[20];
    char password[20];
    char cUser[20] = "Rakib";
    char cPass[20] = "123456";

    printf("Enter User Name : ");
    scanf("%19s", username);
    printf("Enter Password : ");
    scanf("%19s", password);

    if(strcmp(username, cUser) == 0 && strcmp(password, cPass) == 0 )
    {
        printf("Welcome Sir....\n");
        return 1;
    }
    else
    {
        printf("Please Enter Correct Credential\n");
        return 0;
    }
    
}

int main()
{
    int choose;
    if(login())
    {
        return 0;
    }
    return 0;

    do
    {
        printf("\n--- File Explorer ---\n");
        printf("1. Create File\n");
        printf("2. View File\n");
        printf("3. Append to File\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}


