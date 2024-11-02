#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

// Function to insert at beginning of linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* new_node = newNode(data);
    new_node->next = head;
    return new_node;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node *prev = nullptr, *current = head, *next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int N;
    cin >> N;  // Read length of chain
    
    // Read elements and create linked list
    Node* head = nullptr;
    vector<int> elements(N);
    
    // Read elements into vector first (to maintain original order)
    for(int i = 0; i < N; i++) {
        cin >> elements[i];
    }
    
    // Create linked list in original order
    for(int i = N-1; i >= 0; i--) {
        head = insertAtBeginning(head, elements[i]);
    }
    
    // Reverse the linked list
    head = reverseList(head);
    
    // Print the reversed list
    printList(head);
    
    // Clean up memory
    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}