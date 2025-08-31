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


        int ch, count=0;
        char filename[10], text[100];

        /*
            char* text = (char*)malloc(maxsize * sizeof(char));
        if(text == NULL)
        {
        printf("Memory allocation failed!\n");
        return;
        }
        */

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
        getchar(); // consume leftover newline

        fgets(text, sizeof(text), stdin);
        // fgets(text, maxsize, stdin);
        fputs(text, file);

        fclose(file);

        // Count characters
        file = fopen(filename, "r");


        count = strlen(text);  // count characters from text

        if(count > 100)
        {
            //Warning Message
            printf("\nYour file content : greater that 1000 character. You surpass your character limit\n");
            fclose(file);
            return;
        }


        //Promotional Message
        printf("\nYour file content : %d character. Max Character Limit : %d . To increase character limit pay 100 BDT\n",count,sizeof(text));
        fclose(file);


        printf("\n===Data written successfully===\n");

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

//Member 2 : Note Pad Integration

void note_pad()
{

}








//Member 3 : Student Database Integration



   // ===== Student Database =====

   
    typedef struct StudentDatabase {
    int ID;
    char name[50];
    float attendance;
    float avg_marks;
    char grade[3];
} database;

void add_student();
void view_student();

int stu_data(){
    int choice1;

    printf("Enter your choice:\n");
    printf("1. Student Database\n");
    printf("2. Exit\n");
    scanf("%d", &choice1);

    switch (choice1) {
        case 1: {
            printf("------ Student Database ------\n");
            printf("Click:\n1. Show details\n2. Add new\n3. Back\n");

            int choice2;
            scanf("%d", &choice2);

            switch (choice2) {
                case 1:
                    view_student();
                    break;
                case 2:
                    add_student();
                    break;
                case 3:
                    printf("Back\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
            break;
        }
        case 2:
            printf("Exit\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void add_student() {
    int n;
    printf("How many students data you want to store?\n");
    scanf("%d", &n);
    
    database std[n];

    int total_class;
    printf("Enter total classes: ");
    scanf("%d", &total_class);

    int n_sub;
    printf("How many subjects marks you want to calculate?\n");
    scanf("%d", &n_sub);

    FILE *file = fopen("students.txt", "a");
    if (file == NULL) {
        printf("File is not opened!\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {   
        fprintf(file, "%-10s %-15s %-15s %-15s %-10s\n", 
                "ID", "Name", "Attendance", "AverageMarks", "Grade");
        fprintf(file, "-------------------------------------------------------------\n");
    }

    for (int i = 0; i < n; i++) {   
        int attended_class, sub_sum = 0;

        // id
        printf("Enter ID of student :\n");
        scanf("%d", &std[i].ID);

        // name
        printf("Enter name of student:\n");
        scanf("%s", std[i].name);
        
        // attendance
        printf("Attended classes of student :\n");
        scanf("%d", &attended_class);
        std[i].attendance = ((float) attended_class / total_class) * 100;

        // avg marks
        int sub_marks[n_sub];
        for (int j = 0; j < n_sub; j++) {
            printf("Subject %d mark:\n", j + 1);
            scanf("%d", &sub_marks[j]);
            sub_sum += sub_marks[j];
        }

        std[i].avg_marks = (float)sub_sum / n_sub;

        // grade
        if (std[i].avg_marks >= 80 && std[i].avg_marks <= 100)
            strcpy(std[i].grade, "A+");
        else if (std[i].avg_marks >= 75 && std[i].avg_marks <= 79)
            strcpy(std[i].grade, "A");
        else if (std[i].avg_marks >= 70 && std[i].avg_marks <= 74)
            strcpy(std[i].grade, "A-");
        else if (std[i].avg_marks >= 65 && std[i].avg_marks <= 69)
            strcpy(std[i].grade, "B+");
        else if (std[i].avg_marks >= 60 && std[i].avg_marks <= 64)
            strcpy(std[i].grade, "B");
        else if (std[i].avg_marks >= 55 && std[i].avg_marks <= 59)
            strcpy(std[i].grade, "B-");
        else if (std[i].avg_marks >= 50 && std[i].avg_marks <= 54)
            strcpy(std[i].grade, "C+");
        else if (std[i].avg_marks >= 45 && std[i].avg_marks <= 49)
            strcpy(std[i].grade, "C");
        else if (std[i].avg_marks >= 40 && std[i].avg_marks <= 44)
            strcpy(std[i].grade, "D");
        else if (std[i].avg_marks < 40)
            strcpy(std[i].grade, "F");
        else
            printf("Invalid input!");

            fprintf(file, "%-10d %-15s %-14.2f %-15.2f %-10s\n",std[i].ID, std[i].name, std[i].attendance, std[i].avg_marks, std[i].grade);
        }

    fclose(file);
}

void view_student() {
    char data[100];
    FILE *file = fopen("students.txt", "r");

    fgets(data, 100, file);
    printf("%s", data);
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


