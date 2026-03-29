#include <stdio.h>

int main() {
    int i = 20;
    long long product = 1;
    do {
        if (i % 5 == 0) {
            product *= i;
        }
        i++;
    } while (i <= 80);
    printf("Добуток :%lld\n", product);
    return 0;
}