#include <stdio.h>

#define MAXSIZE 10

int stack[MAXSIZE], top = -1;

int isEmpty();
int isFull();
void Push(int element);
int Pop();
int Top();
void Display();

void main(void)
{
    int choice, element, temp, flag = 1;

    while(flag)
    {
        printf("\n\nStack Operations");
        printf("\n----------------");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Top");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\n----------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {

                if(!isFull())
                {
                    printf("\nEnter element to be pushed: ");
                    scanf("%d", &element);
                    Push(element);
                    printf("\nPushed Element: %d", element);
                }
                else
                {
                    printf("\nStack Overflow..");
                }

                break;
            }
            case 2:
            {
                if(!isEmpty())
                {
                    temp = Pop();
                    printf("Popped Element: %d ", temp);
                }
                else
                {
                    printf("\nStack Underflow..");
                }

                break;
            }
            case 3:
            {
                if(!isEmpty())
                {
                    temp = Top();
                    printf("\nTop Element: %d", temp);
                }
                else
                {
                    printf("\nStack is Empty");
                }

                break;
            }
            case 4:
            {
                Display();

                break;
            }
            case 5:
            {
                flag = 0;
                break;
            }
            default:
            {
                printf("\nInvalid Choice");
            }
        }
    }
}

int isEmpty()
{
    if(top == -1) return 1;
    return 0;
}

int isFull()
{
    if(top == (MAXSIZE-1)) return 1;
    return 0;
}

void Push(int element)
{
    stack[++top] = element;
}

int Pop()
{
    return stack[top--];
}

int Top()
{
    return stack[top];
}

void Display()
{
    int i;

    printf("\nStatus of the stack: ");

    if(isEmpty())
    {
        printf("\nStack is Empty");
        return;
    }

    for(i = top; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
}