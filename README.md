# Compute

A header-only, lightweight C++ numerical computing library designed for computational science, machine learning, and high-performance applications.

## Features

* **Header-Only:** Easy integration—just drop the header into your project and `#include "compute.hpp"`.
* **Templated Architecture:** Supports custom numeric types (`float`, `double`, etc.).
* **Intuitive Operators:** Clean syntax for matrix arithmetic, scalar multiplication, and indexing.
* **Modern C++:** Built using modern C++ standards for safety and performance.

## Getting Started

### Prerequisites
* A C++ compiler supporting C++17 or later (GCC, Clang, MSVC).

### Installation
Simply copy `compute.hpp` into your project's include directory.

### Quick Example

```cpp
#include "compute.hpp"
#include <iostream>

int main() {
    // Create a 3x2 matrix initialized with zeros, then fill it
    Compute::Matrix<float> x(3, 2);
    x.fill(1.0f);

    // Perform operations
    auto y = x + -2.2f * x;
    
    // Print the result
    std::cout << y << std::endl;

    return 0;
}