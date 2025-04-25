// Algorithm
// 	1.	Start from the second element (index 1) and assume the first element is already sorted.
// 	2.	Pick the current element and compare it with the elements in the sorted portion (to its left).
// 	3.	Shift elements that are greater than the current element to the right.
// 	4.	Insert the current element in its correct position.
// 	5.	Repeat the process for all elements in the array.

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}