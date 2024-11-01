#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(data);
    return head;
}

// Function to remove duplicates from the sorted linked list
struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

// Function to count nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int N, value;
    struct Node* head = NULL;
    
    // Read the number of entries
    scanf("%d", &N);
    
    // Read N integers and create the linked list
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
    
    // Remove duplicates
    head = removeDuplicates(head);
    
    // Count unique elements
    int uniqueCount = countNodes(head);
    
    // Print output
    printf("%d\n", uniqueCount);
    if (uniqueCount > 0) {
        printList(head);
    }
    
    // Free memory
    freeList(head);
    
    return 0;
}