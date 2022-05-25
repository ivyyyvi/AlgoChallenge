#include <stdio.h>
#include <stdlib.h>

const char* filename = "input.txt";

//
// read input
//
int readInput (void)
{

    FILE *in_file = fopen(filename, "r");
    if (!in_file) {
        perror("fopen");
        return -1;
    }

    printf("Awesome. readInput can read the file.\n");

    int file_contents;
    printf("sizeof(file_contents) %d\n", sizeof(file_contents));

    while (fscanf(in_file, "%d" , &file_contents) != EOF) {
        printf("Read: %d \n", file_contents);
        printf("-----\n");
    }

    fclose(in_file);    
    return 0;
}


long long xToYModM(int x, int y, int m)
{
    //printf("x: %d, y:%d, m:%d \n", x, y, m);

    x %= m;
    long long res = 1;
    while (y > 0) {
        
        // y, are you odd?
        if (y & 1) {
            // y: I'm odd!
            res = res * x % m;
        }
        x = x * x % m;
        y >>= 1;
    }

    return res;
}


//
// read Uva1230 input
//
int Uva1230 (void)
{
    FILE *in_file = fopen(filename, "r");
    if (!in_file) {
        perror("fopen");
        return -1;
    }

    int file_contents = 0;
    int num_datasets = 0;
    const int LEN_DATASET = 3;
    int counter = 0;
    int x, y, m = 0;
    long long res = 0;

    // First read how many datasets to parse
    if (fscanf(in_file, "%d" , &file_contents) != EOF) {
        num_datasets = file_contents;
    }
    
    if (!num_datasets) {
        return 0;
    }

    while (num_datasets && fscanf(in_file, "%d" , &file_contents) != EOF) {
        switch (counter % LEN_DATASET)
        {
        case 0:
            x = file_contents;
            break;
        case 1:
            y = file_contents;
            break;            
        case 2:
            m = file_contents;
            res = xToYModM (x, y, m);
            printf("%d\n", res);
            num_datasets--;
            break;        
        default:
            printf("-----Unexpected case-----\n");
            break;
        }
        if (!x) {
            //printf("reach the end of the input...\n");
            break;
        }
        counter++;
    }
    
    //printf("-----End of Read input-----\n");

    fclose(in_file);
    return 0;
}


//
// main function
//
int main (int argc, char *argv[])
{
    // Read input
    // then compute x^y (mod m)
    printf("Test: read input from file.\n");
    Uva1230 ();


    return 0;
}