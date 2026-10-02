#include <iostream>

int main () {
    int n;
    std::cout <<"Enter the number of elements : ";
    std::cin >>n;

    int arr[n];
    std::cout <<"Enter elements : \n";
    for (int i = 0; i < n; i++) {
        std::cout <<"Enter element "<<i+1<<" : ";
        std::cin >>arr[i];
    }

    std::cout <<"\nArray : ";
    for (int i = 0; i < n; i++) {
        std::cout <<arr[i]<<" | ";
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    std::cout <<"\nReversed Array : ";
    for (int i = 0; i < n; i++) {
        std::cout <<arr[i]<<" | ";
    }
    return 0;
}
