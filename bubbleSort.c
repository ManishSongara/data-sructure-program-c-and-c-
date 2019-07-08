#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[20],n,i,j,t;
	printf("enter size of array: ");
	scanf("%d",&n);
	
	printf("enter elements");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
		for(i=1;i<=n-1;i++)
		{
		 		for(j=1;j<=n-1;j++)
				{
					if(arr[j+1]<arr[j])
					{
						t=arr[j+1];
						arr[j+1]=arr[j];
						arr[j]=t;
					}
			   }
	   }
	   printf("sorted list= ");
	   	for(i=1;i<=n;i++)
     	{
			printf("%d\n",arr[i]);
		}
	
}
