#include <stdio.h>

int add (int a[100][100], int b[100][100], int n){

	int i, j, c[100][100];
	for (i=0; i < n; i++){
		for (j = 0; j < n; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("The sum of the two matrices is\n\n");
	for (i=0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d\t", c[i][j]);
		}
		printf("\n\n");
	}
	return 0;
}

void main(){

	int a[100][100], b[100][100], i, j,n;
	printf("Enter the dimensions of Matrix A and B \n");
	scanf("%d", &n);


	printf("Enter the values of Matrix A\n");
	for (i=0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the values of Matrix B\n");
	for (i=0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &b[i][j]);
		}
	}

	add(a,b,n);

}	