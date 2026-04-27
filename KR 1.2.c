#include <stdio.h>

int main() {
    double a, x, y;

    printf("Введіть a, x, y: ");
    scanf("%lf %lf %lf", &a, &x,&y);

    if (a >= x && a <= y) 
        printf("a належить інтервалу");
    else 
        printf("a не належить інтервалу");
        
    return 0;
}