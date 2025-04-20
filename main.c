#include "linklist.h"

int main()
{
	struct node * head = NULL;
	int i, search=0, replace=0;

	int size;
	printf("How many nodes: ");
	scanf("%d", &size);
	for (i=0; i < size; i++)
	{
		head = insertFront(head, rand() % 1000);
	}
	printList(head);
	printf("Enter a number to search for & change: ");
	scanf("%d", &search);
	if (isInList(head, search))
	{
		printf("&d is in the list!\n", search);
		printf("Enter a number to change %d to: ", search);
		scanf("%d", &replace);
		head = modifyNode(head, search, replace);
		printList(head);
	}
	else
		printf("%d is not in the list!\n", search);

	printf("Enter a number to delete: ");
	scanf("%d", &search);
	head = deleteNode(head, search);
	printList(head);
	return 0;
}
