#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Employee {
    public:
    std::string name;
    int id;
    float salary;
};

void addDetails (std::vector <Employee> & employees) {
    Employee e;

    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');

    std::cout <<"Enter employee name : ";
    std::getline (std::cin , e.name);

    std::cout <<"Enter employee id : ";
    std::cin >>e.id;

    std::cout <<"Enter employee salary : ";
    std::cin >>e.salary;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].id == e.id) {
            std::cout << "\nEmployee ID already exists!\n";
            return;
        }
    }

    employees.push_back(e);

    std::cout <<"\nDetails inserted!";
}

void displayDetails (const std::vector <Employee> & employees) {
    if (employees.empty()) {
        std::cout <<"\nList is empty!";
        return;
    }

    std::cout <<"\nEmployee Details : \n";
    for (int i = 0; i < employees.size(); i++) {
        std::cout <<"Name : "<<employees[i].name
                  <<" | Id : "<<employees[i].id
                  <<" | Salary : "<<employees[i].salary
                  <<"\n";
    }
}


void searchDetails (const std::vector <Employee> & employees) {
    if (employees.empty()) {
        std::cout <<"\nList is empty!";
        return;
    }

    int key;
    bool found = false;

    std::cout <<"Enter employee id to search : ";
    std::cin >>key;

    for (int i = 0 ; i < employees.size(); i++) {
        if (employees[i].id == key) {
            std::cout <<"\nEmployee Found!\n";
            std::cout <<"Name : "<<employees[i].name
                  <<" | Id : "<<employees[i].id
                  <<" | Salary : "<<employees[i].salary
                  <<"\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout <<"\nEmployee not found!";
    }
}

void FindHighestSalary (const std::vector <Employee> & employees) {
    if (employees.empty()) {
        std::cout <<"\nList is empty!";
        return;
    }

    int max = 0;
    for (int i = 1; i < employees.size(); i++) {
        if (employees[i].salary > employees[max].salary) {
            max = i;
        }
    }

    std::cout <<"\nEmployee With highest salary : "
              <<employees[max].name
              <<" ("<<employees[max].salary<<")";
}

void deleteDetails (std::vector <Employee> & employees) {
    if (employees.empty()) {
        std::cout <<"\nList is empty!";
        return;
    }

    int key;
    bool deleted = false;

    std::cout <<"Enter employee id to delete details : ";
    std::cin >>key;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].id == key) {
            employees.erase(employees.begin() +i);

            std::cout <<"\nEmployee deleted!";
            deleted = true;
            break;
        }
    }
    if (!deleted) {
        std::cout <<"\nEmployee not found!";
    }
}

int main () {
    std::vector <Employee> employees;
    int choice;

    do {
        std::cout <<"\n --- Employee Information ---\n";
        std::cout <<"1.Insert details\n";
        std::cout <<"2.Display details\n";
        std::cout <<"3.Search details\n";
        std::cout <<"4.Delete details\n";
        std::cout <<"5.Get employee with highest salary\n";
        std::cout <<"6.Exit\n";
        std::cout <<"Enter choice : ";
        std::cin >>choice;

        switch (choice) {
            case 1:
            addDetails(employees);
            break;

            case 2:
            displayDetails(employees);
            break;

            case 3:
            searchDetails(employees);
            break;

            case 4:
            deleteDetails(employees);
            break;

            case 5:
            FindHighestSalary(employees);
            break;

            case 6:
            std::cout <<"\n\033[32mProgram Exited!\033[0m";
            break;

            default:
            std::cout <<"\n\033[31mInvalid Choice!\033[0m";
            break;
        }

    } while (choice != 6);

    return 0;
}
