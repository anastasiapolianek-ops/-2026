#include <stdio.h>

int main() {
    long long product = 1;

    for(int i = 20; i <= 80; i++) {
    if (i % 5 == 0){
        product *= i;
    }
    }
    printf("Добуток :%lld\n", product);
        return 0;
}