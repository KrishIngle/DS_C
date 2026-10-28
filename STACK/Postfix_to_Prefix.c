// Postfix to Prefix in C using stack

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

void postfix_to_prefix(char postfix[]) {
    char temp[2]; 
    char prefix[30];

    for (int i = 0; postfix[i] != '\0'; i++) {
        // Check if character is an operator
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            char op1[30], op2[30];
            
            // Pop top two operands
            strcpy(op2, pop()); // First popped is right operand
            strcpy(op1, pop()); // Second popped is left operand

            // Prefix format: Operator + Operand1 + Operand2
            temp[0] = postfix[i];
            temp[1] = '\0';

            strcpy(prefix, temp);   // Start with operator
            strcat(prefix, op1);    // Append first operand
            strcat(prefix, op2);    // Append second operand

            push(prefix);
        } 
        else {
            // Push operand to stack as string
            char str[2];
            str[0] = postfix[i];
            str[1] = '\0';
            push(str);
        }
    }

    strcpy(prefix, pop());
    printf("%s", prefix);
}

int main() {
    char postfix[20];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    printf("Prefix Expression: ");
    postfix_to_prefix(postfix);
    printf("\n");

    return 0;
}