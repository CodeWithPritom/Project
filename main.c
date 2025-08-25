#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Login is Created by CodeWithPritom

int login()
{
    printf("Welcome to Mini Terminal OS Simulator\n");

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

//Member 1 : Logic File Explorer

void file_exp()
{

}

//Member 2 : Note Pad Integration

void note_pad()
{

}

//Member 3 : Student Database Integration

void stu_data()
{

}



// Main is Create by CodeWithPritom

int main()
{
    int option = 0;

    if(!login())
    {
        return 0;
    }

    do
    {
        printf("\n===== Main Menu =====\n");
        printf("1. File Explorer\n");   // Member 2
        printf("2. Note Pad\n");    // Member 3
        printf("3. Student Database\n"); // Member 4
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1 : file_exp();
            case 2 : note_pad();
            case 3 : stu_data();
            default : 
            if(option < 0 || option > 3)
            {
            printf("\nPlease Enter Valid Choice! or ShutDown me!\n");
            }
        }
    }while(option != 0 );

    printf("\nGood Bye Sir... Miss You :')\n");
    return 0;
}


