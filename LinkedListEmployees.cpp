#include <iostream>
#include <string>
#include <limits>

class Employee {
    public:
    int id;
    std::string name;
    std::string job;
    float salary;
    float commission;
    
    Employee* next;
};

void insertBegin (Employee* &head, int id, std::string name, std::string job, float salary, float commission) {
    Employee* newNode = new Employee();
    newNode->id = id;
    newNode->name = name;
    newNode->job = job;
    newNode->salary = salary;
    newNode->commission = commission;
    newNode->next = head;
    head = newNode;
}

void insertEnd (Employee* &head, int id, std::string name, std::string job, float salary, float commission) {
    Employee* newNode = new Employee();
    newNode->id = id;
    newNode->name = name;
    newNode->job = job;
    newNode->salary = salary;
    newNode->commission = commission;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Employee* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertPosition (Employee* &head, int id, std::string name, std::string job, float salary, float commission, int pos) {
    Employee* newNode = new Employee();
    newNode->id = id;
    newNode->name = name;
    newNode->job = job;
    newNode->salary = salary;
    newNode->commission = commission;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Employee* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout <<"\nInvalid postion!";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteBegin (Employee*& head) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else {
        Employee* del = head;
        head = head->next;
        delete del;
        std::cout <<"\nFirst details deleted!";
    }
}

void deleteEnd (Employee*& head) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
        std::cout <<"\nOnly details deleted!";
    } else {
        Employee* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Employee* del = temp->next;
        temp->next = nullptr;
        delete del;
        std::cout <<"\nLast details deleted!";
    }
}

void deletePosition (Employee*& head,int pos) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else if (pos == 1) {
        Employee* temp = head;
        head = head->next;
        delete temp;
    } else {
        Employee* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;

            if (temp == nullptr) {
                std::cout <<"\nInvalid postion!";
                return;
            }
        }
        Employee* nodeTodelete = temp->next;
        temp->next = nodeTodelete->next;
        delete nodeTodelete;
        std::cout <<"\nDetails deleted!";
    }
}

void search (Employee* head , int key) {
    Employee* temp = head;
    bool found = false;

    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else {
        while (temp != nullptr) {
            if (temp->id == key) {
                std::cout <<"\nDetails Found!\n";
                std::cout <<"Employee id : "<<temp->id
                          <<" | Name : "<<temp->name
                          <<" | Job : "<<temp->job
                          <<" | Salary : "<<temp->salary
                          <<" | Commission : "<<temp->salary*temp->commission/100
                          <<"\n";
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            std::cout <<"\nDetails not found!";
        }
    }
}

void display (Employee* head) {
    if (head == nullptr) {
        std::cout <<"\nList is empty!";
    } else {
        std::cout <<"\nEmployee Details : \n";
        Employee* temp = head;
        while (temp != nullptr) {
            std::cout <<"Employee id : "<<temp->id
                      <<" | Name : "<<temp->name
                      <<" | Job : "<<temp->job
                      <<" | Salary : "<<temp->salary
                      <<" | Commission : "<<temp->salary*temp->commission/100
                      <<"\n";
            temp = temp->next;
        }
    }
}

int main () {
    Employee* head = nullptr;
    int id;
    std::string name;
    std::string job;
    float salary;
    float commission;
    int pos;
    int choice;

    do {
        std::cout<<"\n--- Employee Information ---\n";
        std::cout <<"1.Insert at beginning\n";
        std::cout <<"2.Insert at end\n";
        std::cout <<"3.Insert at position\n";
        std::cout <<"4.Delete at beginning\n";
        std::cout <<"5.Delete at end\n";
        std::cout <<"6.Delete at postion\n";
        std::cout <<"7.Search employee\n";
        std::cout <<"8.Display employee details\n";
        std::cout <<"9.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1:
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            while (true) {
                std::cout <<"Enter employee id : ";
                std::cin >>id;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid employee id!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

            std::cout <<"Enter employee name : ";
            std::getline(std::cin , name);

            std::cout <<"Enter job : ";
            std::getline(std::cin , job);

            while (true) {
                std::cout <<"Enter salary : ";
                std::cin >>salary;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid salary!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            while (true) {
                std::cout <<"Enter commission : ";
                std::cin >>commission;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid commission!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            insertBegin(head ,id ,name, job, salary, commission);
            break;

            case 2:
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            while (true) {
                std::cout <<"Enter employee id : ";
                std::cin >>id;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid employee id!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

            std::cout <<"Enter employee name : ";
            std::getline(std::cin , name);

            std::cout <<"Enter job : ";
            std::getline(std::cin , job);

            while (true) {
                std::cout <<"Enter salary : ";
                std::cin >>salary;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid salary!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            while (true) {
                std::cout <<"Enter commission : ";
                std::cin >>commission;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid commission!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            insertEnd(head , id, name, job, salary, commission);
            break;

            case 3:
            std::cout <<"\nEnter position to insert details : ";
            std::cin >>pos;
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            while (true) {
                std::cout <<"Enter employee id : ";
                std::cin >>id;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid employee id!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

            std::cout <<"Enter employee name : ";
            std::getline(std::cin , name);

            std::cout <<"Enter job : ";
            std::getline(std::cin , job);

            while (true) {
                std::cout <<"Enter salary : ";
                std::cin >>salary;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid salary!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            while (true) {
                std::cout <<"Enter commission : ";
                std::cin >>commission;

                if (std::cin.fail()) {
                    std::cout <<"\nInvalid commission!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
                    continue;
                } else {
                    break;
                }
            }

            insertPosition(head, id, name, job, salary, commission ,pos);
            break;

            case 4:
            deleteBegin(head);
            break;

            case 5:
            deleteEnd(head);
            break;

            case 6:
            std::cout <<"\nEnter postion to delete deatils : ";
            std::cin >>pos;
            deletePosition(head, pos);
            break;

            case 7:
            std::cout <<"\nEnter employee id to search : ";
            std::cin >>id;
            search(head, id);
            break;

            case 8:
            display(head);
            break;

            case 9:
            std::cout <<"\n\033[32mProgram Exited!\033[0m";
            break;

            default:
            std::cout <<"\n\033[31mInvalid choice!\033[0m";
            break;
        }

    } while (choice != 9);

    return 0;
}
