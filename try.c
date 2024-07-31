#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

int main(){
    char c;
    FILE* menu = fopen("Main Menu2","a+");
    fprintf(menu,"Press 'a' on keyboard for adding new name.\nPress 'p' to print all information in database file.\nPress 's' to search for a name. \nPress 'e' to edit the enteries of the student.\nPress 't' to print top 10 students.\nPress 'd' to delete a student.\n");
    rewind(menu);
    while(c != EOF)
    { 
        printf ("%c",c); 
        c = fgetc(menu);
    }
   
}