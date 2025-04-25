// Algorithm
// 	1.	Start from the first element, assume it’s the minimum.
// 	2.	Compare it with all the other elements in the unsorted portion to find the smallest element.
// 	3.	Swap the smallest element with the first element of the unsorted portion.
// 	4.	Move the boundary of the sorted portion one step to the right.
// 	5.	Repeat the process until the entire array is sorted.

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}