#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Insert at the front
void insertFront(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Insert in ascending order
void insertAsc(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;

    if (!head || value < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next && temp->next->data < value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete the first node
void deleteFirst() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete node before a given position
void deleteBefore(int pos) {
    if (pos <= 1 || !head || !head->next) {
        printf("Invalid position or insufficient nodes\n");
        return;
    }
    if (pos == 2) {
        deleteFirst();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 2 && temp->next && temp->next->next; i++)
        temp = temp->next;

    if (!temp->next || !temp->next->next) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// Delete node after a given position
void deleteAfter(int pos) {
    struct Node *temp = head;
    for (int i = 1; i < pos && temp; i++)
        temp = temp->next;

    if (!temp || !temp->next) {
        printf("No node exists after position %d\n", pos);
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// Display the list
void display() {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Ascending Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Node Before Position\n");
        printf("6. Delete Node After Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAsc(value);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteBefore(pos);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAfter(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

