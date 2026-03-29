#include <stdio.h>
#include <math.h>

int main() {
    double a = -3, b=6, dx = 0.25;
    double x;

    printf("x\t\ty = f(x)\n");
    printf("-----------------------\n");

    for(x = a; x <= b; x += dx) {
        printf("%6.2f\t%10.4f\n", x, pow(x, 3));
    }
    return 0;
}