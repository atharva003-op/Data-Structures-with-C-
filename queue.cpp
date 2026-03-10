#include <iostream>

int main () {
    int queue[5];
    int front = 0;
    int rear = -1;
    int n;
    int choice;

    do{
        std::cout <<"\n--- Queue Operations ---\n";
        std::cout <<"1.Insert\n";
        std::cout <<"2.Delete\n";
        std::cout <<"3.Display\n";
        std::cout <<"4.Exit\n";
        std::cout <<"Enter your choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1:
            std::cout <<"Enter how many elements you what to enter ?: ";
            std::cin >>n;

            if (rear == 4) {
                std::cout <<"Queue Overflow! You can enter maximum 5 elements.";
                break;
            }
            for (int i = 0; i < n; i++) {
                std::cout <<"Enter an element : ";
                std::cin >>queue[++rear];
            }
            break;

            case 2:
            if (front > rear) {
                std::cout <<"Queue Underflow!";
                break;
            }
            std::cout <<"Deleted Element : "<<queue[front];
            front++;
            break;

            case 3:
            if (rear == -1) {
                std::cout <<"Queue is Empty!";
                break;
            }
            std::cout <<"Queue Elements : ";
            for (int i = front; i <= rear; i++) {
                std::cout <<queue[i]<<" ";
            }
            break;

            case 4:
            std::cout <<"Program Exited Sucessfully!";
            break;

            default:
            std::cout <<"Invalid Choice!";
            break;

        }
    } while (choice != 4);

    return 0;
}