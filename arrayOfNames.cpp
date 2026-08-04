#include <iostream>
#include <string>

int main () {
    int n;
    std::cout <<"Enter number of names : ";
    std::cin >>n;

    std::string name[n];
    std::cout <<"Enter names : \n";
    for (int i = 0; i < n; i++) {
        std::cout <<"Enter name "<<i+1<<" : ";
        std::cin >>name[i];
    }

    std::cout <<n<<" Names as follows : \n";
    for (int i = 0; i < n; i++) {
        std::cout <<name[i]<<"\n";
    }

    std::cout <<"Names in color : \n";
    for (int i = 0; i < n; i++) {
        std::cout <<"\033[34m"<<name[i]<<"\n\033[0m";
    }
}
