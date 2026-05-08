//convert infix expression to postfix using a stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char c;
    while ((c = infix[i++]) != '\0') {
        // If operand, add to output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '(' is found
        else if (c == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If operator
        else if (isOperator(c)) {
            // Handle right-associativity for '^'
            if (c == '^') {
                while (top >= 0 && precedence(peek()) > precedence(c)) {
                    postfix[j++] = pop();
                }
            } else {
                while (top >= 0 && precedence(peek()) >= precedence(c)) {
                    postfix[j++] = pop();
                }
            }
            push(c);
        }
    }        
    // Pop remaining operators
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix;
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

OUTPUT
Enter an infix expression: (A+B)*(C-D)
Postfix expression: AB+CD-*
