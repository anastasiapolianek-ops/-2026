#include <stdio.h>
#include <math.h>

int main() {
    int y, z;
    double x;

    printf("Введіть y i z:" );
    if (scanf("%d %d", &y, &z) != 2) {
        printf("Помилка вводу\n");
        return 1;
    }

    if (y == -8) {
        if ((z - 2 *y ) == 0 || 3 * y / (z - 2 * y) < 0 ) {
            printf("Неможливо обчислити\n");
        } else {
            x = sqrt (3 * y / (z - 2 * y));
            printf("x = %.2lf\n", x);
        }
    } else if (y == 10) {
        x = y / 2.0 + 15 * z;
        printf("x = %.2lf\n", x);
    }
    else if (y == 2) {
        x = y * z - 7 * z;
        printf("x = %.2lf\n", x);
    }
        else {
        printf("Неможливо обчислити\n");
    }
    return 0;
}