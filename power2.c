#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool checksum(int sum) {
    return (sum > 0) && ((sum & (sum - 1)) == 0);
}

void combinations(int n, int k, int* list, int* counter, int start, int current_sum) {
    if (k == 0) {
        if (checksum(current_sum)) (*counter)++;
        return;
    }
    for (int i = start; i <= n - k; i++) {

        if (current_sum + list[i] > 2147483647) break; 

        combinations(n, k - 1, list, counter, i + 1, current_sum + list[i]);
    }
}

void find_combinations(int n, int* list, int* counter) {
    for (int i = 2; i <= n; i++) {
        combinations(n, i, list, counter, 0, 0);
    }
}

int main() {
    short n;
    int counter = 0;
    scanf("%hd", &n);
    int* numbers = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    find_combinations(n, numbers, &counter);
    
    printf("%d\n", counter);
    
    free(numbers);
    return 0;
}
