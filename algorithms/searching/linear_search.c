#include <stdio.h>

int array[15], n;

void read_array() {
    int i;
    printf("\nHow many numbers you want to enter: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void linear_search(int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(key == array[i])
        {
            printf("Element %d Found", key);
            return;
        }
    }
    printf("\nElement %d Not Found", key);
}

int main()
{
    int key;
    read_array();

    printf("\nEnter number to be searched: ");
    scanf("%d", &key);
    linear_search(key);

    return 0;
}

