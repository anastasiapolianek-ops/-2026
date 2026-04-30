#include <stdio.h>
#include <math.h>

// довжина кола
double circle_length(double a) {
    return 3.14159 * a * sqrt(2);
}

// площа круга
double circle_area(double a) {
    return (3.14159 * a * a) / 2;
}

int main() {
    double a;
    int choice;

    printf("Введіть сторону квадрата: ");
    scanf("%lf", &a);

    do {
        printf("\n----Меню----\n");
        printf("1. Довжина описаного кола\n");
        printf("2. Площа описаного круга\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                double L = circle_length(a);
                printf("Довжина описаного кола: %.2lf\n", L);
                break;
            }

            case 2: {
                double S = circle_area(a);
                printf("Площа описаного круга: %.2lf\n", S);
                break;
            }

            case 0:
                printf("Вихід...\n");
                break;

            default:
                printf("Невірний вибір!\n");
        }

    } while (choice != 0);

    return 0;
}