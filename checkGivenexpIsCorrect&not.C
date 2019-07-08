#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
char stack[100];
void push(char a)
{
      stack[top] = a;
      top++;
}
void pop()
{
      if (top == -1)
      {
	    printf("expression is invalid\n");
	    exit(0);
      }
      else
      {
	    top--;
      }
}
int main()
{
      int i,cho;
      char a[100];

			printf("\nEnter expression : ");
			scanf("%s",a);
			for (i = 0; a[i] != '\0';i++)
			{
			      if (a[i] == '(')
			      {
				    push(a[i]);
			      }
			      else if (a[i] == ')')
			      {
				    pop();
				      }
			}
			if (top == -1)
			      printf("Expression is valid\n\n");
			else
			      printf("Expression is invalid\n\n");

      return 0;
}