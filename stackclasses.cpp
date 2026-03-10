#include <iostream>

class Stack {
    private:
    int stack[5];
    int top =-1;

    public:
    void push(int n) {
        if (top + n >= 5) {
            std::cout <<"Stack Overflow!";
            return;
        }
        for (int i = 0; i < n; i++) {
            std::cout <<"Enter an elemnet : ";
            std::cin >>stack[++top];
        }
    }

    void pop () {
        if (top == -1) {
            std::cout <<"Stack Underflow!";
            return;
        }
        std::cout <<"Popped Element : "<<stack[top];
        --top;
    }

    void peek () {
        if (top == -1) {
            std::cout <<"Stack is Empty!";
            return;
        }
        std::cout <<"Top element : "<<stack[top];
    }

    void display () {
        if (top == -1) {
            std::cout <<"Stack is Empty!";
            return;
        }
        std::cout <<"Stack Elements : ";
        for (int i = top; i >= 0; i--) {
            std::cout <<stack[i]<< " ";
        }
    }
};

int main () {
    Stack s;
    int choice , n;

    do {
        std::cout <<"\n--- Stack Operations ---\n";
        std::cout <<"1.Push\n";
        std::cout <<"2.Pop\n";
        std::cout <<"3.Peek\n";
        std::cout <<"4.Display\n";
        std::cout <<"5.Exit\n";
        std::cout <<"Enter your choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1:
            std::cout <<"Enter how many elements do you want ?: ";
            std::cin >>n;
            s.push(n);
            break;

            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

            case 4:
            s.display();
            break;

            case 5:
            std::cout <<"Program Exited!";
            break;

            default:
            std::cout <<"Invalid choice";
            break;
        }

    }while (choice != 5);
}