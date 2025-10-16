#include <stdio.h>
#include <stdlib.h>

// Stack node definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Push: insert at the end
Node* push(Node* top, int value) {
    Node* newNode = createNode(value);

    if (top == NULL) {
        return newNode;
    }

    Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return top;
}

// Pop: delete from the end
Node* pop(Node* top) {
    if (top == NULL) {
        printf("Stack Underflow (Empty Stack)\n");
        return NULL;
    }

    if (top->next == NULL) {
        printf("Popped element: %d\n", top->data);
        free(top);
        return NULL;
    }

    Node* temp = top;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Popped element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;

    return top;
}

// Peek: view top element (last element)
void peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Top element: %d\n", temp->data);
}

// isEmpty: check if stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Display stack
void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (bottom to top): ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Main function
int main() {
    Node* top = NULL;
    int choice, value;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                display(top);
                break;
            case 2:
                top = pop(top);
                display(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                if (isEmpty(top))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

