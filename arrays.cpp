#include <iostream>
// #include <string>

int main () {
    int n;

    std::cout <<"Enter size : ";
    std::cin >>n;

    int arr[n];
    std::cout <<"Enter elements : \n";
    for (int i = 0; i < n; i++) {
        std::cin >>arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    std::cout <<"\nArray is : \n";
    for (int i = 0; i < n; i++) {
        std::cout <<arr[i]<<" ";
    }

    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    std::cout <<"\nSum of array = "<<sum;
    std::cout <<"\nAverage : "<<(double)sum/n;
    std::cout <<"\nMaximum element : "<<max;
    std::cout <<"\nMinimum element : "<<min;

    return 0;
}
