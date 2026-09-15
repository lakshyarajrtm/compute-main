#include "linalg.hpp"

int main(){
    Compute::Matrix<float> x = Compute::Matrix<float>(3, 2);
    x.fill(1.0f);
    auto y = x + -2.2f * x;
    y.print();
}