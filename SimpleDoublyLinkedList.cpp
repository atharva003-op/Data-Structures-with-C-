#include <iostream>

class Node {
    public:
    int data;

    Node* prev;
    Node* next;
};

int main () {
    Node* head = nullptr;
    Node* temp = nullptr;
    int choice , value;

    do {
        std::cout <<"\n--- Doubly Linked List ---\n";
        std::cout <<"1.Insert at beginning\n";
        std::cout <<"2.Insert at end\n";
        std::cout <<"3.Delete at beginning\n";
        std::cout <<"4.Delete at end\n";
        std::cout <<"5.Display\n";
        std::cout <<"6.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        if (choice == 1) {
            std::cout <<"Enter data : ";
            std::cin >>value;

            Node* newNode = new Node();
            newNode->data = value;
            newNode->prev = nullptr;
            newNode->next = head;

            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        }

        else if (choice == 2) {
            std::cout <<"Enter data : ";
            std::cin >>value;

            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;
            newNode->prev = nullptr;

            if (head == nullptr) {
                newNode->prev = nullptr;
                head = newNode;
            } else {
                temp = head;

                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
        }

        else if (choice == 3) {
            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else {
                temp = head;
                head = head->next;

                if (head != nullptr) {
                    head->prev = nullptr;
                }
                delete temp;
                std::cout <<"\nFirst node deleted!";
            }
        }

        else if (choice == 4) {
            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else if (head->next == nullptr) {
                delete head;
                head = nullptr;
                std::cout <<"\nOnly node deleted!";
            } else {
                temp = head;

                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->prev->next = nullptr;
                delete temp;
                std::cout <<"\nLast node deleted!";
            }
        }

        else if (choice == 5) {
            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else {
                std::cout <<"\nDoubly Linked List : ";
                temp = head;
                while (temp != nullptr) {
                    std::cout<<temp->data<<" ";
                    temp = temp->next;
                }
            }
        }

        else if (choice == 6) {
            std::cout <<"\n\033[32mProgram Exited!\033[0m";
        }

        else {
            std::cout <<"\n\033[31mInvalid choice\033[0m";
        }

    } while (choice != 6);
}
