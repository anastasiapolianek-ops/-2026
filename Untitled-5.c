#include <stdio.h>
#include <math.h>

int main () {
    int n;
    int a[100], b[100];
    int choice;
    int isFilled = 0;

    while (1) {
        printf("\n---Меню----\n");
        printf("1.Вивести масив:\n");
        printf("2.Видалити елементи між min і max\n");
        printf("0.Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } 
        switch (choice) {
            case 1:
                printf("Введіть кількість елементів масиву: ");
                scanf("%d", &n);
                printf("Введіть елементи масиву:\n");
                for (int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }
                isFilled = 1; //масив введено
                break;
            case 2: {
                if (!isFilled) {
                    printf("Спочатку заповніть масив (опція 1).\n");
                    break;
                }
                int min_i = 0, max_i = 0;

                for (int i = 1; i < n; i++) {
                    if (a[i] < a[min_i]) min_i = i; //індекс мінімального елемента
                    if (a[i] > a[max_i]) max_i = i; //індекс максимального елемента
                }

            int start = min_i < max_i ? min_i : max_i;
            int end = min_i > max_i ? min_i : max_i;

            int j = 0;
            for (int i = 0; i < n; i++) {
                if (i < start || i > end) {
                    b[j++] = a[i];
                }
            }

            printf("Новий масив:\n");
            for (int i = 0; i < j; i++) {
                printf("%d ", b[i]);
            }
            printf("\n");
                break;
        }
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
    }
}
                return 0;
        }