#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#define max 1024

int main (int argc, char *argv[])
{

   char* file_name;
   file_name = argv[1];
   FILE * data=fopen(file_name ,"a+");
   return 0;
}