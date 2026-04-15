#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp;
    if (head == NULL) {
	head = newNode;
	newNode->next = head;
	printf("Inserted %d at end\n", value);
	return;
    }

    temp = head;
    while (temp->next != head)
	temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    printf("Inserted %d at end\n", value);
}

// Insert at position
void insertAtPosition(int value, int pos) {
    struct Node* newNode;
    struct Node* temp;
    int i;
    if (pos == 1) {
	insertAtBeginning(value);
	return;
    }

    newNode = createNode(value);
    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
	temp = temp->next;

    if (temp->next == head && pos > 2) {
	printf("Position out of range\n");
	return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", value, pos);
}

// Delete from beginning
void deleteBeginning() {
    struct Node* temp;
    struct Node* last;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    temp = head;

    if (head->next == head) {
	printf("Deleted %d from beginning\n", head->data);
	free(head);
	head = NULL;
	return;
    }

    last = head;
    while (last->next != head)
	last = last->next;

    printf("Deleted %d from beginning\n", head->data);

    last->next = head->next;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteEnd() {
    struct Node * temp;
    struct Node * prev;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    temp = head;

    if (head->next == head) {
	printf("Deleted %d from end\n", head->data);
	free(head);
	head = NULL;
	return;
    }

    prev = NULL;

    while (temp->next != head) {
	prev = temp;
	temp = temp->next;
    }

    printf("Deleted %d from end\n", temp->data);

    prev->next = head;
    free(temp);
}

// Delete at position
void deleteAtPosition(int pos) {
    struct Node * temp;
    struct Node * prev;
    int i;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    if (pos == 1) {
	deleteBeginning();
	return;
    }

    temp = head;
    prev = NULL;

    for (i = 1; i < pos && temp->next != head; i++) {
	prev = temp;
	temp = temp->next;
    }

    if (temp->next == head && pos > 2) {
	printf("Position out of range\n");
	return;
    }

    printf("Deleted %d from position %d\n", temp->data);
    prev->next = temp->next;
    free(temp);
}

// Search an element
void search(int value) {
    struct Node * temp;
    int pos;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    temp = head;
    pos = 1;

    do {
	if (temp->data == value) {
	    printf("Element %d found at position %d\n", value, pos);
	    return;
	}
	temp = temp->next;
	pos++;
    } while (temp != head);

    printf("Element %d not found\n", value);
}

// Display list
void display() {
    struct Node * temp;
    if (head == NULL) {
	printf("List is empty\n");
	return;
    }

    temp = head;

    printf("Circular Linked List: ");
    do {
	printf("%d -> ", temp->data);
	temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    int choice, value, pos,data;

    while (1) {
	printf("\n--- Circular Linked List Menu ---\n");
	printf("1. Insert at Beginning\n");
	printf("2. Insert at End\n");
	printf("3. Insert at Position\n");
	printf("4. Delete from Beginning\n");
	printf("5. Delete from End\n");
	printf("6. Delete from Position\n");
	printf("7. Search Element\n");
	printf("8. Display List\n");
	printf("9. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter data: ");
		scanf("%d", &data);
		insertAtBeginning(data);
		break;

	    case 2:
		printf("Enter data: ");
		scanf("%d", &data);
		insertAtEnd(data);
		break;

	    case 3:
		printf("Enter data: ");
		scanf("%d", &data);
		printf("Enter position: ");
		scanf("%d", &pos);
		insertAtPosition(data, pos);
		break;

	    case 4:
		deleteBeginning();
		break;

	    case 5:
		deleteEnd();
		break;

	    case 6:
		printf("Enter position: ");
		scanf("%d", &pos);
		deleteAtPosition(pos);
		break;

	    case 7:
		printf("Enter element to search: ");
		scanf("%d", &data);
		search(data);
		break;

	    case 8:
		display();
		break;

	    case 9:
		exit(0);
		return 0;
	    default:
		printf("Invalid choice!\n");
	}
    }
}
