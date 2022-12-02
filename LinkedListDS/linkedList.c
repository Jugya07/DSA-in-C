#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
} *start = NULL;

void insert(int index) {
	printf("\nEnter data to be inserted: ");
	int d; scanf("%d", &d);
	struct Node *p = (struct Node *)malloc(sizeof(struct Node));
	p->data = d;

	// always insert at beginning if head is null
	if (start == NULL) {
		p->next = NULL;
		start = p;
		return;
	}

	// insertion at the beginning
	if (index == 1) { 
		p->next = start;
		start = p;
	}

	// insertion at the end
	else if (index == 0) { 
		struct Node *ptr = start;
		while (ptr->next != NULL)
			ptr = ptr->next;
		p->next = NULL;
		ptr->next = p;
	}

	// insertion at any position
	else { 
		struct Node *ptr = start, *temp;
		while (index-- > 2 && ptr->next != NULL)
			ptr = ptr->next;
		temp = ptr->next;
		ptr->next = p;
		p->next = temp;
	}
}

void delete(int index) {
	// check if list is empty before deletion
	if (start == NULL) {
		printf("Error! List is empty");
		return;
	}
	struct Node *p = start;

	// deleting at beginning
	if (index == 1) {
		start = start->next;
		free(p);
	}

	// deleting at end
	else if (index == 0) {
		while (p->next->next != NULL)
			p = p->next;
		free(p->next);
		p->next = NULL;
	}

	// deleting at any position
	else {
		while (index-- > 2 && p->next->next != NULL)
			p = p->next;
		struct Node *temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}

void search(int key) {
	struct Node *p = start;
	int i = 1;
	while (p != NULL){
		if (p->data == key){
			printf("\nElement found at position %d", i);
			return;
		}
		i++;
		p = p->next;
	}
	printf("\nElement Not Found");
}

void display() {
	struct Node *ptr = start;
	if(start==NULL){
		printf("\nList is Empty");
		return;
	}
	while (ptr != NULL){
		printf("%d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main() {
	while(1) {
		printf("\nEnter: \n0 for Insertion\n1 for Deletion\n2 for Searching\n3 for Displaying\nAnything else to exit: ");
		int n, choice;
		scanf("%d", &n);
		switch (n){
		case 0:
			printf("\nEnter:\n1 to Insert at the Beginning");
			printf("\n0 to Insert in the end");
			printf("\nor Enter specific position to Insert: ");
			scanf("%d", &choice);
			insert(choice);
			break;
		case 1:
			printf("\nEnter:\n1 to Delete at the Beginning");
			printf("\n0 to Delete at the end");
			printf("\nor Enter specific position to Delete: ");
			scanf("%d", &choice);
			delete (choice);
			break;
		case 2:
			printf("\nEnter key to be searched: ");
			scanf("%d", &choice);
			search(choice);
			break;
		case 3:
			display();
			break;
		default:
			printf("\nExiting..");
			return 0;
		}
	}
	return 0;
}