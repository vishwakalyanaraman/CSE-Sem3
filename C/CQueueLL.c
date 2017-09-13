#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    char info;
    struct node* link;
}NODE;
 
NODE* enqueue(NODE *list, char x)
{
    NODE *new, *tmp;
    new = (NODE*)malloc(sizeof(NODE));
   
    new->info = x;
    if(list==NULL)
    {
        new->link = new ;
        return (new);
    }
    tmp=list;
    while(tmp->link!=list)
        tmp=tmp->link;
    tmp->link=new;
    new->link = list;
    return (list);
}

void display(NODE *list)
{
    NODE *temp;
    printf("\n\nQueue: \n");
    if(list==NULL){
        printf("Stack is empty.\n");
        return;
    }
    temp = list;
    printf("%c\n", temp->info);
    temp=temp->link;
    while(temp!=list){
        printf("%c\n", temp->info);
        temp=temp->link;
    }
}
 
int getchoice()
{
    int ch;
    printf("1. Enqueue One \n2. Enqueue Two \n3. Display Both \n4 Merge display \n5. Exit\n");
    scanf("%d",&ch);
    return ch;
}
 
NODE* merge(NODE* l1, NODE* l2){
    NODE *tmp1, *tmp2;
    NODE *l;
    l = NULL;
    tmp1=l1;
    tmp2=l2;
    do
    {
        if(tmp1->info < tmp2->info)
        {
            printf("%c\n", tmp1->info);
            l=enqueue(l,tmp1->info);
            tmp1=tmp1->link;
        }
        else{
            printf("Pushed %c\n", tmp2->info);
            l=enqueue(l,tmp2->info);
            tmp2=tmp2->link;
        }
    }
    while(tmp1->link!=l1 && tmp2->link!=l2 && tmp1!=NULL && tmp2!=NULL);
    if(tmp1->link==l1){
        while(tmp2->link!=l2){
            printf("Pushed %c\n", tmp2->info);
            l=enqueue(l,tmp2->info);
            tmp2=tmp2->link;
        }
    }
    else
        while(tmp1->link!=l1){
            printf("Pushed %c\n", tmp1->info);
            l=enqueue(l,tmp1->info);
            tmp1=tmp1->link;
        }
}
 
int main()
{
    NODE* list1, *list2, *l; // Header node
    int ch;
    char x;
    list1 = NULL;
    list2 = NULL;
    while(1)
    {
        ch = getchoice();
        switch(ch)
        {
            case 1: printf("Enter element: \n");
                    scanf(" %c", &x);
                    list1=enqueue(list1, x);
                    break;
            case 2: printf("Enter element: \n");
                    scanf(" %c", &x);
                    list2=enqueue(list2, x);
                    break;
            case 3: display(list1);
                    printf("---------------------------------");
                    display(list2);
                    break;
            case 4: l=merge(list1, list2);
                    printf("Merged list");
                    display(l);
            case 5: exit(0);
        }
    }
    return 0;
}