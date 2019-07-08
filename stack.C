#include<stdio.h>
#define max 10

int top=-1;
int top1=-1;
int stack[max];
int stack1[max];
void push();
void pop();
void display();
void search();
void main()
{
int flag=1;
int ch;
clrscr();
while(flag)
{
	printf("\n*** Stack Menu ***");
	printf("\n\n1.Push\n2.Pop\n3.Display\n4.search\n5.exit");
	printf("\n\nEnter your choice(1-):");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: push();
		break;
		case 2: pop();
		break;
		case 3: display();
		break;
		case 4: search();
		break;
		case 5: flag=0;
		default: printf("\nWrong Choice!!");
	}
}
}
void push()
{
	int st;
	if(top>=max)
	{
		printf("stack is full");
	}
	else
	{
		printf("enter element data u want to enter in satck");
		scanf("%d",&st);
		top=top+1;
		stack[top]=st;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("empty stack");
	}
	else
	{
		printf("data in stack is\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
void search()
{
int k;
int sr;
int j;
if(top==-1)
{
	printf("stack is empty");
}
else
{
	printf("enter element that u want tu search=  ");
	scanf("%d",&sr);
	for(k=top;k>=0;k--)
	{
		if(stack[k]==sr)
		{

			printf("elemt found=  %d\n",stack[k]);
			pop();
			for(k=top1;k>=0;k--)
			{
			top=top+1;
			stack[top]=stack1[top1];
			top1=top1-1;
			display();
			}
			k=-1;
		}
	       else
		{
			top1=top1+1;
			stack1[top1]=stack[k];
			top=top-1;
		}
	}
	}
}
void pop()
{
int i;
if(top==-1)
{
	printf("stack is empty");
}
else
{
	top=top-1;
}
}
