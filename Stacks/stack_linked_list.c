#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

Node *top = NULL;

Node* getnode()
{
    return (Node*) malloc(sizeof(Node));
}

int isEmpty();
void Push(int element);
int Pop();
int Top();
void Display();

int isEmpty()
{
    if(top == NULL) return 1;
    return 0;
}

void Push(int element)
{
    Node *new_node = getnode(), *temp;

    new_node->data = element;
    new_node->next = NULL;

    if(top == NULL){
        top = new_node;
    } else {
        temp = top;
        top = new_node;
        new_node->next = temp;
    }
}

int Pop()
{
    Node* temp;
    int element;

    element = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return element;
}

int Top()
{
    return top->data;
}

void Display()
{
    Node *temp = top;
    printf("\nStatus of the stack: ");

    if(isEmpty())
    {
        printf("\nStack is Empty");
        return;
    }

    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

void main(void)
{
    int choice, element, flag = 1, temp;

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
                printf("\nEnter element to be pushed: ");
                scanf("%d", &element);

                Push(element);
                printf("\nPushed Element: %d", element);

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
