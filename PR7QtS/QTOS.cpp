#include <stdio.h>
#define size 5   

typedef struct {
    int arr[size];
    int top;
} Stack;

typedef struct {
    int arr[size];
    int front, rear;
} Queue;

void push(Stack *s, int value) {
    if (s->top == size - 1) {
        printf("Stack Overflow!\n");
    } else {
        s->arr[++(s->top)] = value;
        printf("%d pushed into Stack\n", value);
    }
}

void displayStack(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

// Queue functions
void enqueue(Queue *q, int value) {
    if (q->rear == size - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (q->front == -1) q->front = 0; 
        q->arr[++(q->rear)] = value;
        printf("%d enqueued into Queue\n", value);
    }
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        return -1; 
    } else {
        return q->arr[(q->front)++];
    }
}

void displayQueue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements (front to rear): ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void moveQueueToStack(Queue *q, Stack *s) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty, nothing to move!\n");
        return;
    }
    while (q->front <= q->rear) {
        int val = dequeue(q);
        if (val != -1) {
            push(s, val);
        }
    }
    printf("All elements moved from Queue to Stack.\n");
}

int main() {
    Stack s;
    Queue q;
    s.top = -1;
    q.front = -1; q.rear = -1;

    int choice, value;

    do {
        printf("\n------ MENU ------\n");
        printf("1. Enqueue (into Queue)\n");
        printf("2. Display Queue\n");
        printf("3. Display Stack\n");
        printf("4. Move Queue -> Stack\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                displayQueue(&q);
                break;

            case 3:
                displayStack(&s);
                break;

            case 4:
                moveQueueToStack(&q, &s);
                break;

            case 5:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

