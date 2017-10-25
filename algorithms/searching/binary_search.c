#include <stdio.h>

int array[15], n;

void read_array() {
    int i;
    printf("\nHow many numbers you want to enter: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);
}

void binary_search(int key)
{
    int start = 0, end = n-1, mid;

    while(start <= end)
    {
        mid = (start + end)/2;

        if(key == array[mid])
        {
            printf("Element %d Found", key);
            return;
        }
        else if(key < array[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
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
    binary_search(key);

    return 0;
}
