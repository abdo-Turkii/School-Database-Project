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
int main(int argc ,char *argv[])
{
    printf("have %d of argmument\n",argc);
    for(int x=0;x<argc;x++)
    printf("have variable %d-%s\n",x+1,argv[x]);
  return 0;
}