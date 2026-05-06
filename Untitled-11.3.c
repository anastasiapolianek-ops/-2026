#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// безпечне введення
int inputInt() {
    int x;
    while (scanf("%d", &x) != 1) { // Якщо введено не ціле число, виводимо помилку і очищаємо буфер
        printf("Помилка! Введіть число: ");
        while (getchar() != '\n'); // очищаємо буфер вводу
    }
    return x;
}

// випадкові числа [-10;10]
int randRange() {
    return rand() % 21 - 10;
}

//  створення матриці
int** createMatrix(int n, int m) {
    int **a = malloc(n * sizeof(int*)); // Виділяємо память для массива указателей на строки
    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));
    }
    return a;
}

//  заповнення
void fillMatrix(int **a, int n, int m) { // Проходимо по каждому элементу матриці и заполняем его случайным числом
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = randRange();
}

//  вивід
void printMatrix(int **a, int n, int m, const char *msg) { // Виводимо матрицю с сообщением
    printf("\n%s\n", msg);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

//  головна функція (формування нового масиву)
void createNegativeMatrix(int **a, int n, int m) {

    printf("\nНовий масив (значення, номер рядка):\n");

    for (int j = 0; j < m; j++) {
        printf("Стовпець %d:\n", j);

        for (int i = 0; i < n; i++) {
            if (a[i][j] < 0) {
                printf("(%d, рядок %d)\n", a[i][j], i);
            }
        }
    }
}

//  звільнення
void freeMatrix(int **a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

int main() {
    srand(time(NULL));

    int n, m;

    printf("Введіть кількість рядків n: ");
    n = inputInt();

    printf("Введіть кількість стовпців m: ");
    m = inputInt();

    if (n <= 0 || m <= 0) {
        printf("Помилка! Розміри мають бути > 0\n");
        return 1;
    }

    int **a = createMatrix(n, m);

    fillMatrix(a, n, m);
    printMatrix(a, n, m, "Початкова матриця:");

    createNegativeMatrix(a, n, m);

    freeMatrix(a, n);

    return 0;
}