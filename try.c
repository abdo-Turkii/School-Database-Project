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

// Comparison function
/* FUNCTION TO SORT THE RECORD */
void sort()
{
 int a[20], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen("Record", "r");
 while (fread(&stud, sizeof(stud), 1, fpo))
 {
  a[count] = stud.rollno;
  count++;
 }
 c = count;
 for (i = 0; i<count - 1; i++)
 {
  for (j = i + 1; j<count; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
   }
  }
 }
 printf("Roll No.\tName\t\tMark\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   if (a[i] == stud.rollno)
    printf("\n %d\t\t %s \t\t %2f",stud.rollno, stud.name, stud.mark);
  }

 }