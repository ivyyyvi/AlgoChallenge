#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* TODOTODO: wrong answer when enabled */
#define PRIME_BOOSTER 1


const char* filename = "input/big_mod_input.txt";

/*Only list prime numbers smaller then sqrt(46340)=215.xxx */
const int PRIME_NUMBERS[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    211
};


/* 
    Return 1 if a prime number
    Return 0 if not a prime number
*/
int isPrime (int m)
{
    int i = 0;
    int sqrt_m = sqrt(m);
    int prime = 0;

    int table_size = sizeof(PRIME_NUMBERS)/ sizeof(PRIME_NUMBERS[0]);
    for (i = 0; i < table_size; i++) {

        prime = PRIME_NUMBERS[i];

        if (prime > sqrt_m) break;

        if (m == prime) {
            /*  m matches one of the prime numbers in table*/
            return 1;
        }
        
        if ((m % PRIME_NUMBERS[i]) == 0) {
            /*  if m is not the prime numbers itself 
                and is divisible by prime numbers, 
                then m is not a prime number*/
            return 0;
        }
    }
    return 1;
}

long long xToyModM_v2 (long long x, int y, int m)
{
    long long res = 1;

    /*printf("x, y, m = %d %d %d\n", x, y, m);*/

    
    /*
    If m is a prime number, 
    x^n (mod m) => x^(n mod(m-1)) (mod m)
    */    
    if (PRIME_BOOSTER) {
        if (isPrime (m)) {
            /*printf("m %d is a prime number.\n", m);*/
            y = y % (m-1);
            /*printf("y becomes %d.\n", y);*/
        }
    }
    

    x %= m;
    while (y > 0) {

        if (y & 1) {
            res = res * x % m;
            /*printf("res %lld\n", res);*/
        }

        x = x * x % m;
        /*printf("x %lld\n", x);*/
        y >>= 1;
        /*printf("y %lld\n", y);*/
    }

    return res;
}



int main (int argc, char *argv[])
{

    FILE *in_file = stdin;

#ifdef INPUT_FROM_FILE
    printf("=========Build to input from file=========\n");
    in_file = fopen(filename, "r");
    
    if (!in_file) {
        return -1;
    }
#endif /*INPUT_FROM_FILE*/
    
    /* res = x^y mod m*/
    /* 
    ** 0 <= x , y <= 7FFFFFFFh
    ** 1 <= m <= 46340 < 2^16
    */
    const int LEN_DATASET = 3; /* each dataset consist of three integerse*/
    long long read = 0;
    int counter = 0;
    int x , y , m = 0;
    long long res = 0;

#ifdef INPUT_BEGIN_WITH_NUM_DATASETS
    
    int num_datasets = 0;
    if ((EOF != fscanf(in_file,"%d", &read))) {
        num_datasets = read;
    } else {
        goto Exit;
    }

#endif /*INPUT_BEGIN_WITH_NUM_DATASETS*/

    while (EOF != fscanf(in_file,"%d", &read)) {

#ifdef INPUT_BEGIN_WITH_NUM_DATASETS
        if (!num_datasets) break;
#endif        
        switch (counter % LEN_DATASET)
        {
        case 0:
            x = read;
            break;
        case 1:
            y = read;
            break;
        case 2:
            m = read;
            res = xToyModM_v2((long long)x , y, m);
            printf("%lld\n", res);

#ifdef INPUT_BEGIN_WITH_NUM_DATASETS
            num_datasets--;
#endif /*INPUT_BEGIN_WITH_NUM_DATASETS*/

            break;
        default:
            break;
        }
        counter++;
    }
    /*printf("Total lines=%d\n", counter);*/

Exit:
#ifdef INPUT_FROM_FILE
    fclose(in_file); 
#endif
    return 0;
}