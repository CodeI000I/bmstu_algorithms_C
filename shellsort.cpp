#include <iostream>
using namespace std;

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j)) {

    unsigned long fib1 = 1, fib2 = 2;
    unsigned long fib_seq[40] = {0}; 
    fib_seq[0] = fib1;
    int fib_len = 1;


    while (fib2 < nel) {
        fib_seq[fib_len++] = fib2;
        unsigned long temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp;
    }
    

    for (int k = fib_len - 1; k >= 0; k--) {
        unsigned long gap = fib_seq[k];
        
        for (unsigned long i = gap; i < nel; i++) {
            for (unsigned long j = i; j >= gap && compare(j - gap, j) > 0; j -= gap) {
                swap(j - gap, j);
            }
        }
    }
}

