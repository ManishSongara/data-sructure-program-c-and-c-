
#include<stdio.h>
#include<conio.h>

void mergesort(int a[],int n)
{
int b[50],c,low1,high1,high2,low2;
int i,k,j;
c=1;
while(c<n)
{
low1=0;
k=0;
while(low1+c<n)
{
low2=low1+c ;
high1=low2-1;
if(low2+c-1<n)
high2=low2+c-1;
else
high2=n-1;
i=low1;
j=low2;
while(i<=high1 && j<=high2)
{
if(a[i]<=a[j])
b[k++]=a[i++];
else
b[k++]=a[j++];

}
while(i<=high1)
b[k++]=a[i++];
while(j<=high2)
b[k++]=a[j++];
low1=high2+1;
}
i=low1;
while(k<n)
b[k++]=a[i++];
for(i=0; i<n; i++)
a[i]=b[i];
c=c*2;
}
}

main()
{
int a[20],i,n;


printf("How many elements you want to enter: ");
scanf("%d",&n);
printf("Enter any %d elements: \n",n);
for(i=0; i<n; i++)
{
scanf("%d",&a[i]);
}

printf("\n\nList Befor Sorting : ");
for(i=0; i<n; i++)
{

printf("%5d",a[i]);
}
mergesort(a,n);

printf("\n\nList After Sorting : ");
for(i=0; i<n; i++)
{

printf("%5d",a[i]);
}
getch();
return 0;
}
