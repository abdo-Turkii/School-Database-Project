// C Code to explain why adding 
// "while ( (getchar()) != '\n');"
// after "scanf()" statement 
// flushes the input buffer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
  int d;
  int x[]={5,6,3,6,2,9,0};
	char str[10], ch;
#include "C:\Program Files\Notepad++\print.txt"

	printf("Enter age:");
  scanf("%d",&d);
  printf("your age:%d\n",d);
  printf("Enter name:");
  //fflush(stdin);
  while ((getchar()) != '\n'){}

  //fgets(str,10,stdin);
  scanf("%s",str);
  printf("your name:%s",str);

	return 0;
}
