# Prime-Number-Generator

The program will generate prime numbers starting from 2.

After program starts, it takes the following inputs from the user:

Total number of prime numbers to generate: 
INPUT NUMBER OF PRIME NUMBERS GENERATED

Read external data(1-yes)(0-no): (will always read from Prime Numbers.txt)
Code will not execute if the number of primes extracted is greater than the number requested: 
INPUT 0 FOR DEFAULT. IF A DATABASE OF PRIME NUMBERS EXIST IN TXT FILE INPUT 1 AND THE PROGRAM WILL READ THOSE VALUES AND START CALCULATING NEW VALUES AFTER THE LAST VALUE.

Do you want to save all prime numbers in a text file (!The file will be overwritten if exists!) (1-yes:)(0-no):
INPUT 0 FOR DEFAULT. INPUT 1 IF YOU WANT TO SAVE CALCULATED NUMBERS IN A TEXT FILE


Note:
1) By commenting and uncommenting some lines intermediate values could be printed.

The algorithm:
Algorithm divides the new number "n" to the previously found prime numbers 2, 3, 5, 7, ..., "max". max number is less than the sqrt(n). It is single threaded.