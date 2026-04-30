#include <stdio.h>

int main() {
    int n, m;

    printf("Введіть кількість рядків n: ");
    scanf("%d", &n);

    printf("Введіть кількість стовпців m: ");
    scanf("%d", &m);

    int A[n][m];
    int b[m];

    printf("\nВведіть матрицю:\n");

    // Ввід
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int choice;

    do {
        printf("\n----Меню----\n");
        printf("1. Вивести масив b\n");
        printf("2. Вивести матрицю A\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                for (int j = 0; j < m; j++) {
                    int max = A[0][j], min = A[0][j];
                    int i_max = 0, i_min = 0;

                    for (int i = 0; i < n; i++) {
                        if (A[i][j] > max) {
                            max = A[i][j];
                            i_max = i;
                        }
                        if (A[i][j] < min) {
                            min = A[i][j];
                            i_min = i;
                        }
                    }

                    int prod_max = 1, prod_min = 1;

                    for (int k = 0; k < m; k++) {
                        prod_max *= A[i_max][k];
                        prod_min *= A[i_min][k];
                    }

                    b[j] = prod_max * prod_min;
                }

                printf("\nМасив b:\n");
                for (int j = 0; j < m; j++) {
                    printf("%d ", b[j]);
                }
                printf("\n");
                break;

            case 2:
                printf("\nМатриця A:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", A[i][j]);
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