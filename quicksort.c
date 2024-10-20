#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int left, int right) {
    for (int i = left; i <= right; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= right; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right, int m) {
    int stack[MAX_STACK_SIZE];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while (top >= 0) {
        right = stack[top--];
        left = stack[top--];

        if (right - left + 1 <= m) {
            selectionSort(arr, left, right);
            continue;
        }

        int pivotIndex = partition(arr, left, right);

        if (pivotIndex - 1 > left) {
            stack[++top] = left;
            stack[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < right) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = right;
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1, m);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
