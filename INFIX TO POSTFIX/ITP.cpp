#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

// precedence: higher number ? higher precedence
int precedence(char op) {
    switch(op) {
        case '^': return 3;                 // highest
        case '*':
        case '/':
        case '%': return 2;                 // multiplication/div/mod
        case '+':
        case '-': return 1;                 // addition/subtraction                 // lowest
        default: return 0;
    }
}

// returns 1 if operator is right-associative
int isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isspace(ch)) continue; // ignore spaces

        if (isalnum(ch)) {
            // Operand goes directly to output
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty()) pop(); // remove '('
        }
        else {
            // Operator
            while (!isEmpty() && peek() != '(' &&
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

