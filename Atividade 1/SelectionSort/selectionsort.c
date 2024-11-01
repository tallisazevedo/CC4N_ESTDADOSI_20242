#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        
        printf("Etapa %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[50];
    int n = 50;

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }

    printf("Vetor original:\n");
    print_array(arr, n);

    selection_sort(arr, n);

    printf("Vetor ordenado (Selection Sort):\n");
    print_array(arr, n);

    return 0;
}
