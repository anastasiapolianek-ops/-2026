#include <stdio.h>
#include <math.h>  

int main() {
    double a = 15;
    double b = 0;
    double c = -3;
    double y;
    
 if (2 + c ==0){
    printf("Помилка: ділення на нуль!\n");
return 1;
 }
    y = (5 * a - b + pow (c , 2)) / (2 + c) + 1;
    printf("Вхідні данні: \n");
    printf("a = %.2lf , b = %.2lf , c = %.2lf \n ", a, b, c);

    printf("Результат\n");
    printf("y = %.2lf\n", y);
return 1;

}