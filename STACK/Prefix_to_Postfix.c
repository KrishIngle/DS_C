// Prefix to Postfix Conversion

#include <stdio.h>
#include <string.h>

char stack[20][30];
int top = -1;

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

void push(char op[30]) {
    if (isfull()) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    strcpy(stack[top], op);
}

char* pop() {
    if (isempty()) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--];
}

void prefix_to_postfix(char prefix[]) {
    char temp[2];
    char postfix[30];

    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        // Check if character is an operator
        if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            char op1[30], op2[30];

            // Pop top two operands
            strcpy(op1, pop()); // First popped is left operand
            strcpy(op2, pop()); // Second popped is right operand

            // Postfix format: (Operand1 Operand2 Operator)
            postfix[0] = '\0';

            strcat(postfix, op1); // Append first operand
            strcat(postfix, op2);   // Append second operand

            temp[0] = prefix[i];
            temp[1] = '\0';

            strcat(postfix, temp); // Append operator

            push(postfix);
        } else {
            char str[2];
            str[0] = prefix[i];
            str[1] = '\0';
            push(str);
        }
    }

    printf("Postfix Expression: %s\n", pop());
}

int main() {
    char prefix[30];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    prefix_to_postfix(prefix);
    return 0;
}