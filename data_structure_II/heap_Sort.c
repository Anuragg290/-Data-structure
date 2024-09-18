#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{    
    int i,j,k,item,temp,a[10];
	
    srand(time(0));    
    
	
    for(i=1;i<=10;i++) 
    a[i]=rand()%100;   
    
    
    printf("The current array is: ");  
     printf("\n\n");              
    
	for(i=1;i<=10;i++)  
    printf("   %d", a[i]);  
    printf("\n\n");
    
       
   for(k=10;k>0;k--)
   {
               for (i=1;i<=k;i++)
               {
                   item = a[i];
                   j= i/2;
                   
                   while(j>0&& a[j]<item)
                   {
                               a[i]=a[j];
                               i=j;
                               j=j/2;
                   }
                   
                   a[i]= item;
               }
   temp=a[1];
   a[1]=a[k];
   a[k]=temp;
               
   }
    
    printf("The sorted array is: ");  
     printf("\n\n");
	               
    for(i=1;i<=10;i++) 
     printf("   %d", a[i]); 
     printf("\n\n");    
    
     
   }