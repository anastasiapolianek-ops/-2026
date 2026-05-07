#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  структура
typedef struct {
    char month[20];
    double plan;
    double fact;
    double percent;
} Report;

//  обчислення %
void calculatePercent(Report *arr, int n) { // Обчислює відсоток виконання плану для кожного місяця на основі фактичного випуску та плану.
    for (int i = 0; i < n; i++) {
        if (arr[i].plan != 0) 
            arr[i].percent = (arr[i].fact / arr[i].plan) * 100; // Якщо план не дорівнює нулю, обчислює відсоток виконання як (факт / план) * 100.
        else
            arr[i].percent = 0; // Якщо план дорівнює нулю, встановлює відсоток виконання в 0, щоб уникнути ділення на нуль.
    }
}

//  ввід
void inputData(Report *arr, int n) {  // Вводить дані про кожен місяць з клавіатури, включаючи назву місяця, плановий випуск та фактичний випуск. Після введення даних викликає функцію для обчислення відсотка виконання плану.
    for (int i = 0; i < n; i++) { // Проходить по всіх місяцях.
        printf("\nМісяць %d:\n", i + 1);

        printf("Назва місяця: ");
        scanf("%s", arr[i].month);

        printf("План: ");
        scanf("%lf", &arr[i].plan);

        printf("Факт: ");
        scanf("%lf", &arr[i].fact);
    }

    calculatePercent(arr, n); // ОБЧИСЛЮЄ ВІДСОТКИ
}

//  вивід
void printTable(Report *arr, int n) { 
    printf("\nРезультати підприємства:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-15s %-15s %-15s %-19s\n", "Місяць  ", "План випуска ", "фактичний випуск  ", "%");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) { 
        printf("%-15s %-15.2lf %-15.2lf %-19.2lf\n",
               arr[i].month, 
               arr[i].plan,
               arr[i].fact,
               arr[i].percent);
    }

    printf("-------------------------------------------------------------\n");
}

//  сортування за %
void sortByPercent(Report *arr, int n) { 
    for (int i = 0; i < n - 1; i++) { // Сортує масив звітів за відсотком виконання плану у спадному порядку.
        for (int j = i + 1; j < n; j++) {
            if (arr[i].percent > arr[j].percent) { //Якщо поточний більший → міняємо місцями.
                Report temp = arr[i]; //ОБМІН
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//  пошук min і max
void findMinMax(Report *arr, int n) {
    int min_i = 0, max_i = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].percent < arr[min_i].percent) //Якщо знайдено менше значення → оновлюємо індекс.
            min_i = i;
        if (arr[i].percent > arr[max_i].percent) //Якщо знайдено більше значення → оновлюємо індекс.
            max_i = i; 
    }

    printf("\nМінімальний %%: %s (%.2lf%%)\n",
           arr[min_i].month, arr[min_i].percent); // Виводить місяць з мінімальним відсотком виконання та його значення.

    printf("Максимальний %%: %s (%.2lf%%)\n",
           arr[max_i].month, arr[max_i].percent);
}

int main() {

    Report *arr = NULL;
    int n = 0;
    int choice;

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Ввести дані\n");
        printf("2. Вивести таблицю\n");
        printf("3. Сортувати за %% виконання\n");
        printf("4. Знайти min/max\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        switch (choice) {

            case 1:
                printf("Кількість місяців: ");
                scanf("%d", &n);
//  динамічна пам’ять
                arr = (Report*)malloc(n * sizeof(Report)); // Виділяє пам'ять для масиву звітів на основі введеної кількості місяців.

                if (arr == NULL) {
                    printf("Помилка пам'яті!\n");
                    return 1;
                }

                inputData(arr, n);
                break;

            case 2:
                if (arr == NULL)
                    printf("Спочатку введіть дані!\n");
                else
                    printTable(arr, n);
                break;

            case 3:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else {
                    sortByPercent(arr, n);
                    printf("Відсортовано!\n");
                }
                break;

            case 4:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else
                    findMinMax(arr, n);
                break;

            default:
                printf("Невірний вибір!\n");
        }
    }

    free(arr); // Звільняє виділену пам'ять для масиву звітів.
    return 0;
}