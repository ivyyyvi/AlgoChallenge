#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
#define RET_STATUS_SUCCESS 0
#define RET_STATUS_FAILURE 1

int print_prime_until_n (int n)
{
    int *is_prime = NULL;
    int i = 0;
    long long j = 0;
    int is_prime_counter = 0;

    is_prime = malloc ((n+1) * sizeof(int));
    if (is_prime == NULL) return RET_STATUS_FAILURE;

    is_prime[0] = is_prime[1] = FALSE;
    for (i = 2; i <= n; i++) {
        is_prime[i] = TRUE;
    }

    for (i = 2; (long long) i*i <= n; i++) {
        if (is_prime[i]) {
            for (j = i*i; j <= n; j+=i) {
                is_prime[j] = FALSE;
            }
        }
    }

    for (i = 2; i <= n; i++) {
        if (is_prime[i] == TRUE) {
            is_prime_counter++;
            if (is_prime_counter%100 == 1) {
                printf ("%d\n",i);
            }
        }

    }

    return RET_STATUS_SUCCESS;
}

int main (int argc, char *argv[])
{
    int n = 0;
    int status = RET_STATUS_FAILURE;

    n = pow(10, 8);/*10^8;*/
    status = print_prime_until_n(n);
    return status;
}
