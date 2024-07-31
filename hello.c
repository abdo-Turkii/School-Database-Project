/*#include<stdio.h>
void x(int *g)
{
    *g=;
    printf("%d\t",*g);
}
int main()
{
 int j=3;
x(&j);
}*/
#include <stdio.h>

int main (int argc, char * argv[]){
   printf("Hello %s\n", argv[0]);
   for (int i=0;i<34;i+=4)
   printf("%d\t",i);
   return 0;
}