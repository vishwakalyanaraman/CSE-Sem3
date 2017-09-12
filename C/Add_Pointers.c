#include <stdio.h>

int main (int argc, char **argv[]){
	int *ptr1, *ptr2;
	int sum;
	printf("Enter the values for the two numbers \n");
	scanf ("%d %d", ptr1,ptr2);
	sum = (*ptr1) + (*ptr2);
	printf("The sum is %d\n", sum);
}