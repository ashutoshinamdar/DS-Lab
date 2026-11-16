
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("Popped element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("Stack elements are:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeStack() {
    while (top != NULL) {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            freeStack();
            return 0;
        }

        switch (choice) {

            case 1:
                printf("Enter the value to push: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Exiting.\n");
                    freeStack();
                    return 0;
                }

                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                freeStack();
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
