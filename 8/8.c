/*
============================================================================
Name : 8.c
Author : Bhautik Vekariya
Description : Write a program to open a file in read only mode, read line by 
              line and display each line as it is read. Close the file when 
	      end of file is reached. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *ptr;
	char buf[100];

	if(argc!=2){
		printf("Usage: %s <filename>", argv[0]);
	}

	ptr = fopen(argv[1], "r");
	if(ptr == NULL){
		perror("Error opening file");
		exit(1);
	}

	while(fgets(buf, sizeof(buf), ptr) != NULL){
		printf("%s", buf);
	}

	fclose(ptr);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/8$ gcc 8.c
bhautik@bhautik:~/SS/MT2025029/8$ ./a.out file.txt
Hello!
How are you!
============================================================================
*/
