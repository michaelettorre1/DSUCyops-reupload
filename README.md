# Inventory System
**Due: 12p 30 March 2020 / Autograde will be combined with reviewed grade**

## Points: 20

## Submission
`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to dsunix or your local machine using the link provided on the GitHub repo page

Use the included files as your template to start the program maintaining the filenames given.

## Description
This assignment will make use of `structs` and reading from a file.  You would be creating a sort of database-like system that will be keeping track of the inventory of a store.  Each item in the inventory should be its own `struct` item, and you should use a `struct` array to store the entirety of the inventory.


The goal of this assignment is to have you read in this information from a file and save it into an array of structures which represent the inventory items.

**A max of 500 items will be read in from the file.**

Once the data is read into your program, your program must then perform the following tasks and print them off to the screen

1. Calculate the total value of your inventory (this means $)
	* The value is the total of all items
	* The value should be a decimal value as shown in the examples
2. Find total number of items in inventory
3. Tell me which items need to be ordered (one per line)
	* _An item needs to be ordered if the quantity of that item is less than 10_


### Input file format
The input file will have the following format:
```
1st line: signifies the number of inventory items
2nd line: states the name of the item (50 character max length)
3rd line: indicates the quantity of that item currently available
4th line: indicates the price of the item
5th line: is the id of the item
6th line: is the date of the last order

Lines 2-6 will repeat for as many items specified in line 1
```

Example of input file format:
```
1
coke
15
1.59
12657435
12/12/2014
```


```
3
coke
15
1.59
12657435
12/12/2014
pepsi
9
1.49
12547543
12/10/2014
sprite
7
1.59
12657437
12/09/2014
```

You should create other input files of your own using the appropriate format to test your program with larger data sizes.


### Requirements
* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Your program must read input from a file in the proper format, NOT stdin
* Product IDs should always be presented as 0 padded and 8 characters wide
* Your program should accept the filename from the command-line as shown in the example below
	* You should use appropriate error checking
	* Autograding doesn't currently support non-zero exit values; use `exit(0)` whenever exiting this program due to an error


#### Required Functions
```c
int readFile(char filename[], struct inventory_item inventory_list[]);
int getTotalItems(struct inventory_item inventory_list[], int count);
double getTotalVal(struct inventory_item inventory_list[], int count);
```

#### Optional Functions
Additional functions may be used for debugging or while you are developing your program, a useful example is a function to print off some of the properties of one item.
```c
void printItem(struct inventory_item item)
{
	// Print off properties of one individual item
}
```


### Example Output
```
./a.out input-small.txt
Total inventory value: $48.39
Total inventory quantity: 31
Items that need to be ordered:
    12547543: pepsi
    12657437: sprite
```

```
./a.out
Error: file not specified
Format: ./a.out <input-file>
```

```
./a.out not_here.txt
Error: unable to open file not_here.txt
```
