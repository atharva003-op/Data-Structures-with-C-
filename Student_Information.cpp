#include <iostream>
#include <string>

class Student {
    public:
    int rollNo;
    std::string name;
    char gender;
    std::string dept;
    int m1;
    int m2;
    int m3;
};

void insertBegin (Student students[], int &n) {
    Student s;
    if (n > 10) {
        std::cout <<"Size cannot exceed 10!\n";
        return;
    } else {
        if (n == 10) {
            std::cout <<"List is full!\n";
            return;
        } else {
            std::cout <<"Enter Roll No : ";
            std::cin >>s.rollNo;

            std::cin.ignore();

            std::cout <<"Enter Name : ";
            std::getline(std::cin, s.name);

            std::cout <<"Enter Gender (M/F) : ";
            std::cin >>s.gender;

            std::cin.ignore();

            std::cout <<"Enter Department : ";
            std::getline(std::cin , s.dept);

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>s.m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>s.m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>s.m3;

            for (int i = n - 1; i >= 0; i--) {
                students[i+1] = students[i];
            }
            students[0] = s;
            n++;
            std::cout <<"Details inserted!\n";
        }
    }
}

void insertEnd (Student students[], int &n) {
    Student s;
    if (n > 10) {
        std::cout <<"Size cannot exceed 10!\n";
        return;
    } else {
        if (n == 10) {
            std::cout <<"List is full!\n";
            return;
        } else {
            std::cout <<"Enter Roll No : ";
            std::cin >>s.rollNo;

            std::cin.ignore();

            std::cout <<"Enter Name : ";
            std::getline(std::cin, s.name);

            std::cout <<"Enter Gender (M/F) : ";
            std::cin >>s.gender;

            std::cin.ignore();

            std::cout <<"Enter Department : ";
            std::getline(std::cin , s.dept);

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>s.m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>s.m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>s.m3;

            students[n] = s;
            n++;
            std::cout <<"Details inserted!\n";
        }
    }
}

void insertPosition (Student students[], int &n) {
    Student s;
    int pos;

    if (n > 10) {
        std::cout <<"Size cannot exceed 10!\n";
        return;
    } else {
        std::cout <<"Enter position to insert details : ";
        std::cin >>pos;

        if (pos < 0 || pos > n) {
            std::cout <<"Invalid postion!\n";
            return;
        } else {
            std::cout <<"Enter Roll No : ";
            std::cin >>s.rollNo;

            std::cin.ignore();

            std::cout <<"Enter Name : ";
            std::getline(std::cin, s.name);

            std::cout <<"Enter Gender (M/F) : ";
            std::cin >>s.gender;

            std::cin.ignore();

            std::cout <<"Enter Department : ";
            std::getline(std::cin , s.dept);

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>s.m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>s.m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>s.m3;

            for (int i = n - 1; i >= pos; i--) {
                students[i+1] = students[i];
            }
            students[pos] = s;
            n++;
            std::cout <<"Details inserted!\n";
        }
    }
}

void deleteBegin (Student students[], int &n) {
    if (n == 0) {
        std::cout <<"List is empty!\n";
        return;
    } else {
        for (int i = 0; i < n - 1; i++) {
            students[i] = students[i+1];
        }
        n--;
        std::cout <<"Details Deleted!\n";
    }
}

void deleteEnd (Student students[], int &n) {
    if (n == 0) {
        std::cout <<"List is empty!\n";
        return;
    } else {
        n--;
        std::cout <<"Details deleted!\n";
    }
}

void deletePosition (Student students[], int &n) {
    int pos;

    if (n == 0) {
        std::cout <<"List is empty!\n";
        return;
    } else {
        std::cout <<"Enter position to delete details : ";
        std::cin >>pos;

        if (pos < 0 || pos >= n) {
            std::cout <<"Invalid position!\n";
            return;
        } else {
            for (int i = pos; i < n - 1; i++) {
                students[i] = students[i+1];
            }
            n--;
            std::cout <<"Details deleted!\n";
        }
    }
}

void display (Student students[] , int n) {
    if (n == 0) {
        std::cout <<"List is empty!\n";
        return;
    } else {
        std::cout <<"\n Student Details : \n";
        for (int i = 0; i < n; i++) {
            std::cout <<"Roll No : "<<students[i].rollNo
                      <<" | Name : "<<students[i].name
                      <<" | Department : "<<students[i].dept
                      <<" | Gender : "<<students[i].gender
                      <<" | Total Marks : "<<students[i].m1 + students[i].m2 + students[i].m3
                      <<"\n";
        }
        std::cout <<"\nDetails Fetched Sucessfully!\n";
    }
}

