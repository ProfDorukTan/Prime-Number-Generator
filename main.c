//
// Created by Doruk Tan Atila on 12/02/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <errno.h>

int checkifprime(const int allnums[], int currentnum);
int save_external_read(int no_of_lines, int *pointer);
int no_of_lines(int *pointer);
int PrimeAlgorithm(int no_of_array_elements1, int allnums_1[]);
int no_of_prime = 1;
int no_of_prime_at_the_beginning = 0;
int count_a = 0, count_c = 1;
int doruk = 0;
char fileName[30];

int main() {
    int choice;
    int no_of_array_elements1;
    printf("\nTotal number of prime numbers to generate: ");
    scanf("%d", &no_of_array_elements1);
    if(no_of_array_elements1 <= 2 || no_of_array_elements1 > INT_MAX){
        printf("Number entered is invalid");
        exit(33);

    };
    int *allnums_1;
    allnums_1 = calloc(no_of_array_elements1, sizeof(int));
    printf("Read external data(1-yes)(0-no): (will always read from Prime Numbers.txt)");
    printf("\nCode will not execute if the number of primes extracted is greater than the number requested:\n");
    scanf("%d", &choice);
    printf("Do you want to save all prime numbers in a text file (!The file will be overwritten if exists!) (1-yes:)(0-no):\n");
    scanf("%d", &doruk);
    if (choice == 1) {
        no_of_prime = no_of_lines(allnums_1);
        count_a = (count_a + no_of_prime - 1);
        //printf("\n%d", no_of_prime);
        //for (int i = 0; i < 25; ++i) {
        //printf("\nArray element (allnums) %d = %d",i, allnums_1[i]);
        //}
        //printf("\npointer adress: %p", allnums_1);
        //printf("\nsize of int %d bytes", sizeof (int));
    }
    PrimeAlgorithm(no_of_array_elements1, allnums_1);
    return 0;
}

int PrimeAlgorithm(int no_of_array_elements1, int allnums_1[]){
    allnums_1[0] = 2;
    int currentnum;
    printf("\nFirst prime: 2\n");
    clock_t begin = clock();
    while (1) {
        for (int i = 0; i < no_of_array_elements1; ++i) {
            currentnum = allnums_1[no_of_prime_at_the_beginning] + count_c;
            //printf("Current number: %d\n", currentnum);
            if (no_of_prime == no_of_array_elements1) {
                clock_t end = clock();
                double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
                printf("\nNo of primes: %d", no_of_prime);
                printf("\nExecution time: %f", time_spent);
                if(doruk == 1) {
                    printf("\nName of the text file you want to create: ");
                    scanf("%s", fileName);
                    FILE *Pprime_numbers = fopen(fileName, "w");
                    for (int j = 0; j < no_of_array_elements1; ++j) {
                        fprintf(Pprime_numbers, "%d\n", allnums_1[j]);
                    }
                    fclose(Pprime_numbers);
                }
                return 0;
            }
            if (checkifprime(allnums_1, currentnum) == 1) {
                allnums_1[(no_of_prime-1)] = currentnum;
            }
            count_c++;
        }
    }
}

int checkifprime(const int allnums[], int currentnum) {
    int greatest_check = sqrt(currentnum) + 1;
    //printf("\nGreatest check for %d is: %d", currentnum, greatest_check);
    int remainder;
    for (int count_b = 0; greatest_check > allnums[count_b]; count_b++) {
        remainder = currentnum % allnums[count_b];
        if (remainder == 0) {
            //printf("\n%d is divisible by %d\n",currentnum, allnums[count_b]);
            return 0;
        }
    }
    printf("%d, ", currentnum);
    no_of_prime++;
    //printf("no: %d\n",no_of_prime);
    return 1;
}

int no_of_lines(int *pointer) {
    FILE *Pprime_numbers = fopen("Prime Numbers.txt", "r");
    int ch, number_of_lines = 1;
    do {
        ch = fgetc(Pprime_numbers);
        if (ch == '\n')
            number_of_lines++;
    } while (ch != EOF);
    {
        if (ch != '\n' && number_of_lines != 0)
            number_of_lines++;
    }
    fclose(Pprime_numbers);
    //printf("Number of Lines read: %d", (number_of_lines - 1));
    return (save_external_read((number_of_lines-1), pointer));
}

int save_external_read(int no_of_lines, int *pointer){
    printf("Number of Primes extracted from external file: %d", (no_of_lines - 1));
    int *array;
    int i;
    int count = 0;
    array = calloc(no_of_lines, sizeof(int));
    FILE *Pprime_numbers = fopen("Prime Numbers.txt", "r");
    for (i = 0; i < (no_of_lines - 1); i++) {
        fscanf(Pprime_numbers, "%d", &array[i]);
        //printf("\n%d", array[i]);
    }
    count_c = (array[i-1] - 1);
    //printf("\n c: %d", count_c);
    for (int j = 0; j < (no_of_lines - 1); j++) {
        *pointer = array[j];
        pointer = (pointer+1);
    }
    fclose(Pprime_numbers);
    printf("\nAll Prime Numbers are restored\n");


    for (int k = 0; k < 25; ++k) {
        //printf("\nArray element %d = %d",k, array[k]);
    }
    return i;

}