// Postfix to Infix in C using Stack

#include <stdio.h>
#include <string.h>

char stack[20][30]; int top = -1;

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

void push(char op[20]) {
    top++;
    strcpy(stack[top], op);
}

char* pop() {
    char *temp;
    strcpy(temp, stack[top]);
    top--;
    return temp;
}

void postfix_to_infix(char postfix[]) {
    char temp[2]; char stack[20][30]; char infix[20];
    for(int i=0; postfix[i]!='\0'; i++) {
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            char op1[30], op2[30];
            strcpy(op1, pop());
            strcpy(op2, pop());

            infix[0] = '(';
            infix[1] = '\0';

            strcat(infix, op2);

            temp[0] = postfix[i];
            temp[1] = '\0';

            strcat(infix, temp);
            strcat(infix, op1);

            temp[0]=')';
            temp[1]='\0';

            strcat(infix,temp);
            push(infix);
        }
        else {
            char str[2];
            str[0] = postfix[i];
            str[1] = '\0';
            push(str);
        }
    }
    strcpy(infix, pop());
    printf("%s", infix);
}

int main() {
    char postfix[20];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    printf("Postfix Expression: ");
    postfix_to_infix(postfix);
    printf("\n");

    return 0;
}