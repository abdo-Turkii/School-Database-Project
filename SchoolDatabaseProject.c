#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 1024
#define NAME_SIZE 20 
#define GRADE_SIZE 4
#define LOG_DEBUEGG 0
// define file parameters

// struc to store content of file to sort 
struct top_stu
{
    char name1[NAME_SIZE];
    char name2[NAME_SIZE];
    int t_score;
    char arabic_g[GRADE_SIZE];
    char english_g[GRADE_SIZE];
    char math_g[NAME_SIZE];
};
  
struct info
{
    // creat a pointer to store file name
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
};
 
/*void menu()                                     // Function of Print the menu
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
void add(FILE* data    , char* file_name);       // Function of addition
void print(FILE* data  , char* file_name);      // Function of addition
void search(FILE* data , char* file_name);     // Function to search in data file
void edit(FILE* data   , char* file_name);    // Function of edit
void top(FILE* data    , char* file_name);   // Function of print top 10 of score
void del(FILE* data    , char* file_name);  // Function of delete student

int main(int argc ,char *argv[])
{
    FILE* data ;            //Pointer of File
    char* file_name;       // name of file
    struct info student ; //structure variable
    struct top_stu stu ; //structure variable
    //printf("Program name %s\n", argv[0]);
    //to test the program
    #if LOG_DEBUEGG
        file_name ="data2.csv"; //file under testing
    #else
        file_name = argv[1]; // give file name by user 
    #endif 
    //if user did not enter the file name 
    if (file_name==NULL)
        {
            printf("You did not enter the file name to use it\n.(\"Please, start agin with (program name file name)\".) \n"); //
            exit(1);
        }
    //FILE * data=fopen(file_name ,"a+"); //open or creat file name input by user
    printf("                    Welcome\n"); // Introduction
    //char continu; // To loop the program by (yes/no)
    char choice;   // To Select the from menu
    int i=0;      // To loop the program
    while ( i == 0 )
    {
        printf("================================================================================================\n"); 
        printf("Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name.\nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\nPress 'x' to exit program.\nPlease enter your option then press enter:\n");
        //menu();
        scanf(" %c",&choice);       // Input the selection form menu 
        fflush(stdin);
        switch (choice) // Status of menu
        {
            case ('a'): // To add new name 
                add ( data , file_name);     // Function of addition
                break;
            case ('p'): // To print all data
                print(data , file_name);    // Function of Print all data
                break;
            case ('s'): // To search for a name
                search(data , file_name);  // Function To search for a name
                break;
            case ('e'): // To edit data of the student
                edit(data , file_name);   // Function To edit data of the student
                break;
            case ('t'): // To print top 10 students
                top(data , file_name);    // Function To print top 10 students
                break; 
            case ('d'): // To delete a student
                del(data , file_name);   // Function To delete a student
                break;
            case ('x'): // To exit a student
                printf("The end \n");    // message in the end 
                i++; //to exit loop
                break;
        }
        // To loop the program by (yes/no)
        //printf("\nDo you want to continue(y/n)\n");
        //scanf(" %c",&continu);
        //fclose(data);
    }
    return 0;
}
void add( FILE* data , char* file_name) // Function of addition
{
    struct info student;
    data = fopen(file_name,"a+");               // open file
    printf("First Name                \t"); 
    scanf("%s",student.f_name);
    fprintf(data,"%s,",student.f_name);         // To add First Name in file 
    printf("Last Name                 \t");
    scanf("%s",student.l_name);
    fprintf(data,"%s,",student.l_name);         // To add Last Name in file 
    printf("Total score of 100        \t");
    scanf("%d",&student.score);
    fprintf(data,"%d,",student.score);          // To add total score in file 
    printf("Arabic grade (pass/fail)  \t");
    scanf("%s",student.arabic_grade); 
    fprintf(data,"%s,",student.arabic_grade);   // To add Arabic grade in file
    printf("English grade (pass/fail) \t");
    scanf("%s",student.english_grade); 
    fprintf(data,"%s,",student.english_grade);  // To add English grade in file
    printf("Math grade (pass/fail)    \t");
    scanf("%s",student.math_grade); 
    fprintf(data,"%s\n",student.math_grade);    // To add Math grade in file 
    fclose(data);                              //To close The File
 
}

void print(FILE* data , char* file_name)
{
    struct info student;
    data = fopen(file_name,"r"); //open file
    char *c;          // to store character by character
    char str[MAX];   // to store line by line 
    //c =fscanf(data,"%s %s %d %s %s %s\n",student.f_name,student.l_name,&student.score,student.arabic_grade,student.english_grade,student.math_grade); //to read data from file
    //str[MAX]=fscanf(data,"%19[^,]\t%19[^,]\t%d\t%4[^,]\t%19[^,]\t%s\n",student.f_name,student.l_name,&student.score,student.arabic_grade,student.english_grade,student.math_grade); //to read data from file
    //loop to print all character in file 
    /*while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(data); //to get all character from file
    }*/
    printf("First name Last name score Arabic English Math\n");
    rewind(data);     // to move the file pointer to the beginning of the file stream
    //fgets(str,MAX,data);
    int i=1; // To loop the print
   while(  (fgets(str,MAX,data)) != NULL)
    { 
        // To parsing csv file.
        printf("%d-",i++); //To count names
        c=strtok(str,",");  // to stop when he get ","
         printf("%s\t",c); 
        c=strtok(NULL,",");
         printf("%s\t",c); 
        c=strtok(NULL,",");
         printf("%s\t",c); 
        c=strtok(NULL,",");
         printf("%s\t",c); 
        c=strtok(NULL,",");
         printf("%s\t",c); 
        c=strtok(NULL,",");
         printf("%s\n",c); 
        
    }
    printf("END\n");
    fclose(data); //To close The File
}
void search (FILE* data , char* file_name)
{
    struct info student;
    char *c;               // to 
    char str[MAX];        // to store line by line 
    printf("First Name                \t");
    fflush(stdin);
    scanf("%s",student.f_name);
    data = fopen(file_name,"r"); // open file
    {
        printf ("Loading... \n");
        //loop to print all line in file 
        while(  (fgets(str,MAX,data)) != NULL)
        { 
            if ( strncmp(student.f_name , str ,strlen(student.f_name)) == 0 )
             {
                c=strtok(str,",");
                printf("%s\t",c); 
                c=strtok(NULL,",");
                printf("%s\t",c); 
                c=strtok(NULL,",");
                printf("%s\t",c); 
                c=strtok(NULL,",");
                printf("%s\t",c); 
                c=strtok(NULL,",");
                printf("%s\t",c); 
                c=strtok(NULL,",");
                printf("%s",c);
            }
        }
    }
    printf ("End of search \n");
    fclose(data); //To close The File
}
void edit(FILE* data , char* file_name)
{
    struct info student;  // To definition structure 
    int counter=0;       // to clear student found or not founded
    FILE* temp=fopen("temporary.csv","w"); //Temporary file 
    data = fopen(file_name,"r");   // open file
    char str[MAX];
    //to input name want to edit
    printf("Edit data of Student Enter\n");
    printf("First Name                \t");
    scanf("%s",student.f_name);
    printf("Last Name                 \t");
    scanf("%s",student.l_name);
    strcat(student.f_name ,"," ) ; // to identical format
    strcat(student.f_name ,student.l_name ) ;// To copy without deleted information of student
    //printf("Found: %s",student.f_name);
    //loop to copy data file in temporary file without Student Deleted
    while(  (fgets(str,MAX,data)) != NULL)
    {      
        
        if ( strncmp(student.f_name , str ,strlen(student.f_name)) == 0 ) //To compare data
        {
            strcpy(student.f_name , str );
            printf("Found: %s",student.f_name);
            counter++;
        }
        else if(strncmp(student.f_name , str ,strlen(student.f_name)) != 0)
        {
            fputs(str, temp);     
        }
       
    } 

    //To input new data
    printf("New First Name                \t");
    scanf("%s",student.f_name);
    fprintf(temp,"%s,",student.f_name);
    printf("New Last Name                 \t");
    scanf("%s",student.l_name);
    fprintf(temp,"%s,",student.l_name);
    printf("New Total score of 100        \t");
    scanf("%d",&student.score);
    fprintf(temp,"%d,",student.score);
    printf("New Arabic grade (pass/fail)  \t");
    scanf("%s",student.arabic_grade);
    fprintf(temp,"%s,",student.arabic_grade);
    printf("New English grade (pass/fail) \t");
    scanf("%s",student.english_grade);
    fprintf(temp,"%s,",student.english_grade);
    printf("New Math grade (pass/fail)    \t");
    scanf("%s",student.math_grade);
    fprintf(temp,"%s\n",student.math_grade); //how to end of line and do not mix with next line
    // close our files
    fclose(data);
    fclose(temp);
  
    // delete the original file, give the temporary file the name of the original file
    remove(file_name);
    rename( "temporary.csv" , file_name );
}

