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

int peek(struct Stack* stack) {
    if (stack->top == NULL) return -1;
    return stack->top->data;
}

int main() {
    struct Stack stack;
    stack.top = NULL;
    int choice, value;

    while (1) {
        printf("1: Push, 2: Pop, 3: Peek, 0: Exit\nEnter choice: ");
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
                value = peek(&stack);
                if (value == -1) printf("Stack Empty\n");
                else printf("Top element: %d\n", value);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
