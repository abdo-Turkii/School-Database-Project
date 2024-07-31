#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#define NUM_USERS 300
#define NAME_SIZE 20 
#define GRADE_SIZE 4
// define file parameters
FILE* data = fopen("school_project database.csv","a+");
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
void menu() // Function of Print the meue
{
    char c;
    FILE* menu = fopen("Main Menu","r");
    rewind(menu);
    while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(menu); 
    }
}    
void add();    // Function of addition
void print();  // Function of addition
void search(); //Function to search in data storged
void edit();   // Function of edit


int main(int argc ,char *argv[])
{
    printf("Program name %s\n", argv[0]);
    printf("Welcom\n"); // Introduction
    char continu; // To loop the program by (yes/no)
    char choice; // To Select the from menu
    do 
    {
        //printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name. \nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\n");
        menu();
        scanf(" %c",&choice); // Input the selection form menu 
        switch (choice) // Status of menu
        {
            case ('a'): // To add new name 
            add();     // Function of addition
            break;
            case ('p'): // To print all data
            print();    // Function of Print all data
            break;
            case ('s'): // To search for a name
            search();
            break;
            case ('e'): // To edit the enteries of the student
            edit();
            break;
            case ('t'): // To print top 10 students
            printf("CHOIcE t\n");
            break;
            case ('d'): // To delete a student
            printf("CHOIce d\n");
           break;
        }
        // To loop the program by (yes/no)
        printf("\nDo you want to continue(y/n)\n");
        scanf(" %c",&continu);
    } while (continu=='y'); 
    
    fclose(data);

    return 0;
}
void add() // Function of addition
{
    
    data = fopen("school_project database.csv","a+");
    printf("First Name                \t");
    scanf("%s",f_name);
    fprintf(data,"%s,",f_name);
    printf("Last Name                 \t");
    scanf("%s",l_name);
    fprintf(data,"%s,",l_name);
    printf("Total score of 100        \t");
    scanf("%d",&score);
    fprintf(data,"%d,",score);
    printf("Arabic grade (pass/fail)  \t");
    scanf("%s",arabic_grade);
    fprintf(data,"%s,",arabic_grade);
    printf("English grade (pass/fail) \t");
    scanf("%s",english_grade);
    fprintf(data,"%s,",english_grade);
    printf("Math grade (pass/fail)    \t");
    scanf("%s",math_grade); 
    fprintf(data,"%s \n",math_grade);
    
    fclose(data);

}

void print()
{
    data = fopen("school_project database.csv","a+");
    char c;
    printf("First name,Lastname,Score,Arabic Grade,Enlish Grade,Math Grade\n");
    c =fscanf(data,"%s,%s,%d,%s,%s,%s\n",f_name,l_name,&score,arabic_grade,english_grade,math_grade);
    rewind(data);
    while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(data); 
    }
}
void search ()
{
    int i;
    char str[1024];
    printf("First Name                \t");
    scanf("%s",f_name);
    data = fopen("school_project database.csv","r");
    {printf ("Loading... \n");
        while(  (fgets(str,1024,data)) != NULL)
    { 
        if ( strncmp(f_name , str ,strlen(f_name)) == 0 )
        printf ("%s",str); 

    }
    }
    printf ("End of search \n"); 
}

void edit()
{ 
    int counter1;      //location of pointer
    int counter2;     //to point where start edit
    char str1[1024]; // to read and compare data
    printf("First Name               \t");
    scanf("%s",f_name);
    printf("Last Name                \t");
    scanf("%s",l_name);
    strcat(f_name , l_name ) ; // To copy without deleted info of f_name
    data = fopen("school_project database.csv","r+"); // open file
    //To read data and compare
    while(  (fgets(str1,1024,data)) != NULL)
    {      
        counter1=ftell(data); //-line
        if ( strncmp(f_name , str1 ,strlen(f_name)) == 0 ) //To compare data
        {
            printf ("%s",str1);                  
           counter2=counter1-(strlen(str1)+1); //to point where start edit
        }
    
    }
    fseek(data , counter2 , SEEK_SET); // to move the pointer in location 
    //To input new data
    printf("New First Name                \t");
    scanf("%s",f_name);
    fprintf(data,"%s,",f_name);
    printf("New Last Name                 \t");
    scanf("%s",l_name);
    fprintf(data,"%s,",l_name);
    printf("New Total score of 100        \t");
    scanf("%d",&score);
    fprintf(data,"%d,",score);
    printf("New Arabic grade (pass/fail)  \t");
    scanf("%s",arabic_grade);
    fprintf(data,"%s,",arabic_grade);
    printf("New English grade (pass/fail) \t");
    scanf("%s",english_grade);
    fprintf(data,"%s,",english_grade);
    printf("New Math grade (pass/fail)    \t");
    scanf("%s",math_grade);
    fprintf(data,"%s \n",math_grade); //how to end of line and do not mix with next line
  
}