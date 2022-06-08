#include <stdio.h>

int phi(int n) {
    int result = n;
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main (int argc, char *argv[]) {
    int result = phi(10);
    printf("result=%d\n", result);
    return 0;
}