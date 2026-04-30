#include <stdio.h>

int main() {

    const int n = 3, m = 4;
    double A[3][4];

    // Ввід
    printf("Введіть матрицю:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    int choice;

    do {
        printf("\n----Меню----\n");
        printf("1. Відсортувати стовпці\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                for (int j = 0; j < m; j++) {
                    for (int i = 0; i < n - 1; i++) {
                        for (int k = i + 1; k < n; k++) {
                            if (A[i][j] > A[k][j]) {
                                double temp = A[i][j];
                                A[i][j] = A[k][j];
                                A[k][j] = temp;
                            }
                        }
                    }
                }

                printf("\nВідсортована матриця:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%6.2lf", A[i][j]);
                    }
                    printf("\n");
                }
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