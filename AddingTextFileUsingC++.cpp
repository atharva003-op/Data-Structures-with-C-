#include <iostream>
#include <fstream>

int main() {
    std::ofstream out("student.txt", std::ios::app);

    int roll;
    std::string name;

    std::cout << "Enter Roll: ";
    std::cin >> roll;

    std::cout << "Enter Name: ";
    std::cin >> name;

    out <<"Roll No : "<< roll << " | Name : " << name << std::endl;
    out.close();

    std::ifstream in("student.txt");
    std::string line;

    std::cout << "\nStored Data:\n";

    while (getline(in, line)) {
        std::cout << line << std::endl;
    }

    in.close();

    return 0;
}
