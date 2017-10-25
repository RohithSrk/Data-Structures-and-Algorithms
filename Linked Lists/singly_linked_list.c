#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

Node *head;

Node* getnode() {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->next = NULL;
    return temp;
}

void insert_at_beginning()
{
    Node *new_node = getnode(), *temp;

    printf("\nEnter data: ");
    scanf("%d", &new_node->data);

    if(head == NULL){
        head = new_node;
    } else {
        temp = head;
        head = new_node;
        new_node->next = temp;
    }
    printf("Successfully inserted %d at beginning\n", new_node->data);
}

void insert_at_end()
{
    Node *new_node = getnode(), *temp = head;

    printf("\nenter data: ");
    scanf("%d", &new_node->data);

    if(head == NULL)
    {
        head = new_node;
    } else {
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new_node;
    }

    printf("Successfully inserted %d at end\n", new_node->data);
}

void delete_at_beginning()
{
    Node* temp = head;

    if (temp == NULL) {
        printf("\nCannot delete as the list is empty.\n");
        return;
    }

    if (temp->next == NULL) {
        head = NULL;
    } else {
        head = head->next;
    }
    printf("Deleted successfully %d from beginning\n", temp->data);
    free(temp);
}

void delete_at_end() {
    Node *temp = head, *temp2;

    if (temp == NULL) {
        printf("Cannot delete as the list is empty.\n");
        return;
    }

    if (temp->next == NULL) {
        head = NULL;
    } else {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp2 = temp;
        temp = temp->next;
        temp2->next = NULL;
    }
    printf("Deleted successfully %d from end\n", temp->data);
    free(temp);
}

void search(){
    int key;
    Node *temp = head;

    printf("Enter the key to be searched:");
    scanf("%d", &key);

    while(temp!=NULL){
        if(key == temp->data){
            printf("Found the element: %d\n", key);
            return;
        }
        temp = temp->next;
    }

    printf("Element %d not found in the list\n", key);
}

void insert_at_nth()
{
    Node *new_node = getnode(), *temp;
    int pos, cpos = 0;

    printf("Enter location: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    } else {

        if( pos == 0 )
        {
            new_node->next = head;
            head = new_node;
        } else {
            temp = head;

            while (cpos < pos - 1 && temp->next != NULL){
                temp = temp->next;
                cpos++;
            }

            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void reverse() {
    Node *current, *prev, *next;

    current = head;
    prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int length(Node *head) {
    if(!head) return 0;
    return 1 + length(head->next);
}

Node *copy(Node *head) {
    Node *head2 = NULL, *temp2 = head, *new_node, *curr = NULL;

    while (temp2 != NULL) {
        new_node = getnode();
        new_node->data = temp2->data;

        if (head2 == NULL) {
            head2 = curr = new_node;
        } else {
            curr->next = new_node;
            curr = curr->next;
        }

        temp2 = temp2->next;
    }

    return head2;
}

void display(Node *head) {
    Node *temp = head;

    if(temp==NULL) {
        printf("List is Empty\n");
        return;
    }
    else
    {
        while(temp != NULL){
            printf("%d->", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int f = 1, choice;
    Node *temp;

    while (f) {
        printf("\nSingly Linked List :\n");
        printf("---------------------------------\n");
        printf("1. Insert a node at beginning\n");
        printf("2. Insert a node at end\n");
        printf("3. Insert a node at nth position\n");
        printf("4. Delete a node at beginning\n");
        printf("5. Delete a node at end\n");
        printf("6. Display list\t");
        printf("7. Reverse list\n");
        printf("8. Print Length\t");
        printf("9. Copy\n");
        printf("10. Search \t");
        printf("11. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert_at_beginning();
                break;
            case 2: insert_at_end();
                break;
            case 3: insert_at_nth();
                break;
            case 4: delete_at_beginning();
                break;
            case 5: delete_at_end();
                break;
            case 6: display(head);
                break;
            case 7:
                reverse();
                printf("After reversing: ");
                display(head);
                break;
            case 8: printf("length of list: %d", length(head));
                break;
            case 9:
                temp = copy(head);
                printf("Copied. Display of copied list: ");
                display(temp);
                break;
            case 10: search();
                break;
            case 11: f = 0;
                break;
            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}
