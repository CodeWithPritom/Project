#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 1.file er list dekhabe
void file_list(){
    FILE *fl ;      //file ke access korar jonno
    fl = fopen("sv_file.txt","r"); // open korbo ("naam","ki kaj kore")
    char fname[100];     // pointer or char array;

    if(fl == NULL) printf("File not found -_- ");
    else {
        printf("_Your File_\n");

        while( fgets(fname, sizeof(fname) , fl) != NULL  ){
            printf(" - %s",fname); // fgets e \n ache tai ar lagbena;
        }
            fclose(fl);
            printf("\n");

    }
}
// 2.oppening file
void file_open(){
    char fn[100];  // file er naam newar jonno
    printf("enter the file's name : ");
    scanf("%s", fn);
    getchar();

    FILE *fo = fopen(fn, "r"); // fo namer file khullam + ete fn(str) er jinish rakhbo and er type hobe read

    if(fo == NULL) {  // fo namer file e ksu na thakle kaj korbe
        printf("File name '%s' not found :( ",fn);
        return;           // function terminate kore felbe;
    }

    char ch;          // variable porar jonno and pore print korar jonno character ch;
    printf("\n_File Content_\n\n");

    while(( ch = fgetc(fo)) != EOF){    // file er char porbe . then seitake ch er moddhe rakhbe
        putchar(ch);     //one by one sob char ke print korbe       //EOF = end of file;
    }
    fclose(fo);
    printf("\n__\n");

}

// write file;
void write_file(){
    char filename[100] ; // nam nibo
    char text[2000]; // jinis nibo

    printf("Enter file name to write : ");
    scanf("%s", filename);
    getchar(); // jate input nite somossa na hoy

    FILE *fp = fopen(filename,"w"); // value nibe and type write;
    if(fp == NULL ) {
        printf("Failed to open file! \n");
        return; //terminate function
    }

    printf("Enter your text (type END to stop): \n");

    while(1){
        fgets(text, sizeof(text), stdin);  // text nibe
        if(strcmp(text , "END\n") == 0) break; // END pele shes korbe
        fputs(text , fp);  // print korbe
    }
    fclose(fp);

    FILE *sv = fopen("sv_file.txt","a"); // ja khulbo ta save kore rakhar jonno
    if(sv != NULL){       // sv te jinis thakle kaj korbe
        fprintf(sv,"%s\n",filename);     // filename er jinis file e print korchi + \n
        fclose(sv);                   // prottek new file er naam sv te add hocche;
    }
}

void file_dlt(){
    char filename[100];
    printf("Enter filename to delete : ");
    scanf("%s",filename);
    if( remove(filename) == 0)   // remove function diye delete kora// 0 mane kaj hoyeche
    printf("File has been deleted *_* \n");
    else
    printf("Couldn't delete file. Maybe its non-existing \n");

}


void FileExplorer(){
     while(1){
        int choice;
        //outlooks :)
        printf("\n\n__FILE EXPLORER_\n\n");
        printf("1. List Files\n"); // sob file dekhabe
        printf("2. Open Files\n"); // naam bolle file khulbe
        printf("3. Write File\n"); // naam nibe + oitay likhbe
        printf("4. Delete File\n");// naam niye dlt korbe
    //printf("5. Append File\n"); [tasnim er part]
        printf("6. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch(choice){         //file use korar jonno o⏝o
            case 1: file_list();  break;    // akta pele onno gulay jbena
            case 2: file_open();  break;
            case 3: write_file(); break;
            case 4: file_dlt();   break;
        //case 5: file_append();break;  [tasnim er part]
            case 6: printf("Exiting... :( ");    return; // function terminate korbe
        default: printf("Invalid choice x_x \n");
        }
     }
}

int main(){
    FileExplorer();
    return 0;
}
