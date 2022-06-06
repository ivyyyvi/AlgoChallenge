#include <stdio.h>  /*printf, fscanf, fclose*/
#include <stdlib.h> /*calloc, free*/


/*
TODO list:
1) To see if prime numbers are ouput correctly even in big numbers

*/

const char *input_file = "input/input.txt";
#define FALSE 0
#define TRUE 1
#define RET_STATUS_SUCCESS 0
#define RET_STATUS_FAILURE 1


/*

The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n 
(1 <= m <= n <= 1000000000, n-m<=100000) 
separated by a space.
*/
int print_prime_in_range (int m, int n)
{
    int *is_not_prime = NULL;
    int i = 0;
    long long j = 0;

    is_not_prime = calloc ((n+1), sizeof(int)); /* too big?*/
    if (is_not_prime == NULL) return RET_STATUS_FAILURE;

    is_not_prime[0] = is_not_prime[1] = TRUE;


    for (i = 2; (long long) i*i <= n; i++) {
        if (is_not_prime[i] == FALSE) {
            for (j = i*i; j <= n; j+=i) {
                is_not_prime[j] = TRUE;
            }
        }
    }

    for (i = m; i <= n; i++) {
        if (is_not_prime[i] == FALSE) {
            printf ("%d\n",i);
        }
    }

    free(is_not_prime);
    is_not_prime = NULL;


    return RET_STATUS_SUCCESS;
}



int main (int argc, char *argv[])
{
    int read, m, n = 0;
    int status = RET_STATUS_FAILURE;

    int num_test_cases = 0;
    int counter = 0;

    FILE *file = NULL;
    
#ifdef INPUT_FROM_FILE
    file = fopen(input_file, "r");
    if (file == NULL) return RET_STATUS_FAILURE;
#else
    file = stdin;
#endif

    if (fscanf(file, "%d", &num_test_cases) == EOF) return RET_STATUS_FAILURE;

    while (num_test_cases) {
        
        if (fscanf(file, "%d", &read) == EOF) break;

        switch (counter%2)
        {
        case 0:
            m = read;
            break;
        case 1:
            n = read;
            status = print_prime_in_range(m, n);
            printf("\n");
            num_test_cases--;
            break;
        default:
            break;
        }
        counter++;
    }
    
#ifdef INPUT_FROM_FILE
    fclose(file);
#endif
    return status;
}
