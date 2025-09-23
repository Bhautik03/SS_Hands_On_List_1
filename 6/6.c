/*
============================================================================
Name : 6.c
Author : Bhautik Vekariya
Description : Write a program to take input from STDIN and display on STDOUT. 
	      Use only read/write system calls
Date: 7 Sept, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdlib.h>

int main(){
	char buf[50];
	int n;

	n = read(0, buf, sizeof(buf));  
	if(n<0){
		write(2, "Read Error!!!\n", 14);  
		exit(1);
	}

	write(1, buf, n);

	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/6$ gcc 6.c
bhautik@bhautik:~/SS/MT2025029/6$ ./a.out
Hello!!
Hello!!
============================================================================
*/
