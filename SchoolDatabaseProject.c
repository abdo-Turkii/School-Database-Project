#include<stdio.h>
#include<conio.h>
#include<string.h>
//#define NUM_USERS 300
#define NAME_SIZE 20 
#define GRADE_SIZE 4
// define file parameters
FILE* data = fopen("Data File oF school","a+");
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
void add();   // Function of addition
void print();
void search(); //To search in data storged

/*struct add //Data addtion 
{
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
}database[NUM_USERS];*/


int main(int argc ,char *argv[])
{

    printf("Welcom\n"); // Introduction
    char continu; // To loop the program by (yes/no)
    char choice; // To Select the from menu
    do 
    {
        printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name. \nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\n");
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
            printf("CHOIcE e\n");
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
    
    data = fopen("Data File oF school","a+");
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
    data = fopen("Data File oF school","a+");
    char c;
    //printf("First name\tLastname\tScore\tArabic Grade\tEnlish Grade\tMath Grade");
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
    char c;
    printf("First Name                \t");
    scanf("%s",f_name);
    printf("Last Name                \t");
    scanf("%s",l_name);
    data = fopen("Data File oF school","r");
    c =fscanf(data,"%s,%s,%d,%s,%s,%s\n",f_name,l_name,&score,arabic_grade,english_grade,math_grade);
    while(c = (f_name && l_name))
    { 
        printf ("%c",c); 
    }


}