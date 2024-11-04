#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void seedArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1; // Random number between 1 and 100
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 10;
    int arr[n];

    // Seed random number
    srand(time(NULL));

    // Initialize array with random values
    seedArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    // Bubble Sort
    bubbleSort(arr, n);
    printf("Sorted array (Bubble Sort):\n");
    printArray(arr, n);

    // Re-seed array for another sort
    seedArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    // Insertion Sort
    insertionSort(arr, n);
    printf("Sorted array (Insertion Sort):\n");
    printArray(arr, n);

    // Re-seed array for another sort
    seedArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    // Selection Sort
    selectionSort(arr, n);
    printf("Sorted array (Selection Sort):\n");
    printArray(arr, n);

    // Re-seed array for Merge Sort
    seedArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    // Merge Sort
    mergeSort(arr, 0, n - 1);
    printf("Sorted array (Merge Sort):\n");
    printArray(arr, n);

    // Re-seed array for Quick Sort
    seedArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    // Quick Sort
    quickSort(arr, 0, n - 1);
    printf("Sorted array (Quick Sort):\n");
    printArray(arr, n);

    return 0;
}
