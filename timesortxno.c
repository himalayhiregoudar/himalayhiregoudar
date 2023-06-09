#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    // Open input file for reading
    FILE *fp_input;
    fp_input = fopen("Input.txt", "r");

    // Read numbers from file into an array
    int num_array[MAX_SIZE];
    int num_count = 0;
    while (fscanf(fp_input, "%d", &num_array[num_count]) != EOF) {
        num_count++;
    }

    // Close input file
    fclose(fp_input);

    // Open log file for writing
    FILE *fp_log;
    fp_log = fopen("log.txt", "w");

    // Experiment with different sorting techniques and values of X
    int x_values[] = {10, 50, 100};
    char *sort_techniques[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort"};
    int num_sort_techniques = 4;

    for (int i = 0; i < num_sort_techniques; i++) {
        for (int j = 0; j < sizeof(x_values) / sizeof(int); j++) {
            int x = x_values[j];
            int temp_array[x];

            // Copy first x elements from num_array to temp_array
            memcpy(temp_array, num_array, x * sizeof(int));

            // Compute time required to sort temp_array using the current sorting technique
            clock_t start_time = clock();
            if (strcmp(sort_techniques[i], "Bubble Sort") == 0) {
                bubble_sort(temp_array, x);
            } else if (strcmp(sort_techniques[i], "Selection Sort") == 0) {
                selection_sort(temp_array, x);
            } else if (strcmp(sort_techniques[i], "Insertion Sort") == 0) {
                insertion_sort(temp_array, x);
            } else if (strcmp(sort_techniques[i], "Quick Sort") == 0) {
                quick_sort(temp_array, 0, x - 1);
            }
            clock_t end_time = clock();
            double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

            // Write sorting technique, value of X, and time required to log file
            fprintf(fp_log, "%s, %d, %lf seconds\n", sort_techniques[i], x, time_taken);
        }
    }

    // Close log file
    fclose(fp_log);

    printf("Sorting complete. Results written to log.txt.\n");
    return 0;
}

// Bubble sort function
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection sort function
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j <n-i-1;j++);
    }
}
