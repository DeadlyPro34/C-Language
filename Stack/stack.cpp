#include <stdio.h>   // For input/output functions

#define size 5        // Maximum size of the stack

// Global variables
int stack[size], top = -1; // 'top' points to last inserted element

// PUSH operation: Adds element to the stack
void push(int v)
{
    if (top == size - 1) // Check for overflow
        printf("Overflow\n");
    else
        stack[++top] = v; // Increment top and insert value
}

// POP operation: Removes top element
void pop()
{
    if (top == -1) // Check for underflow
        printf("Underflow\n");
    else
    {
        printf("The popped element is %d\n", stack[top]);
        top--; // Decrease top to remove element
    }
}

// PEEP operation: Views top element without removing it
void peep()
{
    if (top == -1)
        printf("Stack empty\n");
    else
        printf("The element at top is %d\n", stack[top]);
}

// CHANGE operation: Replaces value at given position from top
void change(int pos, int v)
{
    // Validate position (pos=1 means top element)
    if (pos <= 0 || pos > top + 1)
        printf("Invalid position\n");
    else
    {
        stack[top - pos + 1] = v; // Calculate actual index
        printf("Value %d is changed at position %d\n", v, pos);
    }
}

// DISPLAY operation: Shows all stack elements from top to bottom
void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

// Main function: Menu-driven program
int main()
{
    int choice, v, pos;

    do
    {
        printf("\n1.PUSH  2.POP  3.PEEP  4.CHANGE  5.DISPLAY  6.EXIT\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // PUSH
            printf("Enter value to PUSH: ");
            scanf("%d", &v);
            push(v);
            break;

        case 2: // POP
            pop();
            break;

        case 3: // PEEP
            peep();
            break;

        case 4: // CHANGE
            printf("Enter the position to change: ");
            scanf("%d", &pos);
            printf("Enter new value: ");
            scanf("%d", &v);
            change(pos, v);
            break;

        case 5: // DISPLAY
            display();
            break;

        case 6: // EXIT
            printf("EXIT\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }
    while (choice != 6); // Loop until EXIT is selected
}
