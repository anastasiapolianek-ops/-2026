#include <stdio.h>
#include <math.h> 
int main() {
    int a, b;
    double x;
    printf("Ведіть a:");
    scanf("%d, &a");

    printf("Ведіть b:");
    scanf("%d, &b");

 if (3* (a * a - 3 * b) == 0 ) {
   printf("Помилка: ділення на нуль!\n");
   return 1;
}
   x = (2 * cos(a) - (pow (b, 2))/3* (pow(a, 2) - 3 * b));
   printf("Результат\n");
   printf("x = %.2lf\n", x);

}