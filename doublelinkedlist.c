#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBeginning(int value) {
    struct Node *newNode = createNode(value);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at given position (1-based index)
void insertPosition(int value, int pos) {
    struct Node *newNode;
    struct Node *temp;
    int i;
    if (pos == 1) {
	insertBeginning(value);
	return;
    }

    newNode = createNode(value);
    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
	temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning() {
    struct Node *temp;
    if (head == NULL) {
	printf("List is empty.\n");
	return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
	head->prev = NULL;

    free(temp);
    printf("\n node deleted at first");
}

// Delete from end
void deleteEnd() {
    struct Node *temp;
    if (head == NULL) {
	printf("List is empty.\n");
	return;
    }

    temp = head;

    if (temp->next == NULL) {
	head = NULL;
	free(temp);
	printf("\n node deleted at last:");
	return;
    }

    while (temp->next != NULL)
	temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    printf("\n node deleted at end");
}

// Delete from position
void deletePosition(int pos) {
    struct Node * temp;
    int i;
    if (head == NULL) {
	printf("List is empty.\n");
	return;
    }

    if (pos == 1) {
	deleteBeginning();
	return;
    }

      temp = head;

    for (i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
    printf("\n node deleted at pos %d",pos);
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display forward
void displayForward() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display backward
void displayBackward() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value, pos;

    while(1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
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
                deletePosition(pos);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                exit(0);
            return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    
}
