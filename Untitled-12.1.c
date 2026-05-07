#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Структура
typedef struct {
    char surname[50];
    char initials[10]; //ініціали
    int birthYear;
    double salary; // оклад
} Employee;

//  Вивід таблиці
void printTable(Employee *arr, int n) { //Виводить таблицю працівників.
    printf("\nВідділ кадрів\n");
    printf("-------------------------------------------------------------\n");
    printf("%-15s %-10s %-12s %-10s\n", "Прізвище", "Ініціали", "Рік", "Оклад");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) { // Виводить інформацію про кожного працівника у форматі таблиці.
        printf("%-15s %-10s %-12d %-10.2lf\n",
               arr[i].surname,
               arr[i].initials,
               arr[i].birthYear,
               arr[i].salary);
    }

    printf("-------------------------------------------------------------\n");
    printf("Примітка: оклад встановлений станом на 1 січня 2000 року\n");
}

//  Сортування за прізвищем
void sortBySurname(Employee *arr, int n) {
    for (int i = 0; i < n - 1; i++) { // Сортує масив працівників за прізвищем у алфавітному порядку.
        for (int j = i + 1; j < n; j++) { 
            if (strcmp(arr[i].surname, arr[j].surname) > 0) { // Порівнює прізвища двох працівників і міняє їх місцями, якщо вони не в алфавітному порядку.
                Employee temp = arr[i]; //Тимчасова змінна потрібна для перестановки.
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Ввід даних
void inputData(Employee *arr, int n) {
    for (int i = 0; i < n; i++) { // Вводить дані про кожного працівника з клавіатури.
        printf("\nПрацівник %d:\n", i + 1);

        printf("Прізвище: ");
        scanf("%s", arr[i].surname);

        printf("Ініціали: ");
        scanf("%s", arr[i].initials);

        printf("Рік народження: ");
        scanf("%d", &arr[i].birthYear);

        printf("Оклад: ");
        scanf("%lf", &arr[i].salary);
    }
}

int main() {
    int n = 0; // Кількість працівників
    Employee *arr = NULL; // Динамічний масив для зберігання інформації про працівників
    int choice; // Змінна для зберігання вибору користувача

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Ввести дані\n");
        printf("2. Вивести таблицю\n");
        printf("3. Сортувати за прізвищем\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {

            case 1:
                printf("Кількість працівників: ");
                scanf("%d", &n);

                //  динамічна пам’ять
                arr = (Employee*)malloc(n * sizeof(Employee)); // Виділяє пам'ять для масиву працівників на основі введеної кількості.

                if (arr == NULL) {
                    printf("Помилка виділення пам'яті!\n");
                    return 1;
                }

                inputData(arr, n); // Викликає функцію для вводу даних про працівників.
                break;

            case 2:
                if (arr == NULL) {
                    printf("Спочатку введіть дані!\n");
                } else {
                    printTable(arr, n);
                }
                break;

            case 3:
                if (arr == NULL) {
                    printf("Немає даних для сортування!\n");
                } else {
                    sortBySurname(arr, n);
                    printf("Відсортовано!\n");
                }
                break;

            default:
                printf("Невірний вибір!\n");
        }
    }

    //  звільнення пам’яті
    free(arr);

    return 0;
}