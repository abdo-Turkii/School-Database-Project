#include<stdio.h>
#include<string.h>
#define NUM_USERS 300
#define NAME_SIZE 20
#define GRADE_SIZE 4
void add(); //To add new name
void print(); //To print all data storged

struct add //Data addtion 
{
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
}database[NUM_USERS];


int main(int argc ,char *argv[])
{
    printf("Welcom\n");
    char continu;
    char choice;
    int counter=0;
    //int *i = &database[0];
    //*(i++);
    do
    {
        printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name. \nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\n");
        scanf(" %c",&choice);
        switch (choice)
        {
            case ('a'): 
            add(&counter);
            counter++;
            break;
            case ('p'):
            print();
            break;
            case ('s'):
            printf("CHOIDE s\n");
            break;
            case ('e'):
            printf("CHOIDE e\n");
            break;
            case ('t'):
            printf("CHOIDE t\n");
            break;
            case ('d'):
            printf("CHOIDE d\n");
            break;
        }
        printf("Do you want to continue(y/n)\n");
        scanf(" %c",&continu);
    } while (continu=='y');








    return 0;
}
void add(int *i)
{
    printf("First Name\t");
    scanf("%s",database[*i].f_name);
    printf("Last Name\t");
    scanf("%s",database[*i].l_name);
    printf("Total score of 100 \t");
    scanf("%d",&database[*i].score);
    printf("Arabic grade (pass/fail)\t");
    scanf("%s",database[*i].arabic_grade);
    printf("English grade(pass/fail)\t");
    scanf("%s",database[*i].english_grade);
    printf("Math grade(pass/fail)\t");
    scanf("%s",database[*i].math_grade); 
}
void print()
{
    for (int i=0;i<400;i++)
    {
        printf(database[i].f_name);
        printf(("\t"),database[i].l_name);
        printf(("\t"),database[i].score);
        printf(("\t"),database[i].arabic_grade);
        printf(("\t"),database[i].english_grade);
        printf(("\t"),database[i].math_grade);
    }
}