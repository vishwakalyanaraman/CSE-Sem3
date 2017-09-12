#include <stdio.h>


int Big(int a[], int n){

	int i, max = a[0];
	for (i = 1; i < n; i++){
		if(a[i]>max){
			max = a[i];
		}
	}
	return max;
}

void main (){

	int a[100],i,n,result;
	printf("Enter the size of the 1D Array\n");
	scanf("%d", &n);
	printf("Enter the elements of the array\n");
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	result = Big(a,n);
	printf("The biggest number in the array is %d\n", result);
}

