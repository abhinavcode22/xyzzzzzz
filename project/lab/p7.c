#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    
    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;


    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        
        heapify(a, n, largest);
    }
}


void heap_sort(int a[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
       
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

     
        heapify(a, i, 0);
    }
}

int main() {
    int n, a[100000];
    clock_t start, end;
    double clk;

    printf("HEAP SORT IMPLEMENTATION\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(0));  

    
    printf("\nOriginal array:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000; 
        printf("%d ", a[i]);
    }

   
    start = clock();

    
    heap_sort(a, n);

   
    end = clock();

   
    clk = (double)(end - start) / CLOCKS_PER_SEC;

   
    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

   
    printf("\n\nRun time: %f seconds\n", clk);

    return 0;
}
