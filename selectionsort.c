#include<stdio.h>



void sort(int arr[],int n){
	int i,j,min;
	for(i=0 ; i<n-1 ; i++){
		min = i;
		for(j=i+1 ; j<n ; j++){
			if(arr[j] < arr[min]){
				min=j;
				if(min!=i){
					int temp = arr[min];
					arr[min] = arr[i];
					arr[i] = temp;
					
				}
			}
		}
	}
}


void print(int arr[] , int size){
	int i;
	for(i=0 ; i<size ; i++){
		printf("%d ",arr[i]);
		
	}
	printf("\n");
}


int main(){
	int arr[]= {64,24,12,33,22,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	printf("Sorted array: \n");
	print(arr,n);
	return 0;
	
}