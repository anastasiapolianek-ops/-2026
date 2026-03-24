#include <stdio.h>

int main() {
    int a, b;
    int remainder, difference, sumSquares;\
    // Введення даних
    printf("Введіть перше ціле число (a): ");
    scanf("%d", &a);
    printf("Введіть друге ціле число (b): ");
    scanf("%d", &b);
    // Перевірка ділення на нуль
    if (b == 0) {
    printf("Помилка: ділення на нуль неможливе!\n");
    } else {
    remainder = a % b;
    printf("Залишок від ділення a на b: %d\n", remainder);
    }
    // Обчислення різниці
    difference = b - a;
    printf("Різниця (b - a): %d\n", difference);
    // Обчислення суми квадратів
    sumSquares = a * a + b * b;
    printf("Сума квадратів: %d\n", sumSquares);

    return 0;
}