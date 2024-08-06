#include <stdio.h>
#include <string.h>
//#include "csvparser.h"
struct info
  {
    // creat a pointer to store file name
    char f_name[20];
    char l_name[20];
    int  score ;
    char arabic_grade[4];
    char english_grade[4];
    char math_grade[4];
  };
int main() {
    struct info student;
    //FILE* data = fopen("data2.csv","r"); // open file
    char *c;          // to store character by character
    char str[1000];  // to store line by line 
    //fgets(str,sizeof(str),data);
    //printf("%s",str); 
    //str[1000]=fgets(str,"%19[^,]\t%19[^,]\t%d\t%4[^,]\t%19[^,]\t%s\n",student.f_name,student.l_name,&student.score,student.arabic_grade,student.english_grade,student.math_grade); //to read data from file
    rewind(data); // to move the file pointer to the beginning of the file stream
    printf("=============================================================================================\n"); 
    int i=1;
   while(  (fgets(str,1000,data)) != NULL)
    { 
        
        printf("%d-",i++);
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
         printf("%s\n",c); 
        

    }
    fclose(data); //To close The File
    return 0;
}