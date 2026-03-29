#include <stdio.h>

int main() {
    int n;
    double x, S = 0;

    printf("Введіть n i x: ");
    scanf("%d %lf", &n, &x);

    for (int i = 1; i <=n; i++) {
        for (int j = 2; j <= n; j++) {
            S += (x +j);
        }
    }
    printf("Сума S = %.2lf\n", S);
    return 0;
}