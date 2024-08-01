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
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main() {
   char * arr[] = {"ahmed 6" ,"sara 5","faten 4" ,"aseel 8","zezo 10"} ;
   int n = sizeof(arr) / sizeof(arr[0]);
  int i;
   for (i = 0; i < n; ++i) {
      printf("%s ", arr[i]);
   }
   qsort(arr, n, sizeof(int), compare);

   printf("\nFollowing is the sorted array: ");
   
   
   for (i = 0; i < n; ++i) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   return 0;
}