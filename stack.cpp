#include <iostream>

int main () {
    int stack[5];
    int top = -1;
    int n;
    int choice;

    do {
        std::cout <<"\n--- Stack Operations ---\n";
        std::cout <<"1.Push\n";
        std::cout <<"2.Pop\n";
        std::cout <<"3.Peek\n";
        std::cout <<"4.Display\n";
        std::cout <<"5.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1:
            std::cout <<"Enter how many elements do you what to enter ?: ";
            std::cin >>n;

            if (top + n >= 5) {
                std::cout <<"Stack Overflow! You can maximum enter 5 elements\n";
                break;
            }

            for (int i = 0; i < n; i++) {
                std::cout <<"Enter an element : ";
                std::cin >>stack[++top];
            }
            break;

            case 2:
            if (top == -1) {
                std::cout <<"Stack Underflow\n";
                break;
            }
            std::cout <<"Popped element : "<<stack[top];
            --top;
            break;

            case 3:
            if (top == -1) {
                std::cout <<"Stack is Empty!";
                break;
            }
            std::cout <<"Top element : "<<stack[top];
            break;

            case 4:
            if(top == -1) {
                std::cout <<"Stack is Empty!";
                break;
            }
            std::cout <<"Stack elements : ";
            for (int i = top; i >= 0; i--) {
                std::cout <<stack[i]<<" ";
            }
            break;

            case 5:
            std::cout <<"Program Exited!";
            break;

            default :
            std::cout <<"Invalid Choice!";
            break;

        }

    }while (choice != 5);

    return 0;
}