#include<stdio.h>
#include <time.h>
int partition(int a[],int low,int high)
{
  int i,j,temp,pivot;
  pivot=a[low];
  i=low+1;
  j=high;

  while(i<=j)
  {
    while (a[i]<=pivot )
    {
        i++;
    }
    while (a[j]>pivot )
    {
        j--;
    }
    if (i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }    
  }
  temp=a[low];
  a[low]=a[j];
  a[j]=temp;

  return j;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

int main()
{
    clock_t start, end;
    double time_taken;

    int n,num;
    printf("ENTER NUMBER OF ARRAY ELEMENTS:");
    scanf("%d",&n);
    int a[n];
    
    for (int i=0;i<n;i++)
    {
        printf("enter elements for array::");
        scanf("%d",&num);
        a[i]=num;
    }  
    start = clock();

    quicksort(a,0,n-1);
    end = clock();

    printf("array elements are::");
    for (int i=0;i<n;i++)
    {
        printf("%d ,",a[i]);
    }  

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);
    printf("Time taken: %f milliseconds\n", time_taken * 100000);


}