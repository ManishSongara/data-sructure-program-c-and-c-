#include <stdio.h>
#define MAX 20
void insert_que1(int *,int *,int *,int);
void insert_que2(int *,int *,int *,int);
void delete_que1(int *,int *,int *,int *);
void delete_que2(int *,int *,int *,int *);
void display_que1(int *,int *,int *);
void display_que2(int *,int *,int *);
int c1=0;
int c2=0;
void main()
{
int que[MAX];
int front1,rear1,front2,rear2;
int value,choice,i;
front1 = rear1 = -1;
front2 = rear2 = 20;
for(i=0;i<MAX;i++)
que[i]=-1;
START:
do
{
printf("\n\tMULTIPLE QUEUE:\n");
display_que1(que,&front1,&rear1);
display_que2(que,&front2,&rear2);
printf("\n______________________________________");
printf("\n 1. insert to queue1\n");
printf("\n 2. insert to queue2\n");
printf("\n 3. delete to queue1\n");
printf("\n 4. delete to queue2\n");
printf("\n 5. Print elements in Queue1\n");
printf("\n 6. Print elements in Queue2\n");
printf("\n 7. Quit\n");
printf("\n______________________________________");
printf("\n\tENTER CHOICE HERE :");
scanf("%d",&choice);
switch(choice)
{
case 1 : printf("Enter the element to be inserted in front\n");
scanf("%d",&value);
insert_que1(que,&front1,&rear1,value);
break;
case 2 : printf("Enter the element to be inserted in end\n");
scanf("%d",&value);
insert_que2(que,&front2,&rear2,value);
break;
case 3 : delete_que1(que,&front1,&rear1,&value);
if(value == -1)
printf("Deque_2 is empty\n");
else
printf("The value deleted from front is %d\n",value);
break;
case 4 : delete_que2(que,&front2,&rear2,&value);
if(value == -1)
printf("Deque_2 is empty\n");
else
printf("The value deleted from front is %d\n",value);
break;
case 5 : display_que1(que,&front1,&rear1);
break;
case 6 : display_que2(que,&front2,&rear2);
break;
case 7 : printf("\npress any key to QUIT !!!\n");
goto EXIT;
default: goto START;
}
}while(1);
EXIT:
getch();
}
void insert_que1(int que[],int *front1,int *rear1,int value)
{
int i,k;
if(*front1 == 0 && *rear1 == MAX-11)
{
printf("Deque_1 is full.\n");
return;
}
if(*rear1 == -1)
{
*rear1=*front1=0;
que[*rear1]=value;
c1++;
return;
}
if(*rear1 == MAX-11)
{
printf("shifting");
k=*front1-1;
for(i=1;i<=c1;i++)
{
que[k]=que[k+1];
k++;
}
que[k]=value;
*rear1=k;
(*front1)++;
c1++;
}
else
{
(*rear1)++;
que[*rear1]=value;
c1++;
}
}
void delete_que1(int que[],int *front1,int *rear1,int *value)
{
if(*front1 == -1)
{
printf("Deque_1 is empty\n");
*value=-1;
return;
}
*value = que[*front1];
que[*front1]=-1;
if(*front1 == *rear1)
{
*front1=-1;
*rear1=-1;
*value=-1;
c1--;
}
else
{
(*front1)++;
c1--;
}
}
void display_que1(int *que,int *front1,int*rear1)
{
int i;
printf("\n QUEUE NO 1 :\t");
if(*front1 == -1 || *rear1 == -1)
printf("Deque_1 is empty\n");
else
{ printf("front->");
for(i=*front1;i<=*rear1;i++)
printf(" %d",que[i]);
printf(" <-rear");
}
}
void insert_que2(int que[],int *front2,int *rear2,int value)
{
int i,k;
if(*front2 == MAX-1 && *rear2 == MAX-10)
{
printf("Deque_2 is full.\n");
return;
}
if(*rear2 == 20)
{
*rear2=*front2=19;
que[*rear2]=value;
c2++;
return;
}
if(*rear2 == MAX-10)
{
printf("shifting");
k=*front2-1;
for(i=1;i<=c2;i++)
{
que[k]=que[k-1];
k--;
}
que[k]=value;
*rear2=k;
(*front2)--;
c2++;
}
else
{
(*rear2)--;
que[*rear2]=value;
c2++;
}
}
void delete_que2(int que[],int *front2,int *rear2,int *value)
{
if(*front2 == 20)
{
printf("Deque_1 is empty\n");
*value=-1;
return;
}
*value = que[*front2];
que[*front2]=-1;
if(*front2 == *rear2)
{
*front2=20;
*rear2=20;
*value=-1;
c2--;
}
else
{
(*front2)--;
c2--;
}
}
void display_que2(int *que,int *front2,int*rear2)
{
int i;
printf("\n QUEUE NO 2 :\t");
if(*front2 == 20 || *rear2 == 20)
printf("Deque_2 is empty\n");
else
{ printf("front->");
for(i=*front2;i>=*rear2;i--)
printf(" %d",que[i]);
printf(" <-rear");
}
}