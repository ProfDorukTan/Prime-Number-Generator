//
// Created by Doruk Tan Atila on 5/3/22.
//
/*
#include "stdio.h"
#include <time.h>
#include <stdlib.h>
#include "unistd.h"
int function();

int main() {
    int prime1 = function();
    usleep(100000);
    int prime2 = function();

    if(prime1 % prime2 == 0 || prime2 % prime1 == 0){
        main();
    }else{
        printf("1st Prime number = %d\n", prime1);
        printf("2nd Prime number = %d\n", prime2);
    }
}

int function(){
    int prime;
    srand(time(NULL));
    int r = rand();
    r = r % 1000;
    FILE *file = fopen("Prime Numbers.txt", "r");
    for (int i = 0; i < (r - 2); i++) {
        fscanf(file, "%d", &prime);
        //printf("\n%d", prime);
    }
    fscanf(file, "%d", &prime);

    fclose(file);
    return prime;
}
*/