#include<stdio.h>
#include<stdlib.h>
#define size 100000
#include<stdio.h>
void quicksort(int number[size],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main()
{
   int i,n,count, number[size];
   FILE *f;
     f=fopen("unsorted.txt","w");
   for (i=1; i<=size; i++)
   {
    n=rand()%1000+1;
    printf("%d\n",n);
    fprintf(f,"%d\n",n);
   }
   fclose(f);
   f=fopen("unsorted.txt","r");
   for(i=0;i<=size;i++)
   {
      fscanf(f,"%d",&number[i]);
   }
   quicksort(number,0,size-1);

   printf("Order of Sorted elements:\n");
   f=fopen("sorted.txt","w");
   for(i=0;i<size;i++)
   {
      printf("%d\n",number[i]);
      fprintf(f,"%d\n",number[i]);
   }
   fclose(f);
   return 0;
}
