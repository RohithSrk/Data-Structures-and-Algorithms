#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

Node *s = NULL;

Node* getnode()
{
    return (Node*) malloc(sizeof(Node));
}

int is_empty()
{
    if(s == NULL) return 1;
    return 0;
}

void Enqueue(int element)
{
    Node *new_node = getnode();

    new_node->data = element;
    new_node->next = NULL;

    if(s == NULL)
    {
        s = new_node;
        new_node->next = s;
    }
    else
    {
        new_node->next = s->next;
        s->next = new_node;
        s = new_node;
    }

}

int Dequeue()
{
    Node *temp;
    int element;

    if(s->next == s){
        temp = s;
        s = NULL;
    } else {
        temp = s->next;
        s->next = temp->next;
    }
    element = temp->data;
    free(temp);
    return element;
}

void Display()
{
    Node *temp;
    printf("\nStatus of the queue:\n");
    if(s == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        temp = s->next;
        do
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }while (temp != s->next);
    }
}

int Front()
{
    return s->next->data;
}

void main()
{
    int choice, element, flag = 1, temp;

    while (flag)
    {
        printf("\n\nQueue Operations");
        printf("\n----------------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Front");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\n----------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1 :
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &element);
                Enqueue(element);
                printf("\nEnqueued element: %d", element);
                break;
            case 2 :
                if(!is_empty())
                {
                    temp = Dequeue();
                    printf("\nDequeued element: %d", temp);
                } else {
                    printf("\nError: Queue is empty");
                }
                break;
            case 3:
                if(!is_empty()){
                    temp = Front();
                    printf("\nFront element: %d", temp);
                }
                break;
            case 4:
                Display();
                break;
            case 5:
                flag = 0;
                break;
            default:
                printf("\nInvalid Choice");

        }
    }
}