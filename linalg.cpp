#include<iostream>
#include<typeinfo>
#include "linalg.hpp"

int main(){
    Compute::Matrix<int> x = Compute::Matrix<int>(3, 3);
    x.fill(3);
    x.set(0, 0, 1);
    x.set(1, 2, 5);
    x.set(2, 1, 2);
    x.exp(3);
    std::cout << x << std::endl << x.det() << std::endl;
}