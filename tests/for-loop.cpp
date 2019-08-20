// Copyright (c) 2019 Edwin Pratt
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <iostream>

#include "../src/timer.h"

int main() {
    /*
    This is a test to compare the performance of various for loops against arrays.

    The for loops which will be tested are:

    *   for (int i = 0; i < (int)(sizeof(array) / sizeof(array[0])); i++) {
            sum += array[i];
        }
    
    *   for (int i = 0, size = (int)(sizeof(array) / sizeof(array[0])); i < size; i++) {
            sum += array[i];
        }
    
    *   for (int i = 0, size = (int)(sizeof(array) / sizeof(array[0])); i < size; i += sizeof(array[0])) {
            sum += *(array + i);
        }
    */

   // ===============

    int array[1000];
    for (int i = 0; i < 1000; i++) {
        array[i] = i;
    }

    // ===============

    std::cout << "Test 1: The size is computed every iteration of the loop, and standard array indexing is performed." << std::endl;
    
    {
        Timer t;

        int sum = 0;
        for (int i = 0; i < (int)(sizeof(array) / sizeof(array[0])); i++) {
            sum += array[i];
        }
    }

    std::cout << "\n";

    std::cout << "Test 2: The size is stored in a variable, and standard array indexing is performed." << std::endl;
    
    {
        Timer t;

        int sum = 0;
        for (int i = 0, size = (int)(sizeof(array) / sizeof(array[0])); i < size; i++) {
            sum += array[i];
        }
    }

    std::cout << "\n";

    std::cout << "Test 3: The size is stored in a variable, and the array is indexed as a pointer." << std::endl;
    
    {
        Timer t;

        int sum = 0;
        for (int i = 0, size = (int)(sizeof(array) / sizeof(array[0])); i < size; i += sizeof(array[0])) {
            sum += *(array + i);
        }
    }

    return 0;
}
