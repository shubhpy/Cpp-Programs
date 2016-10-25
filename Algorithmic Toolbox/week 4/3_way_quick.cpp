#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void partition(int a[], int low, int high, int *lowerLimit, int *higherLimit){
	int pivot = a[low];
	int lt = low + 1;
	int gt = high;
	int reader = low ;

	while(reader < gt){
		if(a[reader] < pivot){
			swap(&a[reader], &a[lt]);
			reader++;
			lt++;
		}
		else if(a[reader] == pivot){
			reader++;
		}
		else {
			swap(&a[reader], &a[gt]);
			gt--;
		}

	}

	swap(&a[low], &a[--lt]);
	*lowerLimit = lt;
	*higherLimit = gt;
	return ;
}

void quickSort(int a[], int low, int high){
	int lowLimit = 0;
	int highLimit = 0;
	if(low < high){
		partition(a, low, high, &lowLimit, &highLimit);
		quickSort(a, low, lowLimit);
		quickSort(a, highLimit, high);
	}
}
int main(void) {
	int a[] = {2,4,3,3,4,4,1,1,6};
	int size = sizeof(a)/sizeof(a[0]);

	quickSort(a, 0, size-1);

	for(int i=0; i<size; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
