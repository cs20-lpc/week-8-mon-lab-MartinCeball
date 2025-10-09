#include <string>       // Required for throwing string exceptions
#include <stdexcept>    // This can be removed or left

using namespace std;

template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    maxSize = i;
    buffer = new T[maxSize];
    this->length = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        delete[] buffer;
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] buffer;
}

template <typename T>
void ArrayStack<T>::clear() {
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->buffer = new T[this->maxSize];

    for (int i = 0; i < this->length; i++) {
        this->buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) {
        // Throw a string exception as per instructions
        throw string("Error: Cannot peek from an empty stack.");
    }
    return buffer[this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if (isEmpty()) {
        // Throw a string exception as per instructions
        throw string("Error: Cannot pop from an empty stack.");
    }
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    if (isFull()) {
        // Throw a string exception as per instructions
        throw string("Error: Cannot push to a full stack.");
    }
    buffer[this->length] = elem;
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length < 2) {
        return; // Nothing to rotate
    }

    // Per instructions, use RIGHT/LEFT from the Stack<T> scope
    if (dir == Stack<T>::RIGHT) {
        // Move bottom element to the top
        T bottomElement = buffer[0];
        for (int i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }
        buffer[this->length - 1] = bottomElement;
    }
    else { // Assumes LEFT
        // Move top element to the bottom
        T topElement = buffer[this->length - 1];
        for (int i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = topElement;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        outStream << "---- STACK (size " << myObj.getLength() << "/" << myObj.getMaxSize() << ") ----\n";
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top ->\t" : "\t")
                      << myObj.buffer[i] << "\n";
        }
        outStream << "---------------------------\n";
    }
    return outStream;
}
