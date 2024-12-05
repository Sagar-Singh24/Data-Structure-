
#include <stdio.h>
#include <stdlib.h>

void insertionSortAsc(int arr[], int n) {
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

void insertionSortDesc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int N;
    printf("Enter the number of integers (N): ");
    scanf("%d", &N);

    if (N <= 0 || N > 1000000) {
        printf("Invalid input for N. N should be in the range (0, 1000000].\n");
        return 1;
    }

    int *arr = (int *)malloc(N * sizeof(int));
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSortAsc(arr, N / 2);

    insertionSortDesc(arr + N / 2, N - N / 2);

    printf("%d\n", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}