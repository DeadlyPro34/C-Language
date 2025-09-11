#include <stdio.h>
#define size 5   

typedef struct {
    int arr[size];
    int top;
    int id;   
} Stack;

void push(Stack *s, int value) {
    if (s->top == size - 1) {
        printf("Stack%d Overflow!\n", s->id);
    } else {
        s->arr[++(s->top)] = value;
        printf("%d pushed into Stack%d\n", value, s->id);
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n", s->id);
        return -1;
    } else {
        int value = s->arr[(s->top)--];
        printf("%d popped from Stack\n", value, s->id);
        return value;
    }
}

void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack%d is empty\n", s->id);
    } else {
        printf("Stack%d elements (top to bottom): ", s->id);
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

void emptyXtoY(Stack *x, Stack *y) {
    if (x->top == -1) {
        printf("StackX is already empty!\n");
        return;
    }
    while (x->top != -1) {
        int val = pop(x);
        if (y->top == size - 1) {
            printf("StackY Overflow while transferring!\n");
            break;
        }
        push(y, val);
    }
    printf("All elements from StackX moved onto StackY.\n");
}

int main() {
    Stack x, y;
    x.top = -1; x.id = 1;   
    y.top = -1; y.id = 2;  

    int choice, stackChoice, value;

    do {
        printf("\n------ MENU ------\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Empty X to Y\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                    push(&x, value);
                break;

            case 2:
                pop(&x);
                break;

            case 3:
                printf("Display stack 1=X / 2=Y ");
                scanf("%d", &stackChoice);
                if (stackChoice == 1)
                    display(&x);
                else if (stackChoice == 2)
                    display(&y);
                else
                    printf("Invalid stack choice!\n");
                break;

            case 4:
                emptyXtoY(&x, &y);
                break;

            case 5:
                printf("Exit\n");
                break;
            		default:
                	printf("Invalid choice\n");
        }
    } 
	while (choice != 5);
    return 0;
}

