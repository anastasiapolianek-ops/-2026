#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 🔹 перевірка на латиницю
int hasLatin(char *word) {
    for (int i = 0; word[i]; i++) {
        if ((word[i] >= 'a' && word[i] <= 'z') ||
            (word[i] >= 'A' && word[i] <= 'Z')) {
            return 1;
        }
    }
    return 0;
}

// 🔹 а) видалення слів з латиницею
void removeLatinWords(char text[], char result[]) {
    char temp[256];
    strcpy(temp, text); // щоб не псувати оригінал

    result[0] = '\0';

    char *word = strtok(temp, " \n");

    while (word != NULL) {
        if (!hasLatin(word)) {
            strcat(result, word);
            strcat(result, " ");
        }
        word = strtok(NULL, " \n");
    }
}

// 🔹 б) видалення цифр
void removeDigits(char text[], char result[]) {
    int j = 0;

    for (int i = 0; text[i]; i++) {
        if (!isdigit(text[i])) {
            result[j++] = text[i];
        }
    }
    result[j] = '\0';
}

int main() {
    char text[256];

    printf("Введіть рядок:\n");
    fgets(text, sizeof(text), stdin);

    int choice;
    char result1[256], result2[256];

    do {
        printf("\n----Меню----\n");
        printf("1. Видалити слова з латиницею\n");
        printf("2. Видалити цифри\n");
        printf("3. Показати початковий рядок\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                removeLatinWords(text, result1);
                printf("\nБез латинських слів:\n%s\n", result1);
                break;

            case 2:
                removeDigits(text, result2);
                printf("\nБез чисел:\n%s\n", result2);
                break;

            case 3:
                printf("\nПочатковий рядок:\n%s\n", text);
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