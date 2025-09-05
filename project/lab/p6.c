#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int a[], int low, int high)
{
    int i = low+1;
    int j = high;
    int pivot = a[low];
    int temp;
    while(1){
        while(i<=high&& a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }
        else{
            temp=a[j];
            a[j]=a[low];
            a[low]=temp;
            return j;
        }
        
    }
    return j;
}
void sort(int a[],int low,int high){
    int j;
    if(low<high){
    j=partition(a,low,high);
    sort(a,low,j-1);
    sort(a,j+1,high);
    }
}
int main()
{
    int i, n, a[200000];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of student records: ");
    scanf("%d", &n);

  
    printf("\nThe roll numbers are:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        printf("%d\t", a[i]);
    }

  
    starttime = clock();

    
    sort(a, 0, n - 1);

   
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    
    printf("\n\nSorted roll numbers are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n\nThe run time is %f seconds\n", clk);

    return 0;
}