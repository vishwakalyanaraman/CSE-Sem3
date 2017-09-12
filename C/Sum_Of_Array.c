#include <stdio.h>

int sum(int a[], int n){

	int i, sum = 0;
	for (i = 0; i < n; i++){
		sum = sum + a[i];
	}
	//printf("The sum of the array is %d\n", sum);
	return sum;
}

void main (){

	int i,n,out,a[100];
	printf ("Enter the size of the 1D array: \n");
	scanf ("%d", &n);
	printf ("Enter the elements of the 1D array \n");
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	out = sum(a, n);
	printf("The sum of the array is %d\n", out);
} 