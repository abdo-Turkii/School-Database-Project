#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#define max 1024

int main (int argc, char *argv[])
{

   char* file_name;
   file_name="ddd.csv";
   //file_name = argv[1];
   FILE * data=fopen(file_name ,"a+");
   
   // sort the records

   int flag;
   int n = 77;
   for( int i = 1; i < n; i++ )
   {
      flag = 0;
      for( int j = 0; j < n - i; j++ )
      {
          if( atoi( record[j].score ) < atoi( record[j+1].score ) )
          {
              SwapRecords( &record[j], &record[j+1] );
              flag = 1;
          }
      }
      if( flag == 0 )
          break;
   }

   // probably should do something with the records here
   // like write them to the new file.g

   fclose( data );
   return 0;
}

