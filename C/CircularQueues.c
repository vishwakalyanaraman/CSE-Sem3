#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define UNDER '\0'

typedef struct
{
	char arr[SIZE];
	int f;
	int r;
} CQ;


int isFullQueue (CQ q)
{
	if ((q.r + 1)%SIZE == q.f)
		return 1;
	return 0;
}

int isEmptyQueue (CQ q)
{
	if (q.f == -1 && q.r == -1)
		return 1;
	return 0;
}

void insert (CQ q, char item[20])
{
	if (isFullQueue(q))
    {
		printf("Overflow\n");
		return;
	}
	
	if (isEmptyQueue(q))
		q.f = q.r = 0;
	else
		q.r+=1;
		//q.r = (q.r + 1)%SIZE;
	
	q.arr[q.r] = item;
}

char delete (CQ q)
{
	if (isEmptyQueue(q))
    {
		printf("Underflow\n");
		return UNDER;
	}
	
	char item = (q.arr[q.f]);
	
	if (q.f == q.r)
		q.f = q.r = -1;
	else
		q.f = (q.f + 1)%SIZE;
	
	return item;
}

void display (CQ q)
{
	if (isEmptyQueue(q))
		printf("Empty Queue\n");
	else
        {
	  printf("Now circular queue is\n");
		int i;
		for (i = q.f; i != q.r; i = (i+1)%SIZE)
			printf("%s\n", (q.arr));
		printf("%s\n", (q.arr));
	}
}


int main()
{
	
	CQ queue;
	int choice;
	char item[20];
	// char item[SIZE];
	queue.f = -1;
	queue.r = -1;
	do
    {
		printf("1 to insert, 2 to delete, 3 to display\n");
		scanf(" %d", &choice);
		
		
		if (choice == 1)
        {
			printf("Enter element ");
			scanf("%s", item);
			insert(queue, item);
		}
		else if (choice == 2)
        {
			/*item = delete(queue);
			if (item != UNDER)*/
				printf("Deleted element is %d\n", delete(queue));
		}
		{
			printf(" %s\n",queue.arr);
			exit(0);
		}
		
	} while (choice == 1 || choice == 2 || choice == 3);
	
	return 0;
}