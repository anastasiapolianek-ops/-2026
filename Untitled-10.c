#include <stdio.h>
#include <ctype.h>

//  створення і запис у файл
void createAndWriteFile(char filename[]) { //відкриває файл для запису
    FILE *f = fopen(filename, "w");// означє створити якщо нема файла або перезапусти якщо вже є

    if (f == NULL) {
        printf("Не вдалося створити файл!\n");
        return;
    }

    fprintf(f, "Hello World! This is a test file with some vowels.\n");
    fprintf(f, "C programming is fun and interesting.\n");
    fprintf(f, "abcdefghijklmnopqrstuvwxyz\n");

    fclose(f);

    printf("Файл створено і записано успішно!\n");
}

//  підрахунок голосних
void countVowels(char filename[]) { // читає символи по одному і рахує голосні
    int ch;
    int a=0, e=0, i_c=0, o=0, u=0, y=0;

    FILE *f = fopen(filename, "r"); //тілки для читтання

    if (f == NULL) {
        printf("Не вдалося відкрити файл!\n");
        return;
    }

    while ((ch = fgetc(f)) != EOF) {// читає 1 символ повертає файл коли закінчився
        ch = tolower(ch); // рахуються однаково В і м букви

        switch (ch) { //якщо голосна збільшуємо лічильник
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i_c++; break;
            case 'o': o++; break;
            case 'u': u++; break;
            case 'y': y++; break;
        }
    }

    fclose(f);

    printf("\nКількість голосних:\n");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i_c);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
    printf("y: %d\n", y);
}

int main() {
    int choice;
    char filename[] = "test.txt"; // ім'я файлу для роботи

    do {
        printf("\n===== МЕНЮ =====\n");
        printf("1. Створити файл і записати текст\n");
        printf("2. Порахувати голосні\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAndWriteFile(filename);
                break;

            case 2:
                countVowels(filename);
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