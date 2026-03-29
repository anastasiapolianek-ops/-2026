#include <stdio.h>

int main() {
    int i = 20;
    long long product = 1;

    while (i <= 80) {
        if (i % 5 == 0) {
            product *= i;
        }
        i++;
    }
    printf("Добуток :%lld\n", product);
    return 0;
}