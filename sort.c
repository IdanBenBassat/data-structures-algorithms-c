#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

static void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

static int partition(int arr[], int low, int high) 
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

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

static void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // check allocation success
    if (L == NULL || R == NULL) 
    {
        fprintf(stderr, "Memory allocation failed in merge()\n");
        free(L);
        free(R);
        return;
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k++] = L[i++];
        }
        else 
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void compareSortTimes(int arr[], int size)
{
    int* copy = (int*)malloc(size * sizeof(int));
    if (copy == NULL) 
    {
        fprintf(stderr, "Memory allocation failed in compareSortTimes()\n");
        return;
    }

    printf("\nSort Timing Comparison:\n");

    clock_t start, end;
    double cpu_time_used;

    // Bubble Sort
    memcpy(copy, arr, size * sizeof(int));
    start = clock();
    bubbleSort(copy, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.6f seconds\n", cpu_time_used);

    // Selection Sort
    memcpy(copy, arr, size * sizeof(int));
    start = clock();
    selectionSort(copy, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.6f seconds\n", cpu_time_used);

    // Quick Sort
    memcpy(copy, arr, size * sizeof(int));
    start = clock();
    quickSort(copy, 0, size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %.6f seconds\n", cpu_time_used);

    // Merge Sort
    memcpy(copy, arr, size * sizeof(int));
    start = clock();
    mergeSort(copy, 0, size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %.6f seconds\n", cpu_time_used);

    free(copy);
}

static void sortMenu() 
{
    int arr[100] = { 0 };
    int size;

    printf("\nEnter the number of elements to sort: ");
    scanf_s("%d", &size);
    if (size <= 0 || size > 100) 
    {
        printf("Invalid size. Must be between 1 and 100.\n");
        return;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf_s("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, size);

    compareSortTimes(arr, size);
}