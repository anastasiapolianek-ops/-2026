#include <stdio.h>

// 🔹 1) сума елементів з непарними індексами
int sumOddIndex(int a[], int n) {
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += a[i];
    }
    return sum;
}

// 🔹 2) сума між першим і другим додатними
int sumBetweenPositive(int a[], int n) {
    int first = -1, second = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (first == -1)
                first = i;
            else {
                second = i;
                break;
            }
        }
    }

    int sum = 0;

    if (first != -1 && second != -1) {
        for (int i = first + 1; i < second; i++) {
            sum += a[i];
        }
    }

    return sum;
}

int main() {
    int n;

    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    int a[n];

    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int choice;

    do {
        printf("\n----Меню----\n");
        printf("1. Сума елементів з непарними індексами\n");
        printf("2. Сума між першим і другим додатними\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Сума: %d\n", sumOddIndex(a, n));
                break;

            case 2:
                printf("Сума: %d\n", sumBetweenPositive(a, n));
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
