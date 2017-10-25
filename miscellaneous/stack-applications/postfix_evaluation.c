#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char postfix[30], t[30];
    int stack[10], top = -1, len, i, j, op1, op2, n;

    printf("\nenter the postfix expression:");
    gets(postfix);
    len = strlen(postfix);
    postfix[len] = ')';

    for (i = 0; postfix[i] != ')'; i++)
    {
        j=0;
        if(postfix[i]==' ')
            continue;
        if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
        {
            op2=stack[top--];
            op1=stack[top--];
            switch(postfix[i])
            {
                case '+':stack[++top]=op1+op2;
                    break;
                case '-':stack[++top]=op1-op2;
                    break;
                case '*':stack[++top]=op1*op2;
                    break;
                case '/':stack[++top]=op1/op2;
                    break;
                case '^':stack[++top]=pow(op1,op2);
                    break;
            }
        }
        else
        {
            while (postfix[i] != ' ') {
                t[j++] = postfix[i++];
            }
            t[j] = '\0';
            n = atoi(t);
            stack[++top] = n;
        }
    }
    printf("\nresult=%d",stack[top]);
    return 0;
}
