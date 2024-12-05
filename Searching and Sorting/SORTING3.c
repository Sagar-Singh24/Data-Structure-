#include <stdio.h>
#include <string.h>

void selectionSort(char arr[][100], int n, int *pass_count) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strlen(arr[j]) < strlen(arr[min_idx])) {
                min_idx = j;
            }
            (*pass_count)++;
        }
        char temp[100];
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
}

int main() {
    int N;
    printf("Enter the number of strings (1<= N <= 5): ");
    scanf("%d", &N);

    if (N < 1 || N > 5) {
        printf("Please enter a value between 1 and 5 for N.\n");
        return 1;
    }

    char strings[N][100];
    int lengths[N];

    printf("Enter %d strings:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%s", strings[i]);
        lengths[i] = strlen(strings[i]);
    }

    int pass_count = 0;
    selectionSort(strings, N, &pass_count);

    printf("Sorted strings in ascending order by length:\n");
    for (int i = 0; i < N; i++) {
        printf("{%s}-%d\n", strings[i], lengths[i]);
    }

    printf("Total passes required: %d\n", pass_count);

    return 0;
}