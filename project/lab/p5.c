#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int a[50000],c[50000];
void merge(int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k = low;
    while(i<=mid && j<=high){
        if(a[i]>a[j]){
            c[k]=a[i++];
        }
        else{
            c[k]=a[j++];
        }
        k++;
    }
    while(i<=mid){
        c[k]=a[i];
        k++;
        i++;
    }
        while(j<=high){
        c[k]=a[j];
        k++;
        j++;
    }
}
void sort(int a[],int low,int high){
    if(low < high){
        int mid = (low+high)/2;
        sort(a,low,mid);
        sort(a,mid+1,high);
        merge(low,mid,high);
    }
}
int main()
{
    int n, i;
    double clk;
    clock_t starttime, endtime;

    printf("MERGE SORT\n");
    printf("Enter the number of employee records:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("The Employee IDs are:\t%d\n", a[i]);
    }

    starttime = clock();
    sort(a, 0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nEmployee IDs in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }

    printf("\nThe run time is %f seconds\n", clk);
    return 0;
}