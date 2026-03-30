#include <stdio.h>
#include <math.h>

int main() {
    int x, z;
    double y;

    while (1) {
        printf("Введіть x і z: ");
        scanf("%d %d", &x, &z);

        if (x < 0) {
            printf("Помилка: корінь з від'ємного x. Введіть інші значення.\n\n");
            continue;
        }

        if (x * z < 0) {
            printf("Помилка: корінь з від'ємного x * z. Введіть інші значення.\n\n");
            continue;
        }

        if (sqrt(x) - 2 * sqrt(x * z) == 0) {
            printf("Помилка: ділення на 0. Введіть інші значення.\n\n");
            continue;
        }

        break;
    }

    y = (sqrt(x) + 2 * sqrt(x * z)) / (sqrt(x) - 2 * sqrt(x * z));
    printf("y = %lf\n", y);

    return 0;
}
