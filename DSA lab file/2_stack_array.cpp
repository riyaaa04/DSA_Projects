//Implement Stack ADT using array.
#include <iostream>
const int MAX_SIZE = 100; 
class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1; 
    }
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }
    void pop() {
        if (top == -1) {
            std::cout << "Stack Underflow\n";
            return;
        }
        top--;
    }
    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};
int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top element after popping: " << stack.peek() << std::endl;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
