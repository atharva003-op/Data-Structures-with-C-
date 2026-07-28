#include <iostream>

int main () {
    int n;
    std::cout <<"Enter number of elements to enter : ";
    std::cin >>n;

    int arr[n];
    std::cout <<"Array elements as follows : \n";
    for (int i = 0; i < n; i++) {
        std::cout <<"Enter element "<<i+1<<" : ";
        std::cin >>arr[i];
    }

    std::cout <<"Array : ";
    for (int i = 0; i < n; i++) {
        std::cout <<arr[i]<<" ";
    }

    int find;
    std::cout <<"\nEnter an element to find in array : ";
    std::cin >>find;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == find) {
            found = true;
            std::cout <<"Element found at index "<<i<<std::endl;
            break;
        }
    }

    if (!found) {
        std::cout <<"Element not found!";
    }
    return 0;
}
