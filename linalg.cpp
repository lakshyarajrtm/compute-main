#include<iostream>
#include<typeinfo>
#include "linalg.hpp"

int main(){
    Compute::Matrix<float> x = Compute::Matrix<float>(3, 2);
    x.fill(3);
    x.exp(3);
    std::cout << x.det() << std::endl;
}