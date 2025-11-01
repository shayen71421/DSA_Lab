#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) return -1;
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

int peekStack(struct Stack* stack) {
    if (stack->top == NULL) return -1;
    return stack->top->data;
}


struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* queue, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) return -1;
    struct Node* temp = queue->front;
    int dequeued = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return dequeued;
}

int peekQueue(struct Queue* queue) {
    if (queue->front == NULL) return -1;
    return queue->front->data;
}

int main() {
    struct Stack stack;
    stack.top = NULL;
    struct Queue queue;
    queue.front = queue.rear = NULL;

    int choice, value;
    
    while (1) {
        printf("1: Push stack, 2: Pop stack, 3: Display stack top\n");
        printf("4: Enqueue queue, 5: Dequeue queue, 6: Display queue front\n");
        printf("0: Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value == -1) printf("Stack Empty\n");
                else printf("Popped %d\n", value);
                break;
            case 3:
                value = peekStack(&stack);
                if (value == -1) printf("Stack Empty\n");
                else printf("Stack top: %d\n", value);
                break;
            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 5:
                value = dequeue(&queue);
                if (value == -1) printf("Queue Empty\n");
                else printf("Dequeued %d\n", value);
                break;
            case 6:
                value = peekQueue(&queue);
                if (value == -1) printf("Queue Empty\n");
                else printf("Queue front: %d\n", value);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
