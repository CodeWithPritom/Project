#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Login is Created by CodeWithPritom

int login() //Member 1 : Login
{
    printf("Welcome to Mini Terminal OS Simulator\n");

    FILE* fp;

    char username[20];
    char password[20];
    char cUser[20];
    char cPass[20];
    int isfound = 0;

    printf("Enter User Name : ");
    fgets(username, sizeof (username), stdin);
    strtok(username,"\n");

    //Username has no spaces.
    if( strchr(username, ' ') != NULL) //strchr search a character in string
    {
        printf("Please do not use any space");
        return 0;
    }

    printf("Enter Password : ");
    scanf("%19s", password);

    fp = fopen("user.txt","r");

    //check user name and password credential
    while(fscanf(fp, "%19s %19s", cUser, cPass)==2)
    {

        if(strcmp(username, cUser) == 0 && strcmp(password, cPass) == 0 )
        {
            isfound = 1;
            break;
        }
    }

    fclose(fp);

    if(isfound)
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




//Member 2 : Logic File Explorer


#define log "file_list.txt"


int file_exp()
{
    //Function Prototypes
    void logfiles(char *filename)
    {
        FILE *filelist = fopen(log,"a");

        fprintf(filelist, "%s\n", filename);
        fclose(filelist);


    }


    void writefile()
    {
        FILE *file;

        char filename[100], text[1000];

        printf("\nEnter File Name : ");
        getchar();
        fgets(filename, sizeof(filename), stdin);
        strtok(filename,"\n");

        file = fopen(filename, "w");

        if(!file)
        {
            printf("\nCannot open file!\n");
            return;
        }

        printf("\nEnter text to write : \n");

        fgets(text, sizeof(text), stdin);
        fputs(text, file);
        fclose(file);

        printf("\nData written successfully\n");

        //filename go to logfiles() function
        logfiles(filename);


    }
    void readfile()
    {

    }
    void appendfile()
    {

    }
    void filelist()
    {
        FILE *listfile;
        char filename[100];

        listfile = fopen(log,"r");

        if(!listfile)
        {
            printf("\nNo files have been created\n");
            return;
        }

        printf("\n==== Your Created Files ====\n");

        while(fgets(filename, sizeof(filename), listfile) != NULL)
        {
            {
                printf("%s",filename);
            }
        }

        fclose(listfile);

        printf("\n==== List End ====\n");

    }
    void deletefile()
    {

    }

    int choice;

    while(1)
    {
        //Menu
        printf("\n==== File Manager Menu ====\n");
        printf("1. Create and Write File ( If input file and existing file same previous content will remove )\n");
        printf("2. Read File\n");
        printf("3. Add text in your existing file\n");
        printf("4. List of all files you created\n");
        printf("5. Delete file\n");
        printf("6. Exit\n");

        printf("Enter Your Choice : \n");
        scanf("%d",&choice);

        //Swtich statement for choices
        switch(choice)
        {

        case 1 :
            writefile();
            break;
        case 2 :
            readfile();
            break;
        case 3 :
            appendfile();
            break;
        case 4 :
            filelist();
            break;
        case 5 :
            deletefile();
            break;
        case 6 :
            printf("\nAbar Asiben Dhonnobad\n");

            return 0;
        default :
            printf("\nEnter Valid Choice\n");

        }
    }

    return 0;
}


//Member 3 : Note Pad Integration

void note_pad()
{

}

//Member 4 : Student Database Integration

void stu_data()
{

}



void SysInfo() // Member 1
{
    printf("==== System Information ====\n");
    system("systeminfo");   // Windows command to print system info

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
        printf("4. System Information\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1 :
            file_exp();
            break;
        case 2 :
            note_pad();
            break;
        case 3 :
            stu_data();
            break;
        case 4 :
            SysInfo();
            break;
        default :
            if(option < 0 || option > 4)
            {
                printf("\nPlease Enter Valid Choice! or ShutDown me!\n");
            }
        }
    }
    while(option != 0 );

    printf("\nGood Bye Sir... Miss You :')\n");
    return 0;
}


