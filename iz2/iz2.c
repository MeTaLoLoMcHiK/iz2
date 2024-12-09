#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 0.0, b = 1.0; 
    int k = 10;             
    double epsilon = 0.0001; 
    double h = (b - a) / (k - 1); 
    double x, sum, term, exact, error;
    int n;

    printf("x\tРяд\t\tТочне значення\tПохибка\n");

    for (int i = 0; i < k; i++) {
        x = a + i * h;
        sum = 0.0;
        n = 1;

        do {
            term = pow(sin(n * x), 1.0) / factorial(n);
            sum += term;
            n++;
        } while (fabs(term) > epsilon);

        
        exact = exp(sin(x)) * sin(cos(x));
        error = fabs(sum - exact);

        printf("%lf\t%lf\t%lf\t%lf\n", x, sum, exact, error);
    }

    return 0;
}
