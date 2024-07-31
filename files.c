// C program for the above approach
#include <conio.h>
#include <stdio.h>
#include <string.h>

  


// Driver Code
int main()
{
	  // Substitute the file_path string
	// with full path of CSV file
	FILE* fp = fopen("file_path.xlsx", "a+");

	char name[50];
	int accountno, amount;

	if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		
	}

	// Asking user input for the
	// new record to be added
	printf("\nEnter Account Holder Name\n");
	scanf("%s", &name);
	printf("\nEnter Account Number\n");
	scanf("%d", &accountno);
	printf("\nEnter Available Amount\n");
	scanf("%d", &amount);

	// Saving data in file
	fprintf(fp, "%s, %d, %d\n", name,accountno, amount);

	printf("\nNew Account added to record");

	char c;
    c =	fscanf(fp,"%s, %d, %d \n",&name,&accountno,&amount);

    while(c != EOF)
    {
        
        printf ("%c",c); 
        c = fgetc(fp); 
       
    }
    fclose(fp);
	return 0;
}
