#include <stdio.h> 
#include <stdlib.h> 

int opCount = 0;

void heapify(int arr[], int index)
{
    int parent = (index - 1) / 2;
    while (parent >= 0)
    {
        opCount++;
        if (arr[parent] < arr[index])
        {
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            index = parent;
            parent = (index - 1) / 2;
        } else
            return;
    }
} 
                                  
int main() {
    int arr[20];     
    int n;     
    int i;     
    
    printf("Enter the size of elements: ");
    scanf("%d", &n);    
    printf("Enter the elements: ");     
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);         
        heapify(arr, i);         
    }                                        
    
    printf("\nHeapified Array: ");
    
    for (i = 0; i < n; i++)         
        printf("%d ", arr[i]);
    
    printf("\n\nOperation count: %d", opCount);     
    printf("\n");
    return 0;
}
