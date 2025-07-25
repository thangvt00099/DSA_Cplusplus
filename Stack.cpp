#include <iostream>
#include <memory>
using namespace std;

class Stack {  
    public:
        Stack() {
            this->top = -1;
            for (int i =0; i < 5; i++) {
                this->arr[i] = 0;
            }
        }

        void push(int value);       
        int pop();
        bool isEmpty();
        bool isFull();  
        int size(); 
        void printStack();   
        
    private:
        int top;
        int arr[5];
};

void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        arr[top] = value;
        cout << "Push element done." << endl;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return 0;
    } else {
        int popValue = arr[top];
        arr[top] = 0;
        top--;
        return popValue;
    }
}

bool Stack::isEmpty() {
    return this->top == -1;
}

bool Stack::isFull() {
    return this->top == 4;
}


int Stack::size() {
    return top + 1;
}

void Stack::printStack() {
    while (!isEmpty()) {
        cout << arr[top] << " ";
        pop();
    }
    cout << endl;
}



int main() {
    shared_ptr<Stack> stack = make_shared<Stack>();
    int option;
    do {
        cout << "===========Menu Stack===========" << endl;
        cout << "1. Push method" << endl;
        cout << "2. Pop method" << endl;
        cout << "3. isEmpty method" << endl;
        cout << "4. isFull method" << endl;
        cout << "5. Size method" << endl;
        cout << "6. Print Stack" << endl;
        cout << "0. Exit menu" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
        case 0:
            cout << "Program quit!" << endl;
            break;
        case 1:
            int value;
            cout << "Enter value: ";
            cin >> value;
            stack->push(value);
            break;
        case 2:
            cout << "Element removed: " << stack->pop() << endl;
            break;
        case 3:
            cout << "Check empty of Stack -> " << stack->isEmpty() << endl;
            break;
        case 4:
            cout << "Check full of Stack -> " << stack->isFull() << endl;
            break;
        case 5:
            cout << "Size of Stack: " << stack->size() << endl;
            break;
        case 6:
            stack->printStack();
            break;
        default:
            cout << "Program crash!" << endl;
            exit(0);
            break;
        }
    } while (option != 0);  
    return 0;
}