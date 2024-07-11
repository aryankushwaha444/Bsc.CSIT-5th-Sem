#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void enqueue();
void dequeue();
void show();

int inp_arr[SIZE];
int Rear = -1;
int Front = -1;

int main()
{
    int ch;
    while (1)
    {
        printf("1. Enqueue Operation\n2. Dequeue Operation\n3. Display the Queue\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid Number\n");
            break;
        }
    }

    return 0;
}

void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if (Front == -1)
            Front = 0;
        printf("Element to be inserted in the Queue: ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
        printf("Element %d inserted in the Queue\n", insert_item);
    }
}

void dequeue()
{
    if (Front == -1 || Front > Rear)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
}

void show()
{
    if (Front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