/*void edit(FILE* data , char* file_name)
{ 
    int counter1;      //location of pointer
    int counter2;     //to point where start edit
    char str1[MAX];  // to read and compare data
    printf("First Name               \t");
    scanf("%s",student.f_name);
    printf("Last Name                \t");
    scanf("%s",student.l_name);
    strcat(student.f_name ,"," ) ;
    strcat(student.f_name ,student.l_name ) ; // To copy without deleted info of f_name
    data = fopen(file_name,"r+"); // open file
    //To read data and compare
    while(  (fgets(str1,MAX,data)) != NULL)
    {      
        counter1=ftell(data); //-line
        if ( strncmp(student.f_name , str1 ,strlen(student.f_name)) == 0 ) //To compare data
        {
            printf ("%s",str1);                  
           counter2=counter1-(strlen(str1)+1); //to point where start edit
        }
    
    }
    fseek(data , counter2 , SEEK_SET); // to move the pointer in location 
    //To input new data
    printf("New First Name                \t");
    scanf("%s",student.f_name);
    fprintf(data,"%s,",student.f_name);
    printf("New Last Name                 \t");
    scanf("%s",student.l_name);
    fprintf(data,"%s,",student.l_name);
    printf("New Total score of 100        \t");
    scanf("%d",&student.score);
    fprintf(data,"%d,",student.score);
    printf("New Arabic grade (pass/fail)  \t");
    scanf("%s",student.arabic_grade);
    fprintf(data,"%s,",student.arabic_grade);
    printf("New English grade (pass/fail) \t");
    scanf("%s",student.english_grade);
    fprintf(data,"%s,",student.english_grade);
    printf("New Math grade (pass/fail)    \t");
    scanf("%s",student.math_grade);
    fprintf(data,"%s,\n",student.math_grade); //how to end of line and do not mix with next line
    fclose(data); //To close The File
}*/

