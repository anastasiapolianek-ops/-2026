#include <stdio.h>

int main (){
    int n;

    printf("Введіть вік (n < 100): ");
    scanf ("%d", &n);

    if (n % 10 == 1 && n % 100 != 11)
        printf("%d рік\n", n);
    else if ((n % 10 >= 2 && n % 10 <= 4) && !(n % 100 >= 12 && n % 100 <= 14))
        printf("%d роки\n", n);
    else
        printf("%d років\n", n);

    return 0;

}