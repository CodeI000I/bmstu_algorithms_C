#include <stdio.h>

int main() {
    unsigned long long a, b, m=1;
    unsigned long long result = 0;  // Результат начнем с нуля

    // Ввод чисел a, b, m
    
    scanf("%llu %llu %llu", &a, &b, &m);

    
    a = a % m;

    // Пока есть двоичные разряды у b
    while (b > 0) {
        // Если младший бит b равен 1, добавляем a к результату
        if (b % 2 == 1) {
            result = (result + a) % m;  // Не забываем применять модуль m
        }

        // Удваиваем a и берем по модулю m, чтобы не было переполнения
        a = (a * 2) % m;

        // Переходим к следующему разряду b
        b = b / 2;
    }

    // Вывод результата умножения по модулю
    printf("%llu", result);
    return 0;
}
