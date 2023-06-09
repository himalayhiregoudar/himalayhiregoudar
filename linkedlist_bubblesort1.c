#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to swap two nodes
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to perform bubble sort on linked list
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    // Check for empty list
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        // Traverse the linked list
        while (ptr1->next != lptr) {
            // If the current node's data is greater than the next node's data, swap them
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Test the code
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    push(&head, 6);
    push(&head, 3);
    push(&head, 8);
    push(&head, 1);
    push(&head, 9);

    printf("Original Linked List: ");
    printList(head);

    // Perform bubble sort
    bubbleSort(head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}
