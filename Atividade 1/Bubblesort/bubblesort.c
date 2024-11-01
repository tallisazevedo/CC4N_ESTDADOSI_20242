#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
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

    bubble_sort(arr, n);

    printf("Vetor ordenado (Bubble Sort):\n");
    print_array(arr, n);

    return 0;
}
