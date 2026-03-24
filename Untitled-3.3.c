#include <stdio.h>

int main() {
    int episode;

    printf("Ведіть номер серії (1-10): ");
    scanf("%d", &episode);

    switch (episode) {
        case 1:
            printf("Серія 1: 'Дух моди'\nДата: 16.03.2018\n");
            break;
        case 2:
            printf("Серія 2: 'Секрети'\nДата: 16.03.2018\n");
            break;
        case 3:
            printf("Серія 3: 'Минуле'\nДата: 16.03.2018\n");
            break;
        case 4:
            printf("Серія 4: 'Контракти'\nДата: 16.03.2018\n");
            break;
        case 5:
            printf("Серія 5: 'Зрада'\nДата: 16.03.2018\n");
            break;
        case 6:
            printf("Серія 6: 'Правда'\nДата: 16.03.2018\n");
            break;
        case 7:
            printf("Серія 7: 'Помста'\nДата: 16.03.2018\n");
            break;
        case 8:
            printf("Серія 8: 'Розплата'\nДата: 16.03.2018\n");
            break;
        case 9:
            printf("Серія 9: 'Фінал гри'\nДата: 16.03.2018\n");
            break;
        case 10:
            printf("Серія 10: 'Новий початок'\nДата: 16.03.2018\n");
            break;
        default:
            printf("Невірний номер серії. Будь ласка, введіть число від 1 до 10.\n");
    }
    return 0;
}