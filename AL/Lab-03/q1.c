#include<stdio.h>
#include<stdlib.h>

int bubblesort(int *a, int n){
	int i,j,temp,opCount=0;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			opCount++;
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	return opCount;
}

int main(){
	int n,i,j,temp,opCount;
	printf("Enter n: ");
	scanf("%d",&n);
	int * a = (int *)malloc(n*sizeof(int));
	printf("Enter %d elements: ",i);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	opCount = bubblesort(a,n);

	printf("Sorted Array is: ");
	for(i=0; i<n; i++){
		printf("%d",a[i]);
		printf(",");
	}
	printf("\nOpCount is %d",opCount);
}