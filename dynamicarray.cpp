#include <iostream>

class DynamicCollection {
private:
    int *elements;
    int capacity;
    int count;

public:
    DynamicCollection() : elements(nullptr), capacity(0), count(0) {}

    ~DynamicCollection() {
        delete[] elements;
    }

    void add(int value) {
        if (count >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            int *newElements = new int[newCapacity];
            for (int i = 0; i < count; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
        elements[count++] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= count) {
            std::cerr << "Index out of range\n";
            exit(1);
        }
        return elements[index];
    }

    int& operator[](int index) {
        if (index < 0 || index >= count) {
            std::cerr << "Index out of range\n";
            exit(1);
        }
        return elements[index];
    }

    int size() const {
        return count;
    }
};

int main() {
    DynamicCollection collection;
    for (int i = 0; i < 10; ++i) {
        collection.add(i);
    }
    for (int i = 0; i < collection.size(); ++i) {
        std::cout << collection[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
