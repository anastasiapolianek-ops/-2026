#include <stdio.h>
#include <stdlib.h>

// 🔹 функція сортування (за спаданням)
int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// 🔹 1) номер максимального елемента
int findMaxIndex(int a[], int n) {
    int max = a[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    return index;
}

// 🔹 2) сума модулів 5 найбільших
int sumTop5(int a[], int n) {
    qsort(a, n, sizeof(int), cmp);

    int sum = 0;
    int k = (n < 5) ? n : 5;

    for (int i = 0; i < k; i++) {
        sum += abs(a[i]);
    }
    return sum;
}

int main() {
    int n;

    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    int a[n];

    printf("Введіть елементи:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int choice;

    do {
        printf("\n----Меню----\n");
        printf("1. Номер максимального елемента\n");
        printf("2. Сума модулів 5 найбільших елементів\n");
        printf("3. Показати масив\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Номер максимального елемента: %d\n", findMaxIndex(a, n));
                break;

            case 2:
                printf("Сума модулів: %d\n", sumTop5(a, n));
                break;

            case 3:
                printf("Масив:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;

            case 0:
                printf("Вихід...\n");
                break;

            default:
                printf("Невірний вибір!\n");
        }

    } while (choice != 0);

    return 0;
}