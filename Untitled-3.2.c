#include <stdio.h>

int main() {
     double A, B, C;
        printf("Ввести A, B, C: " );
        scanf("%lf %lf %lf", &A, &B, &C);
        if (A > B && A > C) {
            A = A * 2;
            B= B * 2;
            C = C * 2;
        } else {
            if (A !=0) A = 1/A;
            else printf("A = 0, оберненого не існує\n");
            if (B !=0) B = 1/B;
            else printf("B = 0, оберненого не існує\n");
            if (C !=0) C = 1/C;
            else printf("C = 0, оберненого не існує\n");
        }
   printf("Результат\n");
   printf("A = %.2lf\n", A);
   printf("B = %.2lf\n", B);
   printf("C = %.2lf\n", C);
        return 0;
}