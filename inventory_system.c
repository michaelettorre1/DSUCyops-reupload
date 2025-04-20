#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 500
#define NAME_LENGTH 50
#define DATE_LENGTH 12
struct inventory_item
{
 	char name[NAME_LENGTH];
	int quantity;
	double price;
	int id;
	char order_date[DATE_LENGTH];
};

int readFile(char filename[], struct inventory_item inventory_list[]);
int getTotalItems(struct inventory_item inventory_list[], int count);
double getTotalVal(struct inventory_item inventory_list[], int count);

void printItem(struct inventory_item item)
{
	printf("Name: %s, Quantity: %d, Price: %lf, ID: %8d, Date: %s\n",
		item.name, item.quantity, item.price, item.id, item.order_date);
}

int main(int argc, char *argv[])
{
	struct inventory_item list[MAX_ITEMS];
	if (argc != 2) {
		printf("Error: file not specified\nFormat: %s <input-file>\n",argv[0]);
		exit(0);
	}

	int count = readFile(argv[1], list);
	if (count == 0) {
		printf("Error: unable to open file %s\n", argv[1]);
		exit(0);
	}

	printf("Total inventory value: $%.2lf\n", getTotalVal(list, count));
	printf("Total inventory quantity: %d\n", getTotalItems(list, count));
	printf("Items that need to be ordered:\n");
	for (int i = 0; i < count; i++) {
		if (list[i].quantity < 10) {
			printf("\t%8d: %s\n", list[i].id, list[i].name);
		}
	}

	return 0;
}

int readFile(char filename[], struct inventory_item inventory_list[])
{
	FILE *infile = fopen(filename, "r");
	if (infile == NULL) {
		return 0;
	}
	int number;
	fscanf(infile, "%d\n", &number);

	for (int i = 0; i < number; i++) {
		fscanf(infile, "%s\n", inventory_list[i].name);
		fscanf(infile, "%d\n", &inventory_list[i].quantity);
		fscanf(infile, "%lf\n",&inventory_list[i].price);
		fscanf(infile, "%d\n", &inventory_list[i].id);
		fscanf(infile, "%s\n", inventory_list[i].order_date);
	}

	return number;
}

int getTotalItems(struct inventory_item inventory_list[], int count) 
{
	int total = 0;
	for (int i = 0; i < count; i++) {
		total += inventory_list[i].quantity;
	}
	return total;

}

double getTotalVal(struct inventory_item inventory_list[], int count) 
{
	double value = 0;
	for (int i = 0; i < count; i ++) {
		value += inventory_list[i].price * inventory_list[i].quantity;
	}
	return value;
}
