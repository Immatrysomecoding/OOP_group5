#include "Array.hpp"

Array::Array() {
    data = nullptr;
    size = 0;
}

Array::~Array() {
    delete[] data;
}

void Array::input() {
    cout << "Enter array size: ";
    cin >> size;
    while (size <= 0) {
        cout << "  Error: size must be > 0. Try again: ";
        cin >> size;
    }
    delete[] data;
    data = new int[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "  [" << i << "]: ";
        cin >> data[i];
    }
}

void Array::output() const {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]";
}

int Array::getSize() const {
    return size;
}

int Array::getItem(int index) const {
    if (index < 0 || index >= size) {
        cout << "  Error: index " << index << " out of range.\n";
        return -1;
    }
    return data[index];
}

int Array::find(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) return i;
    }
    return -1;   // not found
}

void Array::sortIncreasing() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}

void Array::sortDecreasing() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] < data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}