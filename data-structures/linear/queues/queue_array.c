#include <stdio.h>

#define MAXSIZE 10

int queue[MAXSIZE], front = -1, rear = -1;

void Enqueue(int element);
int Dequeue();
int Front();
void Display();
int is_full();
int is_empty();

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
                if(!is_full())
                {
                    printf("\nEnter the element to be enqueued: ");
                    scanf("%d", &element);
                    Enqueue(element);
                    printf("\nEnqueued element: %d", element);
                }else{
                    printf("\nError: Queue is full");
                }
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

int is_full()
{
    if(rear == (MAXSIZE - 1)) return 1;
    return 0;
}

int is_empty(){
    if(front == -1 && rear == -1) return 1;
    return 0;
}

void Enqueue(int element)
{
    if(is_empty())
    {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
}

int Dequeue()
{
    int temp;
    if(front == rear){
        temp = queue[front];
        front = rear = -1;
    } else {
        temp = queue[front];
        front++;
    }

    return temp;
}

int Front()
{
    return queue[front];
}

void Display()
{
    int i;
    printf("\nStatus of the queue:\n");

    if(is_empty())
    {
        printf("\nQueue is Empty");
        return;
    }

    for (i = front; i <= rear; ++i) {
        printf("%d\t", queue[i]);
    }
}