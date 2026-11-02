// Postfix Esxpression Evaluation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stack[20];
int top = -1;

void push(int ele) {
    stack[++top] = ele;
}

int pop() {
    return stack[top--];
}

void postfix_eval(char postfix[20]) {
    for (int i=0; postfix[i]!='\0'; i++) {
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            int op2 = pop();
            int op1 = pop();
            switch(postfix[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push((int)pow(op1, op2));
                    break;
            }
        } else {
            push(postfix[i] - '0');
        }
    }
}

int main() {
    char postfix[20];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    postfix_eval(postfix);
    printf("Result: %d\n", pop());
    return 0;
}