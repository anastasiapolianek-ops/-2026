#include <stdio.h>

// введення
void inputArray(double a[], int n) { //Користувач вводить n чисел:
    for (int i = 0; i < n; i++) {
        printf("[%d] = ", i);
        scanf("%lf", &a[i]);
    }
}

// вивід
void printArray(double a[], int n) { //Виводить всі елементи:
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    printf("\n");
}

// сортування за спаданням
void sortDesc(double a[], int n) { // сортування за спаданням
    for (int i = 0; i < n-1; i++) {  //проходимо по масиву від 0 до n-2
        for (int j = 0; j < n-i-1; j++) { 
            if (a[j] < a[j+1]) { //якщо лівий менший → міняємо місцями
                double temp = a[j];
                a[j] = a[j+1];  
                a[j+1] = temp; //міняємо місцями
            }
        }
    }
}

// порівняння
void compareK(double a[], double b[], int k) {
    if (a[k-1] > b[k-1]) //масиви в C починаються з 0
        printf("У масиві A більший елемент\n");
    else if (a[k-1] < b[k-1]) //якщо елемент масиву A менший за відповідний елемент масиву B
        printf("У масиві B більший елемент\n");
    else
        printf("Елементи рівні\n");
}

int main() {
    int n, k;

    printf("n = ");
    scanf("%d", &n);

    double a[n], b[n];

    printf("Масив A:\n");
    inputArray(a, n); // Вводимо елементи масиву A

    printf("Масив B:\n");
    inputArray(b, n); // Вводимо елементи масиву B
 // Сортуємо обидва масиви за спаданням
    sortDesc(a, n);
    sortDesc(b, n);
// Виводимо відсортовані масиви
    printf("A: "); printArray(a, n);
    printf("B: "); printArray(b, n);

    printf("k = ");
    scanf("%d", &k);

    compareK(a, b, k);

    return 0;
}