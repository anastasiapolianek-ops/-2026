#include <stdio.h>

//  перевірка умови числа
int isValid(int i) { //Перевіряє, чи відповідає число умові задачі.

    return (i % 6 != 0 && //Перевіряє, чи не ділиться число на 6, 10 та 15 без остачі.
            i % 10 != 0 &&
            i % 15 != 0);
}

//  рекурсивний підрахунок
int countNumbers(int current) {

    // базовий випадок
    if (current > 1000)
        return 0;

    // якщо число підходить
    if (isValid(current))
        return 1 + countNumbers(current + 1);

    // якщо не підходить
    return countNumbers(current + 1);
}

//  меню
void showMenu() {

    printf("\n===== МЕНЮ =====\n");
    printf("1. Порахувати числа (1–1000)\n");
    printf("2. Вихід\n");
    printf("Ваш вибір: ");
}

int main() {

    int choice;

    while (1) {

        showMenu();
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Кількість чисел: %d\n",
                       countNumbers(1)); //Починає підрахунок з числа 1.
                break;

            case 2:
                printf("Вихід з програми...\n");
                return 0;

            default:
                printf("Невірний вибір!\n");
        }
    }

    return 0;
}