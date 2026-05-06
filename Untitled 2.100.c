#include <stdio.h>

// введення
void inputArray(double a[], int n) { //проходить по масиву від 0 до n-1 вводить кожен елемент з клавіатури
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
}

// обчислення добутку
double product(double a[], int n) {
    double result = 1; //починаємо з 1
    for (int i = 0; i < n; i++) {
        result *= a[i]; // множимо на кожен елемент масиву
    }
    return result;//повертає
}

// вивід
void printResult(double b) {
    printf("Добуток = %.2lf\n", b);
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n); //розмір масиву

    double a[n];

    inputArray(a, n); //вводимо елементи
    double b = product(a, n); //рахуємо добуток
    printResult(b);

    return 0;
}