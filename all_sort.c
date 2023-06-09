#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function declarations
void heap_sort(int arr[], int n);
//void merge_sort(int arr[], int left, int right);
//void bubble_sort(int arr[], int n);
//void selection_sort(int arr[], int n);

int main() {
    // Generate array of random numbers
    int num_array[MAX_SIZE];
    srand(time(0));
    for (int i = 0; i < MAX_SIZE; i++) {
        num_array[i] = rand() % 1000;
    }

    // Sort array using Heap sort and compute time complexity
    clock_t start_time = clock();
    heap_sort(num_array, MAX_SIZE);
    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Heap sort completed in %lf seconds.\n", time_taken);

    // Sort array using Merge sort and compute time complexity
    start_time = clock();
    merge_sort(num_array, 0, MAX_SIZE - 1);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Merge sort completed in %lf seconds.\n", time_taken);

    // Sort array using Bubble sort and compute time complexity
    start_time = clock();
    bubble_sort(num_array, MAX_SIZE);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Bubble sort completed in %lf seconds.\n", time_taken);

    // Sort array using Selection sort and compute time complexity
    start_time = clock();
    selection_sort(num_array, MAX_SIZE);
    end_time = clock();
    time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Selection sort completed in %lf seconds.\n", time_taken);

    return 0;
}

// Heap sort function
void heap_sort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
// Merge sort function
//void merge_sort(int arr[], int left, int right) {
  //  if (left < right) {
    //    int mid = left + (right - left) / 2;
      //  merge_sort(arr, left, mid);
        //merge_sort(arr, mid + 1, right);
       // merge_sort(arr, left, mid, right);
    //}
//}
