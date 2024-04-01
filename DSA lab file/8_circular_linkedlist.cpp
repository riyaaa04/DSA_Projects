// Implement Circular Linked List ADT.
#include <iostream>
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Circular link to itself
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
    void deleteNode(int value) {
        if (head == nullptr)
            return;
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == value) {
                if (temp == head) {
                    if (temp->next == head) {
                        delete temp;
                        head = nullptr;
                        return;
                    } else {
                        Node* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        last->next = head->next;
                        head = head->next;
                        delete temp;
                        return;
                    }
                } else {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    std::cout << "Circular Linked List: ";
    list.display(); 

    list.deleteNode(2); 

    std::cout << "Circular Linked List after deletion: ";
    list.display(); 

    return 0;
}
