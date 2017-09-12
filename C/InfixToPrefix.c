#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "prefix_eval.h"

int priority(char);
char pop1(STACK *);
char top(STACK *);


int priority(char c)
{
	if(c=='('||c==')')
		return 0;
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	return 3;
}

char pop1(STACK *s)
{
	char x;
	x = s->stack[s->top];
	s->top = s->top - 1;
	return x;
}


void main()
{
	STACK s;
	s.top=-1;
	char x[100],prefix[100],temp;
	int n,i,j=0;
	printf("Enter expression:\n");
	scanf("%s",x);
	for(i=0,n=strlen(x);i<n/2;i++)
	{
		temp = x[i];
		x[i] = x[n-i-1];
		x[n-i-1] = temp;
	}
	for(i=0;i<strlen(x);i++)
	{
		char symbol = x[i];
		if(isalnum(symbol))
		{
			prefix[j] = symbol;
			j++;
		}
		else
		{
			if(symbol == ')')
				push(&s,symbol);
			else
				if(symbol == '(')
				{
					while(s.stack[s.top] != ')')
					{
						prefix[j] = pop1(&s);
						j++;
					}
					pop1(&s);
				}
				else
				{
					if(priority(s.stack[s.top]) <= priority(symbol))
						push(&s,symbol);
					else
					{
						while(priority(s.stack[s.top]) >= priority(symbol))
						{
							prefix[j] = pop1(&s);
							j++;
						}
						push(&s,symbol);
					}
				}
		}
	}
	while(!isEmpty(&s))
	{
		prefix[j] = pop1(&s);
		j++;
	}
	prefix[j] = '\0';
	for(i=0;i<strlen(prefix)/2;i++)
	{
		temp = prefix[i];
		prefix[i] = prefix[strlen(prefix)-i-1];
		prefix[strlen(prefix)-i-1] = temp;
	}
	printf("%s\n",prefix);
}
