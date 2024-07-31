/*******************************************************************************
*
* Program: Delete Specific Line From A File 
* 
* Description: Example of deleting a specific line from a in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=NRA46yNC_P0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// set some generous maximum lengths for filename size and each line in a file
#define FILENAME_SIZE 1024
#define MAX 2048

// our program will work by writing all of the original file content to a 
// temp file EXCEPT for the line we want to delete, and then we'll delete the 
// original file and rename the temp file to the original file name
int main()
{
   int counter=0; // to clear student found or not founded
    FILE* temp=fopen("temporary2.csv","w"); //Temporary file 
    FILE* data = fopen("school_project database2.csv","r"); // open file
    char str[MAX];
        char f_name[MAX];

    char l_name[MAX];

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
    if(counter==0)
    printf("Error: student not found");
    else
    printf("Student is deleted");
    // close our files
    fclose(data);
    fclose(temp);
  
    // delete the original file, give the temporary file the name of the original file
    remove( "school_project database2.csv" );
    rename( "temporary2.csv" , "school_project database2.csv" );
    remove( "school_project database2.csv" );

  return 0;
}