/*void top (FILE* data , char* file_name)
{
    int c1; 
    int counter1;      //location of pointer
    int counter2;     //to point where start edit
    char str1[MAX];
    char str2[MAX];
    char temp[MAX];   // to read and compare data
    data = fopen(file_name,"r"); // open file
    //To read data and compare
    while(  ((char*) str1 = (fscanf(data,"%s %s %d",student.f_name,student.l_name,&student.score))) != NULL)
    {      
        counter1=ftell(data); //-line
        counter2=counter1-2;
        fseek(data , counter2 , SEEK_END);
        //fscanf(str1,"%d",c1);
        c1=atoi(str1);
        printf("score %d\n",c1);
        if(strcmp(str1,str2) > 0) 
        {
            strcpy(temp , str1);
            strcpy(str1 , str2);
            strcpy(str2 , temp);
        } 
        
       
       //counter2=counter1+22;
    
    }
    printf("score %s\n",str1);
    
    fclose(data); //To close The File
}/*/
void top(FILE* data , char* file_name)
{

    struct top_stu stu[1024],str;
   // structure to store data in array
    int read = 0 ;     // number of data get from file in one line 
    int records = 0 ; // number of line get
    int i,j;         // counters 
    data = fopen( file_name , "r"); // open file to read
    //loop to read and store data in student structure
    do
    {
        //get data line by line
        read = fscanf(data,"%19[^,],%19[^,],%d,%4[^,],%4[^,],%5[^,]",stu[records].name1,stu[records].name2,&stu[records].t_score,stu[records].arabic_g,stu[records].english_g,stu[records].math_g);
        if (read == 6) // get six elements of line
            records++;  
        if (read !=6 && !feof) // if data in file need to edit
        {
            printf("file formant incorrect");
        }
        if (ferror(data)) //Error in reading file
        {
            printf("Error in reading file");
        }
    } while (!feof(data) ); // to read all file
    fclose(data); //to close file
    printf("%d records was read.\n",records); //number of line 
    //for(int i=0;i<records;i++)
    //{
        //printf("%s %s %d\n",stu[i].name1,stu[i].name2,stu[i].t_score);

    //}    
    //loop to sort from high to low score
    for ( i=0;i<records;i++)
    {
        for(  j=i+1;j<records;j++)
        {
            if(stu[i].t_score < stu[j].t_score)
            {
                str = stu[i];
                stu[i] = stu[j];
                stu[j] = str   ;
            }      
        }
    }
    //Use qsort to sort
    //qsort(stu , records , sizeof(stu[0]), compare);
    printf("Top 10 students:\n");
    for (  i = 0; i < 10;i++)//loop to print Top 10 students
   {
      printf("(%d)-%s %s %d \n",j=i+1,stu[i].name1,stu[i].name2,stu[i].t_score);
   }
}
void del(FILE* data , char* file_name) 
{
    struct info student; // To definition structure 
    int counter=0;      // to clear student found or not founded
    FILE* temp=fopen("temporary.csv","w"); //Temporary file 
    data = fopen(file_name,"r"); // open file
    char str[MAX];
    //to input name want to delete
    printf("Delete data of Student\n");
    printf("First Name                \t");
    scanf("%s",student.f_name);
    printf("Last Name                 \t");
    scanf("%s",student.l_name);
    strcat(student.f_name ,"," ) ; // to identical format
    strcat(student.f_name ,student.l_name ) ; // To copy without deleted info of student.f_name
    //printf("Found: %s",student.f_name);
    //loop to copy data file in temporary file without Student Deleted
    while(  (fgets(str,MAX,data)) != NULL)
    {      
        
        if ( strncmp(student.f_name , str ,strlen(student.f_name)) == 0 ) //To compare data
        {
            strcpy(student.f_name , str );
            printf("Found: %s\n",student.f_name);
            counter++;
        }
        else if(strncmp(student.f_name , str ,strlen(student.f_name)) != 0)
        {
            fputs(str, temp);     
        }
       
    } 
    // if statement to clear student found or not founded
    if(counter==0)
    printf("Error: student not found\n");
    else
    printf("Student is deleted\n");
    // close our files
    fclose(data);
    fclose(temp);
  
    // delete the original file, give the temporary file the name of the original file
    remove(file_name);
    rename( "temporary.csv" , file_name );
}