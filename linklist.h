#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct node
{
	int val;
	struct node *next;
};

struct node *makeNode(int val);
struct node *insertFront(struct node *head, int val);
struct node *modifyNode(struct node *head, int old, int new);
struct node *deleteNose(struct node *head, int val);
void printList(struct node *head);
int isInList(struct node *head, int val);
int lenList(struct node *head);

#endif
