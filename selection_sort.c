#include<stdio.h>
#include<conio.h>
int main(){
     int i, j, n, temp, arr[100];
     printf("How many numbers u are going to enter?: ");
     scanf("%d",&n);

   printf("Enter %d elements: ", n);
   
   for(i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
 
   
   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<n;i++)
   	{
      printf(" %d",arr[i]);
  }
  


}
