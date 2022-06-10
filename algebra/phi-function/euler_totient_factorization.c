#include <stdio.h>


int GetPhiByFactorization(int n){

    int i = 0;
    int result = n;

    for (i=2; i*i < n; i++) {
        if (n%i == 0) {
            while(n%i ==0) {
                n = n/i;
            }
            
            result -= result/i;
        }
    }
    if (n > 1) {
        result -= result/n;
    }
    return result;
}


int main (int argc, char *argv[]) {
    int result = GetPhiByFactorization(10);
    printf("result=%d\n", result);
    return 0;
}