#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hsort(void *base, size_t nel, size_t width,
        int (*compare)(const void *a, const void *b));

void swap(void *a, void *b, size_t width) {
    unsigned char cache[width];
    memcpy(cache, a, width);
    memcpy(a, b, width);
    memcpy(b, cache, width);
}

void heapify(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b), size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < nel && compare((char *)base + left * width, (char *)base + largest * width) > 0) {
        largest = left;
    }
    if (right < nel && compare((char *)base + right * width, (char *)base + largest * width) > 0) {
        largest = right;
    }
    if (largest != i) {
        swap((char *)base + i * width, (char *)base + largest * width, width);
        heapify(base, nel, width, compare, largest);
    }
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)) {
    for (size_t i = nel / 2; i-- > 0;) {
        heapify(base, nel, width, compare, i);
    }
    for (size_t i = nel - 1; i > 0; i--) {
        swap((char *)base, (char *)base + i * width, width);
        heapify(base, i, width, compare, 0);
    }
}

int compare(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;

    int count_a = 0, count_b = 0;

    for (const char *p = str_a; *p; p++) {
        if (*p == 'a') {
            count_a++;
        }
    }

    for (const char *p = str_b; *p; p++) {
        if (*p == 'a') {
            count_b++;
        }
    }

    return count_a - count_b;
}

int main() {
    char *array[1000];
    char buffer[1000];
    size_t n;

    scanf("%zu", &n);
    getchar();

    for (size_t i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        array[i] = malloc(strlen(buffer) + 1);
        strcpy(array[i], buffer);
    }

    hsort(array, n, sizeof(char *), compare);

    for (size_t i = 0; i < n; i++) {
        printf("%s\n", array[i]);
        free(array[i]);
    }

    return 0;
}
