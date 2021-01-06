#include<stdio.h>
#define ARRAYSIZE 50



void shift_element(int* arr, int i){
	int tmp = *arr;
	int previous=0 , current=0;
	for(int j = 1; j <= i; j++){		
		previous = tmp;
		current = *(arr+j);		
		tmp = current;		
		*(arr+j) = previous;

		
	}
}


void insertion_sort(int* arr, int len){
	
	for(int i = 1; i < len; i++){
		int goFowerd = 0;
		int key = *(arr+i);
		int j = i-1;	
		
		while(j>=0 && *(arr+j)>=key){
			j--;
			goFowerd++;
		}

		shift_element(arr+j+1 , goFowerd);
		*(arr+j+1) = key;
	}
}


int main(){
	int array[ARRAYSIZE] = {0};
	
	for(int i = 0; i < ARRAYSIZE; i++){
		fscanf(stdin, "%d", &array[i]);
	}

	insertion_sort(array, ARRAYSIZE);

	for(int i = 0; i < ARRAYSIZE-1; i++){
		printf("%d,", *(array+i));
	}

	printf("%d",*(array+49));
	
	return 0;
}
