#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 1024
#define NAME_SIZE 20 
#define GRADE_SIZE 4
// define file parameters
    FILE* data ;
    char* file_name;  // creat a pointer to store file name
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
/*void menu()        // Function of Print the meue
{
    char c;
    FILE* menu = fopen("Main Menu","a+");
    //fprintf(menu,"Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name. \nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\n");
    rewind(menu);
    while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(menu); 
    }
    printf("\n");
}    */
void add();       // Function of addition
void print();    // Function of addition
void search();  // Function to search in data storged
void edit();   // Function of edit
void del();   // Function of delete student

int main(int argc ,char *argv[])
{
    //printf("have %d of argmument\n",argc);
    //printf("Program name %s\n", argv[0]);
    //file_name = "data2.csv";
    file_name = argv[1]; // give file name by user 
    //FILE * data=fopen(file_name ,"a+"); //open or creat file name input by user
    printf("                       Welcom\n"); // Introduction
    char continu; // To loop the program by (yes/no)
    char choice; // To Select the from menu
    do 
    {
        printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name. \nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\n");
        //menu();
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
            del();
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
    
    data = fopen(file_name,"a+"); // open file
    printf("First Name                \t"); 
    scanf("%s",f_name);
    fprintf(data,"%s ",f_name);         // To add First Name in file 
    printf("Last Name                 \t");
    scanf("%s",l_name);
    fprintf(data,"%s ",l_name);         // To add Last Name in file 
    printf("Total score of 100        \t");
    scanf("%d",&score);
    fprintf(data,"%d ",score);          // To add total score in file 
    printf("Arabic grade (pass/fail)  \t");
    scanf("%s",arabic_grade); 
    fprintf(data,"%s ",arabic_grade);   // To add Arabic grade in file
    printf("English grade (pass/fail) \t");
    scanf("%s",english_grade); 
    fprintf(data,"%s ",english_grade);  // To add English grade in file
    printf("Math grade (pass/fail)    \t");
    scanf("%s",math_grade); 
    fprintf(data,"%s \n",math_grade);   // To add Math grade in file 
    
    fclose(data); //To close The File

}

void print()
{
    data = fopen(file_name,"a+"); // open file
    char c; // to store character by character 
    printf("First name,Lastname,Score,Arabic Grade,Enlish Grade,Math Grade\n");
    c =fscanf(data,"%s %s %d %s %s %s\n",f_name,l_name,&score,arabic_grade,english_grade,math_grade); //to read data from file
    rewind(data); // to move the file pointer to the beginning of the file stream
    //loop to print all character in file 
    while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(data); //to get all character from file
    }
    printf("END\n");
    fclose(data); //To close The File
}
void search ()
{
    
    char str[MAX];        // to store line by line 
    printf("First Name                \t");
    scanf("%s",f_name);
    data = fopen(file_name,"r"); // open file
    {
        printf ("Loading... \n");
        //loop to print all line in file 
        while(  (fgets(str,MAX,data)) != NULL)
    { 
        if ( strncmp(f_name , str ,strlen(f_name)) == 0 )
        printf ("%s",str);  //to print line where the pointer is existing
    }
    }
    printf ("End of search \n");
    fclose(data); //To close The File
}

void edit()
{ 
    int counter1;      //location of pointer
    int counter2;     //to point where start edit
    char str1[MAX];  // to read and compare data
    printf("First Name               \t");
    scanf("%s",f_name);
    printf("Last Name                \t");
    scanf("%s",l_name);
    strcat(f_name , l_name ) ; // To copy without deleted info of f_name
    data = fopen(file_name,"r+"); // open file
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
    fprintf(data,"%s ",f_name);
    printf("New Last Name                 \t");
    scanf("%s",l_name);
    fprintf(data,"%s ",l_name);
    printf("New Total score of 100        \t");
    scanf("%d",&score);
    fprintf(data,"%d ",score);
    printf("New Arabic grade (pass/fail)  \t");
    scanf("%s",arabic_grade);
    fprintf(data,"%s ",arabic_grade);
    printf("New English grade (pass/fail) \t");
    scanf("%s",english_grade);
    fprintf(data,"%s ",english_grade);
    printf("New Math grade (pass/fail)    \t");
    scanf("%s",math_grade);
    fprintf(data,"%s \n",math_grade); //how to end of line and do not mix with next line
    fclose(data); //To close The File
}
void del() 
{
    int counter=0; // to clear student found or not founded
    FILE* temp=fopen("temporary.csv","w"); //Temporary file 
    data = fopen(file_name,"r"); // open file
    char str[MAX];
    printf("Delete data of Student\n");
    printf("First Name                \t");
    scanf("%s",f_name);
    printf("Last Name                 \t");
    scanf("%s",l_name);
    strcat(f_name , l_name ) ; // To copy without deleted info of f_name
    //loop to copy data file in temporary file without Student Deleted
    while(  (fgets(str,1024,data)) != NULL)
    {      
        
        if ( strncmp(f_name , str ,strlen(f_name)) == 0 ) //To compare data
        {
            strcpy(f_name , str );
            printf("Found: %s",f_name);
            counter++;
        }
        else if(strncmp(f_name , str ,strlen(f_name)) != 0)
        {
            fputs(str, temp);     
        }
       
    } 
    // if statment to clear student found or not founded
    if(counter==0)
    printf("Error: student not found");
    else
    printf("Student is deleted");
    // close our files
    fclose(data);
    fclose(temp);
  
    // delete the original file, give the temporary file the name of the original file
    remove(file_name);
    rename( "temporary.csv" , file_name );
}
