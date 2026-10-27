// Infix to Prefix in C using Stack

#include <stdio.h>
#include <string.h>

char stack[20]; int top = -1;

int isfull() {
    if (top == 19)
            return 1;
    return 0;
}

int isempty() {
    if (top == -1)
        return 1;
    return 0;
}

void push(char operand) {
    if (isfull())
        printf("Stack is full\n");
    else {
        top++;
        stack[top] = operand;
    }
}

char pop() {
    if (isempty())
        return -1;
    else {
        char element = stack[top];
        top--;
        return element;
    }
}

int ISP(char operator) {
    if (operator == '(')
        return 0;
    else if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return -1;
}

int ICP(char operator) {
    if (operator == '(')
        return 5;
    else if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 4;
    else
        return -1;
}

void infixtoprefix(char infix[]) {
    char prefix[20]; int k = 0;

    for (int i = strlen(infix)-1; i>=0; i--) {
        if (infix[i] == ')')
            push(infix[i]);
        else if (infix[i] == '(') {
            while (stack[top] != ')') {
                prefix[k] = pop();
                k++;
            }
            pop();
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (ICP(stack[top]) >= ISP(infix[i])) {
                prefix[k] = pop();
                k++;
            }
            push(infix[i]);
        } else {
            prefix[k] = infix[i];
            k++;
        }
    }
    
    while (!isempty()) {
        prefix[k] = pop();
        k++;
    }

    for(int i=0; i<k/2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[k-i-1];
        prefix[k-i-1] = temp;
    }
    
    prefix[k] = '\0';
    printf("%s", prefix);
}

int main() {
    char infix[20];

    printf("Enter the infix expression: ");
    scanf("%s", infix);
    printf("Prefix Expression: ");
    infixtoprefix(infix);
    printf("\n");

    return 0;
}