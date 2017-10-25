/*
 * Singly Circular Linked List (Sentinel Pointing to last node).
 */
#include <stdio.h>
#include <stdlib.h>

struct node // Constructing a structure as node.
{
    int data;
    struct node *next;
};
typedef struct node Node; // Using "struct node" as "Node".

Node *s; // Sentinel.

//Creates a node on the heap and returns address of it.
Node* getnode()
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    return new_node;
}

void display()
{
    Node *temp = s;
    printf("\nStatus of the list:\n");
    if(temp==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        temp = temp->next;
        do
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }while (temp != s->next);

        printf("first\n");
    }
}

void insert_at_beginning()
{

    Node *new_node = getnode();
    printf("\nEnter data: ");
    scanf("%d", &new_node->data);
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
    }

    printf("Successfully inserted %d at beginning\n", new_node->data);
}

void insert_at_end() {
    Node *new_node = getnode();
    printf("\nEnter data: ");
    scanf("%d", &new_node->data);
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

    printf("Successfully inserted %d at end\n", new_node->data);
}

void delete_at_beginning()
{
    Node *temp = s;

    if(temp == NULL)
    {
        printf("\nCannot delete as the list is empty.\n");
        return;
    }

    if( s->next == s ){
        temp = s;
        s = NULL;
    } else {
        temp = s->next;
        s->next = s->next->next;
    }
    printf("Deleted successfully %d from beginning\n", temp->data);
    free(temp);
}

void delete_at_end()
{
    Node *temp = s, *temp2 = NULL;

    if(temp == NULL)
    {
        printf("\nCannot delete as the list is empty.\n");
        return;
    }

    if( s->next == s ){
        temp2 = s;
        s = NULL;
    } else {

        while (temp->next != s){
            temp = temp->next;
        }
        temp2 = s;
        temp->next = s->next;
        s = temp;
    }
    printf("Deleted successfully %d from end\n", temp2->data);
    free(temp2);
}

void search(){
    int key;
    Node *temp = s;

    printf("Enter the key to be searched:");
    scanf("%d", &key);

    do
    {
        if(key == temp->data){
            printf("Found the element: %d\n", key);
            return;
        }
        temp = temp->next;
    }while(temp != s);

    printf("Element %d not found in the list\n", key);
}

void main()
{
    int f = 1, choice;

    while (f){
        printf("\nSingly Circular Linked List :\n");
        printf("---------------------------------\n");
        printf("1. Insert a node at beginning\n");
        printf("2. Insert a node at end\n");
        printf("3. Delete a node at beginning\n");
        printf("4. Delete a node at end\n");
        printf("5. Display list\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                insert_at_beginning();
                break;
            }
            case 2:
            {
                insert_at_end();
                break;
            }
            case 3:
            {
                delete_at_beginning();
                break;
            }
            case 4:
            {
                delete_at_end();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:
            {
                search();
                break;
            }
            case 7:
            {
                f = 0;
                break;
            }
            default:
            {
                printf("Invalid Choice\n");
            }
        }
    }
}