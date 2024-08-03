#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 1024
#define NAME_SIZE 20 
#define GRADE_SIZE 4
// define file parameters
  struct info
  {
    FILE* data ;
    char* file_name;  // creat a pointer to store file name
    char f_name[NAME_SIZE];
    char l_name[NAME_SIZE];
    int  score ;
    char arabic_grade[GRADE_SIZE];
    char english_grade[GRADE_SIZE];
    char math_grade[GRADE_SIZE];
  }b;
  
/*void menu()      // Function of Print the meue
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
void top();   // Function of print top 10 of score
void del();  // Function of delete student

int main(int argc ,char *argv[])
{
    //printf("have %d of argmument\n",argc);
    //printf("Program name %s\n", argv[0]);
    b.file_name = "data2.csv";
    //b.file_name = argv[1]; // give file name by user 
    //FILE * data=fopen(file_name ,"a+"); //open or creat file name input by user
    printf("                    Welcom\n"); // Introduction
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
            top();
            break;
            case ('d'): // To delete a student
            del();
           break;
        }
        // To loop the program by (yes/no)
        printf("\nDo you want to continue(y/n)\n");
        scanf(" %c",&continu);
    } while (continu=='y'); 
    
    fclose(b.data);

    return 0;
}
void add() // Function of addition
{
    
    b.data = fopen(b.file_name,"a+"); // open file
    printf("First Name                \t"); 
    scanf("%s",b.f_name);
    fprintf(b.data,"%s ",b.f_name);         // To add First Name in file 
    printf("Last Name                 \t");
    scanf("%s",b.l_name);
    fprintf(b.data,"%s ",b.l_name);         // To add Last Name in file 
    printf("Total b.score of 100        \t");
    scanf("%d",&b.score);
    fprintf(b.data,"%d ",b.score);          // To add total b.score in file 
    printf("Arabic grade (pass/fail)  \t");
    scanf("%s",b.arabic_grade); 
    fprintf(b.data,"%s ",b.arabic_grade);   // To add Arabic grade in file
    printf("English grade (pass/fail) \t");
    scanf("%s",b.english_grade); 
    fprintf(b.data,"%s ",b.english_grade);  // To add English grade in file
    printf("Math grade (pass/fail)    \t");
    scanf("%s",b.math_grade); 
    fprintf(b.data,"%s \n",b.math_grade);   // To add Math grade in file 
    
    fclose(b.data); //To close The File

}

void print()
{
    b.data = fopen(b.file_name,"a+"); // open file
    char c; // to store character by character 
    printf("First name,Lastname,b.score,Arabic Grade,Enlish Grade,Math Grade\n");
    c =fscanf(b.data,"%s %s %d %s %s %s\n",b.f_name,b.l_name,&b.score,b.arabic_grade,b.english_grade,b.math_grade); //to read data from file
    rewind(b.data); // to move the file pointer to the beginning of the file stream
    //loop to print all character in file 
    while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(b.data); //to get all character from file
    }
    printf("END\n");
    fclose(b.data); //To close The File
}
void search ()
{
    
    char str[MAX];        // to store line by line 
    printf("First Name                \t");
    scanf("%s",b.f_name);
    b.data = fopen(b.file_name,"r"); // open file
    {
        printf ("Loading... \n");
        //loop to print all line in file 
        while(  (fgets(str,MAX,b.data)) != NULL)
    { 
        if ( strncmp(b.f_name , str ,strlen(b.f_name)) == 0 )
        printf ("%s",str);  //to print line where the pointer is existing
    }
    }
    printf ("End of search \n");
    fclose(b.data); //To close The File
}

void edit()
{ 
    int counter1;      //location of pointer
    int counter2;     //to point where start edit
    char str1[MAX];  // to read and compare data
    printf("First Name               \t");
    scanf("%s",b.f_name);
    printf("Last Name                \t");
    scanf("%s",b.l_name);
    strcat(b.f_name ," " ) ;
    strcat(b.f_name ,b.l_name ) ; // To copy without deleted info of b.f_name
    b.data = fopen(b.file_name,"r+"); // open file
    //To read data and compare
    while(  (fgets(str1,MAX,b.data)) != NULL)
    {      
        counter1=ftell(b.data); //-line
        if ( strncmp(b.f_name , str1 ,strlen(b.f_name)) == 0 ) //To compare data
        {
            printf ("%s",str1);                  
           counter2=counter1-(strlen(str1)+1); //to point where start edit
        }
    
    }
    fseek(b.data , counter2 , SEEK_SET); // to move the pointer in location 
    //To input new data
    printf("New First Name                \t");
    scanf("%s",b.f_name);
    fprintf(b.data,"%s ",b.f_name);
    printf("New Last Name                 \t");
    scanf("%s",b.l_name);
    fprintf(b.data,"%s ",b.l_name);
    printf("New Total b.score of 100        \t");
    scanf("%d",&b.score);
    fprintf(b.data,"%d ",b.score);
    printf("New Arabic grade (pass/fail)  \t");
    scanf("%s",b.arabic_grade);
    fprintf(b.data,"%s ",b.arabic_grade);
    printf("New English grade (pass/fail) \t");
    scanf("%s",b.english_grade);
    fprintf(b.data,"%s ",b.english_grade);
    printf("New Math grade (pass/fail)    \t");
    scanf("%s",b.math_grade);
    fprintf(b.data,"%s \n",b.math_grade); //how to end of line and do not mix with next line
    fclose(b.data); //To close The File
}
// Comparison function
int compare(const void *arg1, const void *arg2)
{
   return strcasecmp(*(const char **)arg1, *(const char **)arg2);
}
void top ()
{
    int c1; 
    int counter1;      //location of pointer
    int counter2;     //to point where start edit
    char str1[MAX];
    char str2[MAX];
    char temp[MAX];   // to read and compare data
    b.data = fopen(b.file_name,"r+"); // open file
    //To read data and compare
    while(  (fgets(str1,MAX,b.data)) != NULL)
    {      
        counter1=ftell(b.data); //-line
        counter2=counter1-19;
        fseek(b.data , counter2 , SEEK_END);
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
    
    fclose(b.data); //To close The File
}
/*void top()
{
    //char str[MAX];
   info *s , s1;
   int i ,j ;
   // Size of the array
   b.data=fopen(b.file_name, "r");
   fseek(b.data,0,SEEK_END);
   int n =ftell(b.data)/ sizeof(info);
   s = (info*)calloc(n,sizeof(info));
   rewind(b.data);
   for(i=0;i<n;i++)
        fread(&s[i],sizeof(info),3,b.data);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i].score < s[j].score)
            {
                s1=s[i];
                s[i]=s[j];
                s[j]=s1;
            }
        }
    }  
    
    for(i=0;i<2;i++)
    {
        printf(" %d\n",s[i].score);
    }

    //Use qsort to sort
   //qsort(b.data, size, sizeof(char *), compare);
   //printf("Following is the sorted File: ");
//////while(  (fgets(str,MAX,b.data)) != NULL)
    //{      
    //    printf("%s",str);
   // }
    
fclose(b.data);
}*/
void del() 
{
    int counter=0; // to clear student found or not founded
    FILE* temp=fopen("temporary.csv","w"); //Temporary file 
    b.data = fopen(b.file_name,"r"); // open file
    char str[MAX];
    printf("Delete data of Student\n");
    printf("First Name                \t");
    scanf("%s",b.f_name);
    printf("Last Name                 \t");
    scanf("%s",b.l_name);
    strcat(b.f_name ," " ) ;
    strcat(b.f_name ,b.l_name ) ;
    // To copy without deleted info of b.f_name
    //printf("Found: %s",b.f_name);
    //loop to copy data file in temporary file without Student Deleted
    while(  (fgets(str,1024,b.data)) != NULL)
    {      
        
        if ( strncmp(b.f_name , str ,strlen(b.f_name)) == 0 ) //To compare data
        {
            strcpy(b.f_name , str );
            printf("Found: %s",b.f_name);
            counter++;
        }
        else if(strncmp(b.f_name , str ,strlen(b.f_name)) != 0)
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
    fclose(b.data);
    fclose(temp);
  
    // delete the original file, give the temporary file the name of the original file
    remove(b.file_name);
    rename( "temporary.csv" , b.file_name );
}
