#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
        printf("Etapa %d: ", i);
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

    insertion_sort(arr, n);

    printf("Vetor ordenado (Insertion Sort):\n");
    print_array(arr, n);

    return 0;
}
