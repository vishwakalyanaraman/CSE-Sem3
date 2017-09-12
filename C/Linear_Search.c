#include <stdio.h>

void main(){

	int a[100], i, n, search;
	printf("Enter the size of the array \n");
	scanf("%d", &n);
	printf("Enter the elements of the array\n");
	for (i = 0; i < n; i++){
			scanf("%d", &a[i]);
	}
	printf("Enter the number you want to search for\n");
	scanf ("%d", &search);
	for (i = 0; i < n; i++){
		if (a[i] == search){
			printf("The number is found in position %d\n", i+1);
		}
		else printf("The number is not found \n");
		break;
	}
}
