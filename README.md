# ListVector C++20 Program

## Overview
This program is designed to compare the performance of `std::list` and `std::vector` containers in C++ while performing certain operations. The comparison is made by generating a sequence of random numbers, inserting them into either a list or a vector, then removing items from the container. It measures and outputs the time taken for these operations.

The program uses advanced features introduced in C++20 such as concepts and constexpr if.

## Compilation

The program can be compiled using any modern C++ compiler that supports C++20. Here's how you can compile it with g++:

```
c++ -std=c++20 -O3 -o listvector listvector.cpp
```

This will produce an executable named `listvector`.

## Usage

To run the program, you need to provide two command line arguments: sequence_length and number_of_trials. 

- sequence_length: This specifies how many random numbers should be generated and inserted into the container.
- number_of_trials: This specifies how many times the test should be repeated.

Here's an example of how to run it:

```
./listvector 10000 10
```

In this case, the program will generate sequences of 10000 random numbers, perform all operations on them and repeat this process 10 times for both std::list<int> and std::vector<int>. The time taken for each type of container is reported in microseconds.

Please note that larger values of sequence_length or number_of_trials may require more time or memory to complete.
