// Own headers
#include <DynamicLib.h>
// System headers
#include <iostream>

int min (const int a, const int b) {
    int result = (a < b) ? a : b;
    std::cout << "Dynamic Lib <min> function:" << std::endl 
              << "From given: " << a << " and " << b << ", smaller is " << result << std::endl; 
    return result;
}