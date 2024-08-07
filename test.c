#include <stdio.h>
#include <string.h>
//#include "csvparser.h"
struct top_stu
{
  char name1[20];
  char name2[20];
  int t_score;
  char arabic_g[4];
  char english_g[4];
  char math_g[5];
};
void top(FILE* data , char* file_name)
{
  struct top_stu stu[1024],str;
  //char stu[1024];
  //char *str;  // structure to store data in array
  int read = 0 ;     // number of data get from file in one line 
  int records = 0 ; // number of line get
  int i,j;         // counters 
  data = fopen( file_name , "r"); // open file to read
  //loop to read and store data in student structure
  do
    {
        //get data line by line
        //read = fscanf(data,"%19[^,],%19[^,],%d,%4[^,],%4[^,],%5[^,]",stu.name1,stu.name2,&stu.t_score,stu.arabic_g,stu.english_g,stu.math_g);

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
              //str=strtok(stu[i],"\n'");  

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
    struct top_stu stu[1024];
    struct info student;
    char* file_name ;
    file_name ="data2.csv";
    FILE* data = fopen("data2.csv","r"); // open file
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
    top(data ,file_name);
    return 0;
}