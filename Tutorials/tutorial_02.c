#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