void search (Student students[], int &n) {
    int key;
    bool found = false;

    if (n == 0) {
        std::cout <<"List is empty!\n";
        return;
    } else {
        std::cout <<"Enter RollNo to search details : ";
        std::cin >>key;
        
        for (int i = 0; i < n; i++) {
            if (key == students[i].rollNo) {
                std::cout <<"\nDetails found!\n";
                std::cout <<"Roll No : "<<students[i].rollNo
                      <<" | Name : "<<students[i].name
                      <<" | Department : "<<students[i].dept
                      <<" | Gender : "<<students[i].gender
                      <<" | Total Marks : "<<students[i].m1 + students[i].m2 + students[i].m3
                      <<"\n";

                std::cout <<"\nDetails Fetched Sucessfully!\n";
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout <<"Details not found!\n";
        }
    }
}

void update (Student students[] ,int &n) {
    int pos;

    if (n == 0) {
        std::cout <<"List is empty! Cannot update!\n";
        return;
    } else {
        std::cout <<"Enter position to update details : ";
        std::cin >>pos;

        if (pos < 0 || pos >= n) {
            std::cout <<"Invalid Position!\n";
            return;
        } else {
            std::cout <<"\nCurrent Details : \n";

            std::cout <<"Roll No : "<<students[pos].rollNo
                      <<" | Name : "<<students[pos].name
                      <<" | Department : "<<students[pos].dept
                      <<" | Gender : "<<students[pos].gender
                      <<" | Total Marks : "<<students[pos].m1 + students[pos].m2 + students[pos].m3
                      <<"\n";

            std::cout <<"\nEnter new details : \n";

            std::cout <<"Enter Roll No : ";
            std::cin >>students[pos].rollNo;

            std::cin.ignore();

            std::cout <<"Enter Name : ";
            std::getline(std::cin, students[pos].name);

            std::cout <<"Enter Gender (M/F) : ";
            std::cin >>students[pos].gender;

            std::cin.ignore();

            std::cout <<"Enter Department : ";
            std::getline(std::cin , students[pos].dept);

            std::cout <<"Enter marks in subject 1 : ";
            std::cin >>students[pos].m1;

            std::cout <<"Enter marks in subject 2 : ";
            std::cin >>students[pos].m2;

            std::cout <<"Enter marks in subject 3 : ";
            std::cin >>students[pos].m3;

            std::cout <<"Details Updated!\n";
        }
    }
}

void count (int n) {
    std::cout <<"Number of students : "<<n<<"\n";
}

int main () {
    Student students[10];
    int n = 0;
    int choice;
    char exit = 'y';

    do {
        std::cout <<"\n--- |Student Details| ---\n";
        std::cout <<"[1].Insert details at beginning\n";
        std::cout <<"[2].Insert details at ending\n";
        std::cout <<"[3].Insert details at position\n";
        std::cout <<"[4].Delete details at beginning\n";
        std::cout <<"[5].Delete details at ending\n";
        std::cout <<"[6].Delete details at position\n";
        std::cout <<"[7].Display details\n";
        std::cout <<"[8].Search details\n";
        std::cout <<"[9].Update details\n";
        std::cout <<"[10].Count students\n";
        std::cout <<"[11].Exit\n";
        std::cout <<"Enter choice (1 - 10) : ";
        std::cin >>choice;

        switch (choice) {
            case 1: insertBegin(students, n);
            break;

            case 2: insertEnd(students, n);
            break;;

            case 3: insertPosition(students, n);
            break;

            case 4: deleteBegin(students , n);
            break;

            case 5: deleteEnd(students, n);
            break;

            case 6: deletePosition(students, n);
            break;

            case 7: display(students, n);
            break;

            case 8: search(students, n);
            break;

            case 9: update(students, n);
            break;

            case 10: count(n);
            break;

            case 11:
            std::cout <<"Do you want to exit? (y/n) : ";
            std::cin >>exit;

            if (exit == 'y' || exit == 'Y') {
                std::cout <<"Program Exited Sucessfully!";
                break;
            } else {
                choice = 0;
            }

            default:
            std::cout <<"Invalid choice!\n";
            break;
        }

    } while (choice != 11);

    return 0;
}
