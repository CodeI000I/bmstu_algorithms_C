#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

int main() {
    
    char str[1000001]; 
    scanf("%s", str);

    
    int count[ALPHABET_SIZE] = {0};

    
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%c", i + 'a');
        }
    }

    printf("\n");

    return 0;
}
