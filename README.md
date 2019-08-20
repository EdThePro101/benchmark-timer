# benchmark-timer

This a simple implementation of a benchmark timer in C++

## Introduction

When ever I want to use a particular part of a library, or if I am concerned about the performance of my code, I normally would write a class (like the one in [timer.h](./src/timer.h)). This is quite irritating because I have to do the same thing over and over again.

I decided to share the code and make it easily available so that I don't have to write it over again.

## Usage

It is quite easy to use the class. Simply include the header `src/timer.h`.

```cpp
#include "src/timer.h"
```

Then when ever you want to benchmark a piece of code, surround the code in a block and instantiate the class:

```cpp
// tests/for-loop.cpp
#include "src/timer.h"

int main() {
    {
        Timer t;

        int sum = 0;

        for (int i = 0, size = (int)(sizeof(array) / sizeof(array[0])); i < size; i += sizeof(array[0])) {
            sum += *(array + i);
        }
    }

    return 0;
}
```

## The `tests` folder

The `tests` folder is very bare. However, if you would like to submit tests, feel free to do so!

The test file should looks similar to [for-loop.cpp](./tests/for-loop.cpp).

## License

This project is license under the MIT License. Please refer to the [LICENSE](LICENSE) file for more info.
