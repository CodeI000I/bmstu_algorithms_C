#include <stdio.h>
#include <stdlib.h>  // Для malloc и free

int main() {
    int n; // степень полинома
    long long x0; 
    scanf("%d %lld", &n, &x0);

    // выделение памяти для коэффициентов
    long long* a = (long long*)malloc((n + 1) * sizeof(long long));

    for (int i = 0; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    // вычисление значения полинома
    long long P = a[0]; 
    for (int i = 1; i <= n; i++) {
        P = P * x0 + a[i];
    }

    // вычисление производной
    long long proizvodnya = a[0] * n; // начальное значение для производной
    for (int i = 1; i < n; i++) {
        proizvodnya = proizvodnya * x0 + a[i] * (n - i);
    }

    // вывод полинома и его производной
   printf("%lld %lld\n", P, proizvodnya);

   
    free(a);

    return 0;
}
