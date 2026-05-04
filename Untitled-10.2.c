#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.bin" // ім'я файлу для роботи

// створення файлу
void createFile() {
    FILE *f = fopen(FILENAME, "wb"); //б двійковий режим

    if (f == NULL) {
        printf("Не вдалося створити файл!\n");
        return;
    }

    int n, value;

    printf("Скільки чисел записати? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Введіть число %d: ", i + 1);
        scanf("%d", &value);
        fwrite(&value, sizeof(int), 1, f); // записує число у двійковому форматі
    }

    fclose(f);
    printf("Файл створено!\n");
}

//  додавання в кінець
void addToFile() {
    FILE *f = fopen(FILENAME, "ab"); // a - відкриває для додавання, b - двійковий режим

    if (f == NULL) {
        printf("Не вдалося відкрити файл!\n");
        return;
    }

    int n, value;

    printf("Скільки чисел додати? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { // додаємо числа в кінець
        printf("Введіть число %d: ", i + 1);
        scanf("%d", &value); // зчитуємо число з консолі
        fwrite(&value, sizeof(int), 1, f); // записує число у двійковому форматі
    }

    fclose(f);
    printf("Дані додано!\n");
}

// показ файлу
void showFile() {
    FILE *f = fopen(FILENAME, "rb"); // r - відкриває для читання, b - двійковий режим

    if (f == NULL) {
        printf("Файл не знайдено!\n");
        return;
    }

    int value;

    printf("\nДані у файлі:\n");

    while (fread(&value, sizeof(int), 1, f)) { // читає по одному числу, повертає кількість прочитаних елементів читає поки є данні
        printf("%d ", value);// виводить число
    }

    printf("\n");

    fclose(f);
}

//  видалення N елементів з кінця (БЕЗ _chsize)
void removeLastElements() {
    FILE *f = fopen(FILENAME, "rb");

    if (f == NULL) {
        printf("Файл не знайдено!\n");
        return;
    }

    int count;

    printf("Скільки елементів видалити? ");
    scanf("%d", &count); 

    // розмір файлу
    fseek(f, 0, SEEK_END);
    int size = ftell(f) / sizeof(int); //ftell повертає розмір у байтах sizeof(int) - розмір одного числа, ділимо щоб отримати кількість чисел 
    rewind(f);

    if (count > size) { 
        printf("Забагато елементів для видалення!\n");
        fclose(f);
        return;
    }

    // читаємо всі дані
    int *arr = (int*)malloc(size * sizeof(int));

    fread(arr, sizeof(int), size, f); //всі числа в память
    fclose(f);

    // записуємо назад без останніх count
    FILE *f2 = fopen(FILENAME, "wb"); //відкриває і очищює файл

    for (int i = 0; i < size - count; i++) {// записуємо всі числа крім останніх count
        fwrite(&arr[i], sizeof(int), 1, f2); // записуємо по одному числу у двійковому форматі
    }

    fclose(f2);
    free(arr); //щоб не було витоку пам'яті

    printf("Видалено %d елементів!\n", count);
}

//  меню
void menu() {
    printf("\n===== МЕНЮ =====\n");
    printf("1. Створити файл\n");
    printf("2. Додати числа\n");
    printf("3. Показати файл\n");
    printf("4. Видалити елементи з кінця\n");
    printf("0. Вихід\n");
}

int main() {
    int choice;

    do {
        menu();
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;

            case 2:
                addToFile();
                break;

            case 3:
                showFile();
                break;

            case 4:
                removeLastElements();
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