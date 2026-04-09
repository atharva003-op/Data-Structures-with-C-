#include <iostream>
#include <string>
#include <limits>

class Student {
    public:
    int rollno;
    std::string name;
    char gender;
    float m1;
    float m2;
    float m3;

    Student* next;
};

void insertbegin (Student*& head , int rollno , std::string name , char gender , float m1, float m2, float m3) {
    Student* newNode = new Student();
    newNode->name = name;
    newNode->rollno = rollno;
    newNode->gender = gender;
    newNode->m1 = m1;
    newNode->m2 = m2;
    newNode->m3 = m3;
    newNode->next = head;
    head = newNode;
}

void insertend (Student*& head , int rollno , std::string name , char gender , float m1, float m2, float m3) {
    Student* newNode = new Student();
    newNode->name = name;
    newNode->rollno = rollno;
    newNode->gender = gender;
    newNode->m1 = m1;
    newNode->m2 = m2;
    newNode->m3 = m3;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertposition (Student*& head , int rollno , std::string name , char gender , float m1, float m2, float m3, int pos) {
    Student* newNode = new Student();
    newNode->name = name;
    newNode->rollno = rollno;
    newNode->gender = gender;
    newNode->m1 = m1;
    newNode->m2 = m2;
    newNode->m3 = m3;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Student* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deletebegin (Student*& head) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else {
        Student * del = head;
        head = head->next;
        delete del;
        std::cout <<"\nFirst details deleted!";
    }
}

void deleteend (Student*& head) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
        std::cout <<"\nOnly details deleted!";
    } else {
        Student* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Student* del = temp->next;
        temp->next = nullptr;
        delete del;
        std::cout <<"\nLast details deleted!";
    }
}

void deletepostion (Student*& head , int pos) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
        return;
    } else if (pos == 1) {
        Student* temp = head;
        head = head->next;
        delete temp;
    } else {
        Student* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        Student* nodetoDelete = temp->next;
        temp->next = nodetoDelete->next;
        delete nodetoDelete;
        std::cout <<"\nDetails deleted!";
    }
}

void search (Student* head , int key) {
    Student* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->rollno == key) {
            std::cout <<"\nDetails found!\n";
            std::cout <<"Name : "<<temp->name<<" | Roll No : "<<temp->rollno<<" | Gender : "<<temp->gender<<" | Total Marks : "<<temp->m1 + temp->m2 + temp->m3<<"\n";
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        std::cout <<"\nDetails not found!";
    }
}

void display (Student* head) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
        return;
    }
    std::cout <<"\n--- Student Details ---\n";
    Student* temp = head;
    while (temp != nullptr) {
        std::cout <<"Name : "<<temp->name<<" | Roll No : "<<temp->rollno<<" | Gender : "<<temp->gender<<" | Total Marks : "<<temp->m1 + temp->m2 + temp->m3<<"\n";
        temp = temp->next;
    }
}

int main () {
    Student* head = nullptr;
    int rollno;
    std::string name;
    char gender;
    float m1;
    float m2;
    float m3;
    int pos;
    int choice;

    do {
        std::cout <<"\n--- Student Information ---\n";
        std::cout <<"1.Insert at beginning\n";
        std::cout <<"2.Insert at end\n";
        std::cout <<"3.Insert at position\n";
        std::cout <<"4.Delete at beginning\n";
        std::cout <<"5.Delete at end\n";
        std::cout <<"6.Delete at position\n";
        std::cout <<"7.Search details\n";
        std::cout <<"8.Display details\n";
        std::cout <<"9.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1: 
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            std::cout <<"Enter name : ";
            std::cin >>name;

            std::cout <<"Enter roll no : ";
            std::cin >>rollno;

            std::cout <<"Enter gender (M|F) : ";
            std::cin >>gender;

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>m3;

            insertbegin(head, rollno , name , gender , m1,m2,m3);
            break;

            case 2: 
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            std::cout <<"Enter name : ";
            std::cin >>name;

            std::cout <<"Enter roll no : ";
            std::cin >>rollno;

            std::cout <<"Enter gender (M|F) : ";
            std::cin >>gender;

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>m3;

            insertend(head , rollno , name , gender , m1,m2,m3);
            break;

            case 3:
            std::cout <<"Enter position to insert details : ";
            std::cin >>pos;

            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            std::cout <<"Enter name : ";
            std::cin >>name;

            std::cout <<"Enter roll no : ";
            std::cin >>rollno;

            std::cout <<"Enter gender (M|F) : ";
            std::cin >>gender;

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>m3;

            insertposition(head , rollno , name , gender , m1,m2,m3 , pos);
            break;

            case 4:
            deletebegin(head);
            break;

            case 5:
            deleteend(head);
            break;

            case 6:
            std::cout <<"Enter position to delete details : ";
            std::cin >>pos;
            deletepostion(head , pos);
            break;

            case 7:
            std::cout <<"Enter Roll No to search details : ";
            std::cin >>rollno;
            search(head , rollno);
            break;

            case 8:
            display(head);
            break;

            case 9:
            std::cout <<"\n\033[32mProgram exited sucessfully!\033[0m";
            break;

            default:
            std::cout <<"\n\033[31mInvalid choice!\033[0m";
            break;
        }
 
    } while (choice != 9);

}
