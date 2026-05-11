#include <stdio.h>

//  рекурсивний реверс числа
int reverseNumber(int num, int reversed) {

    // базовий випадок
    if (num == 0)
        return reversed;

    return reverseNumber(
        num / 10,
        reversed * 10 + num % 10 //Додає останню цифру до реверсованого числа
    );
}

//  перевірка паліндрома
int isPalindrome(int num) {

    int reversed = reverseNumber(num, 0); //Отримує реверс числа.

    return (num == reversed); //Порівнює оригінальне число з реверсом для визначення, чи є воно паліндромом.
}

//  введення числа
int inputNumber() {
    int n;

    printf("Введіть натуральне число: ");
    scanf("%d", &n);

    return n;
}

//  перевірка числа
void checkPalindrome() {

    int n = inputNumber();

    if (n <= 0) {
        printf("Потрібно ввести натуральне число!\n");
        return;
    }

    if (isPalindrome(n)) // Перевіряє, чи є число паліндромом.
        printf("Число є паліндромом\n");
    else
        printf("Число НЕ є паліндромом\n");
}

//  меню
void showMenu() {
    printf("\n===== МЕНЮ =====\n");
    printf("1. Перевірити число на паліндром\n");
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
                checkPalindrome(); // Викликає функцію для перевірки числа на паліндром.
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