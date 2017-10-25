#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 25

char stack[MAX];
int top = -1;

int priority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '$':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char in[MAX], post[MAX], ch;
    int i, j = 0, l;

    printf("Enter expression: ");
    gets(in);
    l = strlen(in);

    for (i = 0; i < l; i++) {
        if (isalpha(in[i]) || isdigit(in[i]))
            post[j++] = in[i];
        else {
            if (in[i] == '(')
                push(in[i]);
            else if (in[i] == ')')
                while ((ch = pop()) != '(')
                    post[j++] = ch;
            else {
                while (priority(in[i]) <= priority(stack[top]))
                    post[j++] = pop();
                push(in[i]);
            }
        }
    }

    while (top != -1)
        post[j++] = pop();
    post[j] = '\0';
    printf("postfix expression is: %s", post);

    return 0;
}
