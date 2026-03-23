#include <iostream>
#include <string>
#include <limits>

class Student {
    public:
    std::string name;
    int rollno;
    std::string dept;
    float m1;
    float m2;
    float m3;

    Student* next;
};

int main () {
    Student* head = nullptr;
    Student* temp = nullptr;
    int value , choice;

    std::string name;
    int rollno;
    std::string dept;
    float m1;
    float m2;
    float m3;

    do {
        std::cout <<"\n --- Student Information ---\n";
        std::cout <<"1.Insert details at beginning\n";
        std::cout <<"2.Insert details at end\n";
        std::cout <<"3.Insert details at position\n";
        std::cout <<"4.Delete details at beginning\n";
        std::cout <<"5.Delete details at end\n";
        std::cout <<"6.Delete details at position\n";
        std::cout <<"7.Search student details\n";
        std::cout <<"8.Display details\n";
        std::cout <<"9.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        if (choice == 1) {
            std::cin.ignore(std::numeric_limits<std::streamsize> ::max() , '\n');

            std::cout <<"Enter name : ";
            std::getline (std::cin , name);

            std::cout <<"Enter Roll No : ";
            std::cin >>rollno;

            std::cin.ignore(std::numeric_limits<std::streamsize> ::max() , '\n');

            std::cout <<"Enter department : ";
            std::getline (std::cin , dept);

            std::cout <<"Enter marks in Python programming : ";
            std::cin >>m1;
            
            std::cout <<"Enter marks in C++ programming : ";
            std::cin >>m2;

            std::cout <<"Enter marks in C programming : ";
            std::cin >>m3;

            Student* newNode = new Student();
            newNode->name = name;
            newNode->rollno = rollno;
            newNode->dept = dept;
            newNode->m1 = m1;
            newNode->m2 = m2;
            newNode->m3 = m3;
            newNode->next = head;
            head = newNode;
        }

        else if (choice == 2) {
            std::cin.ignore(std::numeric_limits<std::streamsize> ::max() , '\n');

            std::cout <<"Enter name : ";
            std::getline (std::cin , name);

            std::cout <<"Enter Roll No : ";
            std::cin >>rollno;

            std::cin.ignore(std::numeric_limits<std::streamsize> ::max() , '\n');

            std::cout <<"Enter department : ";
            std::getline (std::cin , dept);

            std::cout <<"Enter marks in Python programming : ";
            std::cin >>m1;
            
            std::cout <<"Enter marks in C++ programming : ";
            std::cin >>m2;

            std::cout <<"Enter marks in C programming : ";
            std::cin >>m3;

            Student* newNode = new Student();
            newNode->name = name;
            newNode->rollno = rollno;
            newNode->dept = dept;
            newNode->m1 = m1;
            newNode->m2 = m2;
            newNode->m3 = m3;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                Student* t = head;
                while (t->next != nullptr) {
                    t = t->next;
                }
                t->next = newNode;
            }
        }

        else if (choice == 3) {
            int pos;
            std::cout <<"Enter a position to insert details : ";
            std::cin >>pos;

            std::cin.ignore(std::numeric_limits<std::streamsize> ::max() , '\n');

            std::cout <<"Enter name : ";
            std::getline (std::cin , name);

            std::cout <<"Enter Roll No : ";
            std::cin >>rollno;

            std::cin.ignore(std::numeric_limits<std::streamsize> ::max() , '\n');

            std::cout <<"Enter department : ";
            std::getline (std::cin , dept);

            std::cout <<"Enter marks in Python programming : ";
            std::cin >>m1;
            
            std::cout <<"Enter marks in C++ programming : ";
            std::cin >>m2;

            std::cout <<"Enter marks in C programming : ";
            std::cin >>m3;

            Student* newNode = new Student();
            newNode->name = name;
            newNode->rollno = rollno;
            newNode->dept = dept;
            newNode->m1 = m1;
            newNode->m2 = m2;
            newNode->m3 = m3;

            if (pos == 1) {
                newNode->next = head;
                head = newNode;
            } else {
                temp = head;

                for (int i = 1; i < pos - 1; i++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        else if (choice == 4) {
            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else {
                Student* del = head;
                head = head->next;
                delete del;
                std::cout <<"\nFirst details deleted";
            }
        }

        else if (choice == 5) {
            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else if (head->next == nullptr) {
                delete head;
                head = nullptr;
                std::cout <<"\nOnly details deleted";
            } else {
                temp = head;

                while (temp->next->next != nullptr) {
                    temp = temp->next;
                } 
                Student* del = temp->next;
                temp->next = nullptr;
                delete del;
                std::cout <<"\nLast details deleted";             
            }
        }

        else if (choice == 6) {
            int pos;
            std::cout <<"Enter a position to delete details : ";
            std::cin >>pos;

            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else if (pos == 1) {
                temp = head;
                head = head->next;
                delete temp;
            } else {
                temp = head;
                 for (int i = 1; i < pos - 1; i++) {
                    temp = temp->next;
                 }
                 Student* nodetoDelete = temp->next;
                 temp->next = nodetoDelete->next;
                 delete nodetoDelete;
            }
        }

        else if (choice == 7) {
            int key;
            bool found = false;

            std::cout <<"Enter Roll No : ";
            std::cin >>key;

            temp = head;
            while (temp != nullptr) {
                if (temp->rollno == key) {
                    std::cout <<"\nStudent found : \n";
                    std::cout <<"Name : "<<temp->name<<" | Roll No : "<<temp->rollno<<" | Department : "<<temp->dept<<" | Total marks : "<<temp->m1 + temp->m2 + temp->m3<<"\n";
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if (!found) {
                std::cout <<"\nDetails not found!";
            }
        }

        else if (choice == 8) {
            if (head == nullptr) {
                std::cout <<"\nList is empty!";
            } else {
                std::cout <<"\nStudent details : \n";
                temp = head;
                while (temp != nullptr) {
                    std::cout <<"Name : "<<temp->name<<" | Roll No : "<<temp->rollno<<" | Department : "<<temp->dept<<" | Total marks : "<<temp->m1 + temp->m2 + temp->m3<<"\n";
                    temp = temp->next;
                }
            }
            
        }

        else if (choice == 9) {
            std::cout <<"\nProgram Exited!";
        }

        else {
            std::cout <<"\nInvalid choice!";
        }

    } while (choice != 9);

    return 0;
}
