#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>
using namespace std;

class Array {
    int* data;
    int size;

public:
    Array();
    ~Array();

    void input();
    void output() const;

    int getSize() const;
    int getItem(int index) const;

    int find(int value) const;

    void sortIncreasing();
    void sortDecreasing();
};

#endif