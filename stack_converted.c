
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stackArr[MAX];
int topIndex = -1;

// PUSH operation
void push(int value) {
    if (topIndex >= MAX - 1) {
        printf("Stack Overflow! Cannot insert.\n");
        return;
    }
    stackArr[++topIndex] = value;
    printf("%d added to stack.\n", value);
}

// POP operation
void pop() {
    if (topIndex < 0) {
        printf("Stack Underflow! Nothing to remove.\n");
        return;
    }
    printf("%d removed from stack.\n", stackArr[topIndex--]);
}

// PEEK operation
void peek() {
    if (topIndex < 0) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element: %d\n", stackArr[topIndex]);
}

// DISPLAY operation
void display() {
    if (topIndex < 0) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= topIndex; i++) {
        printf("%d ", stackArr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    char input[128];

    while (1) {
        printf("\n======== STACK MENU ========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input failed. Exiting.\n");
            break;
        }

        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number (1–5).\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (!fgets(input, sizeof(input), stdin)) { 
                    printf("Input error.\n"); 
                    break; 
                }
                if (sscanf(input, "%d", &value) != 1) {
                    printf("Invalid number! Try again.\n");
                } else {
                    push(value);
                }
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid option! Please pick between 1 and 5.\n");
        }
    }

    return 0;
}
