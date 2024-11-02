#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(int);

    printf("Original array:\n");
    printArray(arr, n);

    // Bubble Sort
    bubbleSort(arr, n);
    printf("Sorted array (Bubble Sort):\n");
    printArray(arr, n);

    int arr2[] = {64, 25, 12, 22, 11};
    
    // Insertion Sort
    insertionSort(arr2, n);
    printf("Sorted array (Insertion Sort):\n");
    printArray(arr2, n);

    int arr3[] = {64, 25, 12, 22, 11};

    // Selection Sort
    selectionSort(arr3, n);
    printf("Sorted array (Selection Sort):\n");
    printArray(arr3, n);

    return 0;
}
