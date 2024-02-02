# Prime Number Generator

This program, created by Doruk Tan Atila on 12/02/2022, is designed to generate prime numbers starting from 2. It offers various functionalities, including reading external data from "Prime Numbers.txt," saving prime numbers to a text file, and calculating prime numbers based on user input.

## Features

- **Prime Number Generation:** The program allows the user to specify the total number of prime numbers to generate.

- **External Data:** Users can choose to read existing prime numbers from "Prime Numbers.txt." The program will not execute if the number of primes extracted is greater than the number requested.

- **Save to Text File:** Users have the option to save all prime numbers in a text file. The file will be overwritten if it already exists.

- **Execution Time:** The program provides information on the execution time, allowing users to assess performance.

## How to Use

1. **Total Number of Primes:**
   - Enter the desired number of prime numbers to generate.

2. **Read External Data:**
   - Enter `1` to read existing prime numbers from "Prime Numbers.txt" or `0` to generate new ones.

3. **Save to Text File:**
   - Enter `1` to save calculated prime numbers in a text file or `0` for the default behavior.

4. **Note:**
   - By commenting and uncommenting specific lines in the source code,

## Algorithm

The algorithm divides the new number "n" by the previously found prime numbers (2, 3, 5, 7, ..., `max`). The `max` number is less than the square root of "n." It is a single-threaded algorithm.
