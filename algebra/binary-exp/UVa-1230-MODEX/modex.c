#include <stdio.h>

long long xToYModM(int x, int y, int m)
{

    x %= m;
    long long res = 1;
    while (y > 0) {
        
        if (y & 1) {
            res = res * x % m;
        }
        x = x * x % m;
        y >>= 1;
    }

    return res;
}


int Uva1230 (void)
{
    int file_contents = 0;
    int num_datasets = 0;
    const int LEN_DATASET = 3;
    int counter = 0;
    int x, y, m = 0;
    long long res = 0;

    if (fscanf(stdin, "%d" , &file_contents) != EOF) {
        num_datasets = file_contents;
    }
    
    if (!num_datasets) {
        return 0;
    }

    while (num_datasets && fscanf(stdin, "%d" , &file_contents) != EOF) {
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
            break;
        }
        counter++;
    }
    

    return 0;
}

int main (int argc, char *argv[])
{

    Uva1230 ();

    return 0;
}