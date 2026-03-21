#include <iostream>

class Node {
    public:
    int data;
    Node* next;
};

int main () {
    Node* head = nullptr;
    Node* temp = nullptr;
    int n , choice;
    do {
        std::cout <<"\n--- Linked List ---\n";
        std::cout <<"1.Insert at beginning\n";
        std::cout <<"2.Insert at end\n";
        std::cout <<"3.Delete at beginning\n";
        std::cout <<"4.Delete at end\n";
        std::cout <<"5.Display\n";
        std::cout <<"6.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;
        switch (choice) {
            case 1:{
                std::cout <<"Enter data : ";
                std::cin >>n;

                Node* newNode = new Node();
                newNode->data = n;
                newNode->next = head;
                head = newNode;
                break;
            }

            case 2:{
                std::cout <<"Enter data : ";
                std::cin >>n;

                Node* newNode = new Node ();
                newNode->data = n;
                newNode->next = nullptr;

                if (head == nullptr) {
                    head = newNode;
                } else {
                    Node* t = head;
                    while (t->next != nullptr) {
                        t = t->next;
                    }
                    t->next = newNode;
                }
                break;
            }

            case 3:
            if (head == nullptr) {
                std::cout <<"\nList is empty";
            } else if (head != nullptr) {
                Node* del = head;
                head = head->next;
                delete del;
                std::cout <<"\nFirst element deleted!";
            }
            break;

            case 4:
            if (head == nullptr) {
                std::cout <<"\nList is empty";
            } else if (head->next == nullptr) {
                delete head;
                head = nullptr;
                std::cout <<"\nOnly element deleted";
            } else {
                temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                Node* del = temp->next;
                temp->next = nullptr;
                delete del;
                std::cout <<"\nLast element deleted";
            }
            break;

            case 5 :
            if (head == nullptr) {
                std::cout <<"\nList is empty";
            } else {
                std::cout <<"\nLinked List : ";
                temp = head;
                while (temp != nullptr) {
                    std::cout <<temp->data<<" ";
                    temp = temp->next;
                }
            }
            break;

            case 6 :
            std::cout <<"\nProgram exited";
            break;

            default :
            std::cout <<"\nInvalid choice";
            break;
        }

    } while (choice != 6);
}
