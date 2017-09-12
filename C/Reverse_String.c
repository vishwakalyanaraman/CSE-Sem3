#include <stdio.h>

//Revesing Function
void reverseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--; //Works from the ends towards the middle
    }   
}     
 
//Function that prints Array onto one line
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
 
  printf("\n");
} 



int main() 
{
    int start = 0, end, i, arr[100];
    printf("Enter the size of the 1D Array\n");
    scanf("%d", &end);
    printf("Enter the elements of the array \n");
    for (i = 0; i < end; i++){
        scanf("%d", &arr[i]);
    }
    printf("The array entered is\n");
    printArray(arr, end);
    reverseArray(arr, start, end-1);
    printf("Reversed array is \n");
    printArray(arr, end);   
    return 0;
}