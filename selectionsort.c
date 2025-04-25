#include <stdbool.h>
#include <stdio.h>

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void showArr(int arr[], int size){
    for(int i = 0; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size){
    for(int i = 0 ; i<size-1 ; i++){
        int min = i;
        for(int j = i + 1 ; j<size ; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

int main(){
    int a[]= { 8,7,9,2,3,1,5,4,6 };
    int size = sizeof(a)/sizeof(a[0]);
    selectionSort(a,size);
    printf("Sorted array: \n");
    showArr(a,size);


}