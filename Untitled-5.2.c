#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    const int n = 10;
    int a[n];
    int choice;
    int isFilled = 0;

    srand(time(0));

    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Згенерувати масив\n");
        printf("2. Обчислити (нулі і добуток)\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        switch (choice) {

            case 1:
                // генерація масиву
                for (int i = 0; i < n; i++) {
                    a[i] = -100 + rand() % 201;
                }

                printf("Масив:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");

                isFilled = 1;
                break;

            case 2:
                if (!isFilled) {
                    printf("Спочатку згенеруйте масив!\n");
                    break;
                }

                // 1) кількість нулів
                int zeroCount = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] == 0)
                        zeroCount++;
                }

                // 2) max за модулем
                int max_i = 0;
                for (int i = 1; i < n; i++) {
                    if (abs(a[i]) > abs(a[max_i]))
                        max_i = i;
                }

                // 3) добуток після max
                long long product = 1;
                int found = 0;

                for (int i = max_i + 1; i < n; i++) {
                    product *= a[i];
                    found = 1;
                }

                printf("Кількість нулів: %d\n", zeroCount);

                if (found)
                    printf("Добуток після max: %2lld\n", product);
                else
                    printf("Немає елементів після max\n");

                break;

            default:
                printf("Невірний вибір!\n");
        }
    }

    return 0;
}