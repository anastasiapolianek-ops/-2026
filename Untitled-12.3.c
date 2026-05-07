#include <stdio.h>
#include <stdlib.h>
#include <string.h> //РОБОТА З РЯДКАМИ
#include <math.h> // МАТЕМАТИЧНІ ФУНКЦІЇ

//  структура
typedef struct {
    char date[15];
    double temp;
    double pressure;
} Weather;

//  ввід
void inputData(Weather *arr, int n) { //Вводить дані про погоду.
    for (int i = 0; i < n; i++) { // Проходить по всіх днях.
        printf("\nДень %d:\n", i + 1);

        printf("Дата: ");
        scanf("%14s", arr[i].date);

        printf("Температура: ");
        scanf("%lf", &arr[i].temp);

        printf("Тиск: ");
        scanf("%lf", &arr[i].pressure);
    }
}

//  вивід
void printTable(Weather *arr, int n) { //Виводить таблицю погодних даних.
    printf("\n---------------------------------------\n");
    printf("%-12s %-12s %-12s\n", "Дата", "Темп", "Тиск");
    printf("---------------------------------------\n");

    for (int i = 0; i < n; i++) { // Виводить інформацію про кожен день у форматі таблиці.
        printf("%-12s %-12.2lf %-12.2lf\n",
               arr[i].date,
               arr[i].temp,
               arr[i].pressure);
    }
}

//  сортування (за спаданням температури)
void sortByTemp(Weather *arr, int n) {
    for (int i = 0; i < n - 1; i++) { // Сортує масив погодних даних за температурою у спадному порядку.
        for (int j = i + 1; j < n; j++) {
            if (arr[i].temp < arr[j].temp) { //Якщо поточний менший → міняємо місцями.
                Weather temp = arr[i]; //Тимчасова змінна потрібна для перестановки.
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//  найбільший перепад температур
void findMaxDiff(Weather *arr, int n) {
    double maxDiff = 0;
    int d1 = 0, d2 = 1;

    for (int i = 0; i < n; i++) { // Проходить по всіх днях.
        for (int j = i + 1; j < n; j++) { // Порівнює кожен день з усіма наступними днями, щоб знайти найбільший перепад температур.
            double diff = fabs(arr[i].temp - arr[j].temp); // Обчислює абсолютну різницю температур між двома днями.

            if (diff > maxDiff) { //Якщо знайдено більший перепад → оновлюємо максимальний перепад і зберігаємо індекси днів.
                maxDiff = diff; 
                d1 = i;
                d2 = j;
            }
        }
    }

    printf("\nНайбільший перепад температур:\n");
    printf("%s і %s (%.2lf)\n",
           arr[d1].date, // Виводить дати двох днів з найбільшим перепадом температур та значення цього перепаду.
           arr[d2].date,
           maxDiff);
}

//  запис у файл
void writeToFile(const char *name, Weather *arr, int n) { // Записує масив погодних даних у двійковий файл.
    FILE *f = fopen(name, "wb"); // Відкриває файл для запису у двійковому режимі. Якщо файл не існує, він буде створений. Якщо файл вже існує, його вміст буде перезаписаний.
    if (!f) { // Якщо файл не вдалося відкрити, виводить повідомлення про помилку і завершує функцію.
        printf("Помилка файлу!\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, f); // Записує кількість елементів масиву у файл. Це потрібно для того, щоб при читанні з файлу знати, скільки елементів потрібно прочитати.
    fwrite(arr, sizeof(Weather), n, f); // Записує масив погодних даних у файл. Параметри fwrite вказують на адресу масиву, розмір одного елемента (розмір структури Weather) і кількість елементів для запису (n).

    fclose(f);
}

//  читання з файлу
Weather* readFromFile(const char *name, int *n) {
    FILE *f = fopen(name, "rb");
    if (!f) {
        printf("Файл не знайдено!\n");
        return NULL;
    }

    fread(n, sizeof(int), 1, f); // Читає кількість елементів масиву з файлу і зберігає її у змінну, на яку вказує вказівник n. Це дозволяє функції повернути масив правильного розміру.

    Weather *arr = (Weather*)malloc((*n) * sizeof(Weather)); // Виділяє пам'ять для масиву погодних даних на основі кількості елементів, прочитаних з файлу. Розмір кожного елемента визначається розміром структури Weather.
    fread(arr, sizeof(Weather), *n, f); // Читає масив погодних даних з файлу і зберігає його у виділеній пам'яті. Параметри fread вказують на адресу масиву, розмір одного елемента (розмір структури Weather) і кількість елементів для читання (n).

    fclose(f);
    return arr;
}

//  запис результату
void saveResult(const char *name, Weather *arr, int n) {
    FILE *f = fopen(name, "w");

    if (!f) {
        printf("Помилка запису!\n");
        return;
    }

    for (int i = 0; i < n; i++) { // Записує інформацію про кожен день у текстовий файл у форматі: дата, температура і тиск. Параметри fprintf вказують на формат запису даних у файл.
        fprintf(f, "%s %.2lf %.2lf\n",
                arr[i].date,
                arr[i].temp,
                arr[i].pressure);
    }

    fclose(f);
}

int main() {

    Weather *arr = NULL;
    int n = 0;
    int choice;

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Ввести дані\n");
        printf("2. Записати у файл\n");
        printf("3. Зчитати з файлу\n");
        printf("4. Вивести таблицю\n");
        printf("5. Сортувати за температурою\n");
        printf("6. Знайти найбільший перепад\n");
        printf("7. Записати результат у файл\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        switch (choice) {

            case 1:
                printf("Кількість днів: ");
                scanf("%d", &n);

                arr = (Weather*)malloc(n * sizeof(Weather)); // Виділяє пам'ять для масиву погодних даних на основі введеної кількості днів.
                inputData(arr, n);
                break;

            case 2:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else
                    writeToFile("weather.bin", arr, n);
                break;

            case 3:
                arr = readFromFile("weather.bin", &n);
                break;

            case 4:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else
                    printTable(arr, n);
                break;

            case 5:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else {
                    sortByTemp(arr, n);
                    printf("Відсортований масив:\n");
                    printTable(arr, n);
                }
                break;

            case 6:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else
                    findMaxDiff(arr, n); // Викликає функцію для знаходження найбільшого перепаду температур між двома днями і виводить результат.
                break;

            case 7:
                if (arr == NULL)
                    printf("Немає даних!\n");
                else
                    saveResult("result.txt", arr, n);
                break;

            default:
                printf("Невірний вибір!\n");
        }
    }

    free(arr); // Звільняє виділену пам'ять для масиву погодних даних перед завершенням програми.
    return 0;
}