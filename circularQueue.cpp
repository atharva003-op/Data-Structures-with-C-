#include <iostream>

int main () {
    int queue[5];
    int front = -1;
    int rear = -1;
    int n;
    int choice;

    do {
        std::cout <<"\n---Circular Queue Operations---\n";
        std::cout <<"1.Insert\n";
        std::cout <<"2.Delete\n";
        std::cout <<"3.Display\n";
        std::cout <<"4.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1:
            std::cout <<"Enter how many elements do you want ?: ";
            std::cin>>n;

            for (int i = 0; i < n; i++) {
                if((rear + 1) % 5 == front) {
                    std::cout <<"Queue Overflow!";
                    break;
                }

                if (front == -1)
                    front = 0;

                rear = (rear + 1) % 5;
                std::cout <<"Enter an element : ";
                std::cin >>queue[rear];
            }
            break;

            case 2:
            if (front == -1){
                std::cout <<"Queue Underflow!";
                break;
            }

            std::cout <<"\nDeleted : "<<queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % 5;
            }
            break;

            case 3: {
                if (front == -1) {
                std::cout <<"Queue is Empty!";
                break;
                }

                int i = front;
                std::cout <<"Circular queue elements : ";
                while (true) {
                std::cout <<queue[i]<<" ";

                if (i == rear) 
                    break;

                i = (i + 1) % 5;
            }
            break;
            }

            case 4:
            std::cout <<"\nProgram Exited!";
            break;

            default :
            std::cout <<"\nInvalid Choice!";
            break;
        }

    }while(choice != 4);
}