# CSC-150 Review: Arrays & Random Numbers
## Points: 10

## Submission
`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to dsunix or your local machine using the link provided on the GitHub repo page

Use the included files as your template to start the program maintaining the filenames given.

## Description
For this assignment, you will be reviewing some major topics from CSC-150 that you must understand for this course. You will be creating a program that uses arrays, random numbers, searching, and simple math operations.

1. Ask the user how many numbers they would like generated. Your program will then generate that many numbers with a range of 0-1000 into an array of the same size. This means the array should be dynamically allocated, using the number the user entered.
2. Find the smallest and largest numbers in the array.
    * Print out these values and indices of those values in the array.
3. Then, find the sum and average (integer average) of the numbers in the array.
4. Finally, print out the entire array to verify.

## Requirements
* You MUST use functions where appropriate!  Some are given, but you can add more.
    * Examples may be:
        * `findSum()`
        * `findMin()`
        * `findMax()`
* Output **MUST** be formatted **EXACTLY** as below (number alignment, spacing, etc.)
    * Count the spaces, make sure it's correct.
* Make sure you include both 0 **and** 1000 in your random generation
* Use `rand()` for number generation and `srand()` to set the random generator time as a seed value

## Example Output
```
$ ./a.out
Enter an integer: 30
max:    992 pos:      3
min:      2 pos:     24
avg:    445
sum:  13371

 Pos  :   Val
-------------
   0  :   309
   1  :   607
   2  :   387
   3  :   992
   4  :   835
   5  :   376
   6  :    68
   7  :   490
   8  :   179
   9  :   571
  10  :   889
  11  :   888
  12  :   243
  13  :   272
  14  :   749
  15  :   381
  16  :   864
  17  :    99
  18  :   438
  19  :    32
  20  :   628
  21  :   203
  22  :   460
  23  :    92
  24  :     2
  25  :   987
  26  :    79
  27  :   490
  28  :   680
  29  :    81
```
