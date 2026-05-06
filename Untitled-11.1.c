#include <stdio.h>
#include <stdlib.h>

//  перевірка введення int
int inputInt() { // Ця функція для ввести ціле число
    int x;
    while (scanf("%d", &x) != 1) { // Якщо введено не ціле число, виводимо помилку і очищаємо буфер
        printf("Помилка! Введіть ціле число: ");
        while (getchar() != '\n'); // очищаємо буфер вводу
    }
    return x;
}

//  введення масиву
void inputArray(int *a, int n) { // Ця функція для введення масиву цілих чисел
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) { //проходимо по масиву від 0 до n-1
        printf("a[%d] = ", i);
        a[i] = inputInt(); // Використовуємо inputInt для безпечного введення цілих чисел
    }
}

//  вивід масиву
void printArray(int *a, int n) {
    if (a == NULL || n <= 0) { // Перевірка на порожній масив
        printf("Масив порожній!\n");
        return;
    }

    printf("Масив:\n");
    for (int i = 0; i < n; i++) { //проходимо по масиву від 0 до n-1 і виводимо кожен елемент
        printf("%d ", a[i]);
    }
    printf("\n");
}

// видалення елементів між min і max
int removeBetweenMinMax(int *a, int n) {
    int min_i = 0, max_i = 0; // Ініціалізуємо індекси мінімального і максимального елементів

    for (int i = 1; i < n; i++) { //проходимо по масиву від 1 до n-1, порівнюємо кожен елемент з поточними min і max
        if (a[i] < a[min_i]) min_i = i;
        if (a[i] > a[max_i]) max_i = i; 
    }

    int start = (min_i < max_i) ? min_i : max_i; // Визначаємо початковий індекс для видалення (менший з двох)
    int end   = (min_i > max_i) ? min_i : max_i; // Визначаємо кінцевий індекс для видалення (більший з двох)

    if (end - start <= 1) { // Якщо між min і max немає елементів для видалення (тобто вони сусідні або однакові)
        printf("Між min і max немає елементів для видалення.\n");
        return n; // Повертаємо початковий розмір масиву, оскільки нічого не видаляємо
    }

    int new_n = 0; // Ініціалізуємо новий розмір масиву після видалення

    for (int i = 0; i < n; i++) { // копіюємо елементи, які не знаходяться між min і max
        if (i <= start || i >= end) { // Якщо індекс елемента знаходиться поза межами між min і max, копіюємо його в новий масив
            a[new_n++] = a[i]; // Копіюємо елемент і збільшуємо лічильник нового розміру масиву
        }
    }

    printf("Елементи між min і max видалено.\n");
    return new_n; // Повертаємо новий розмір масиву після видалення
}

//  меню
void menu() {
    printf("\n===== МЕНЮ =====\n");
    printf("1. Ввести масив\n");
    printf("2. Вивести масив\n");
    printf("3. Видалити елементи між min і max\n");
    printf("0. Вихід\n");
    printf("=================\n");
    printf("Ваш вибір: ");
}

int main() {
    int *a = NULL;
    int n = 0;
    int choice;

    while (1) {
        menu();
        choice = inputInt();

        switch (choice) {

        case 1:
            if (a != NULL) {
                free(a);
            }

            printf("Введіть розмір масиву n: ");
            n = inputInt();

            if (n <= 0) {
                printf("Помилка! n має бути > 0\n");
                a = NULL;
                n = 0;
                break;
            }

            a = (int*)malloc(n * sizeof(int)); // Виділяємо память для массива целых чисел
            if (a == NULL) {
                printf("Помилка виділення пам’яті!\n");
                return 1;
            }

            inputArray(a, n);
            break;

        case 2:
            printArray(a, n);
            break;

        case 3:
            if (a == NULL) {
                printf("Спочатку створіть масив!\n");
                break;
            }
            n = removeBetweenMinMax(a, n);
            break;

        case 0:
            printf("Вихід...\n");
            free(a);
            return 0;

        default:
            printf("Невірний вибір!\n");
        }
    }
}