#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete a node with given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value not found in the linked list." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Print the linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertAtEnd(5);
    myList.insertAtEnd(10);
    myList.insertAtBeginning(2);
    myList.insertAtEnd(15);
    myList.display(); // Output: 2 5 10 15

    myList.deleteNode(10);
    myList.display(); // Output: 2 5 15

    myList.deleteNode(20); // Output: Value not found in the linked list.

    return 0;
}
