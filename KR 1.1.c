# include <stdio.h>

int main () {
    double x, y, result;

    printf ("Ведіть x та y:");
    scanf("%lf %lf", &x, &y );

    if (y + 2 == 0) {
        printf ("Помилка: ділення на нуль\n");
    } else {
        result = x * x + (2*x - 10 / (y + 2));
        printf ("Результат: %.2lf\n", result);
    }
    return 0;
}