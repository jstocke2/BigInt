# BigInt

A C++ library for performing arithmetic operations on arbitrarily large integers that exceed the range of standard integer types.

## Description

This project implements a `BigInt` class that allows efficient manipulation of very large integers. It's based on Dr. J Maletic's class notes and provides a complete ADT (Abstract Data Type) implementation with support for all standard arithmetic operations.

## Features

- **Arbitrary precision arithmetic**: Handle integers of any size
- **Standard operators**: Addition, subtraction, multiplication, division
- **Comparison operators**: Equality, inequality, less than, greater than, etc.
- **Input/output support**: Stream operators for easy I/O
- **Array-based storage**: Efficient internal representation

## Building

### Prerequisites
- C++ compiler (C++11 or later)
- Standard C++ library

### Compilation

```bash
g++ -o bigint_demo bigint.cpp main.cpp
```

Or with additional flags:

```bash
g++ -Wall -Wextra -std=c++11 -o bigint_demo bigint.cpp main.cpp
```

## Usage

```cpp
#include "BigInt.h"

int main() {
    BigInt a("12345678901234567890");
    BigInt b("98765432109876543210");
    
    BigInt sum = a + b;
    BigInt product = a * b;
    
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    
    return 0;
}
```

## Implementation Details

- **Internal Representation**: Array-based digit storage
- **Base**: Typically 10 (decimal) or power of 10 for efficiency
- **Sign Handling**: Separate tracking for positive/negative values

## License

No license specified. See LICENSE file if present.

## Author

Based on Dr. J Maletic's class notes (Kent State University)

---

**Last Updated**: 2015
