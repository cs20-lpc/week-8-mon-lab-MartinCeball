#include <iostream>
#include <string>
#include "ArrayStack.hpp"

using namespace std;

// Required function template to test the rotate method
template <typename T>
void testRotate(ArrayStack<T>& s) {
    cout << "\n--- Testing Rotation ---\n";
    cout << "Original Stack:" << endl;
    cout << s;

    cout << "Rotating RIGHT (bottom element moves to top)..." << endl;
    s.rotate(Stack<T>::RIGHT);
    cout << s;

    cout << "Rotating RIGHT again..." << endl;
    s.rotate(Stack<T>::RIGHT);
    cout << s;
    
    cout << "Rotating LEFT (top element moves to bottom)..." << endl;
    s.rotate(Stack<T>::LEFT);
    cout << s;

    cout << "Rotating LEFT again (back to original state)..." << endl;
    s.rotate(Stack<T>::LEFT);
    cout << s;
    cout << "--- End Rotation Test ---\n";
}

int main() {
    cout << "========= ArrayStack Test Driver =========\n" << endl;

    // ===============================================
    // TEST 1: INTEGER STACK
    // ===============================================
    cout << "## TEST 1: INTEGER STACK ##\n" << endl;
    ArrayStack<int> intStack(5);
    cout << "Created an integer stack with max size 5." << endl;
    
    // Test empty operations
    cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    cout << intStack;

    cout << "\nAttempting to pop from empty stack..." << endl;
    try {
        intStack.pop();
    } catch (const string& e) {
        cout << "CAUGHT EXCEPTION: " << e << endl;
    }

    cout << "Attempting to peek at empty stack..." << endl;
    try {
        intStack.peek();
    } catch (const string& e) {
        cout << "CAUGHT EXCEPTION: " << e << endl;
    }

    // Test pushing
    cout << "\nPushing elements 10, 20, 30, 40, 50..." << endl;
    for (int i = 1; i <= 5; ++i) {
        intStack.push(i * 10);
        cout << "Pushed " << intStack.peek() << ". Length is now " << intStack.getLength() << endl;
    }

    // Test full operations
    cout << "\nIs stack full? " << (intStack.isFull() ? "Yes" : "No") << endl;
    cout << intStack;
    
    cout << "Attempting to push to full stack..." << endl;
    try {
        intStack.push(999);
    } catch (const string& e) {
        cout << "CAUGHT EXCEPTION: " << e << endl;
    }

    // Test pop
    cout << "\nPopping top element..." << endl;
    cout << "Top was: " << intStack.peek() << endl;
    intStack.pop();
    cout << "New top is: " << intStack.peek() << endl;
    cout << intStack;

    // Test rotation
    testRotate(intStack);

    // Test clear
    cout << "\nClearing the stack..." << endl;
    intStack.clear();
    cout << "Is stack empty now? " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    cout << intStack;
    

    // ===============================================
    // TEST 2: CHAR STACK & COPY SEMANTICS
    // ===============================================
    cout << "\n\n## TEST 2: CHAR STACK & COPY SEMANTICS ##\n" << endl;
    ArrayStack<char> charStack(4);
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    
    cout << "Original Char Stack:" << endl;
    cout << charStack;

    // Test copy constructor
    cout << "Testing Copy Constructor (stackB = stackA)..." << endl;
    ArrayStack<char> copyStack = charStack;
    cout << "Original:" << endl << charStack;
    cout << "Copy:" << endl << copyStack;
    cout << "Popping from ORIGINAL stack..." << endl;
    charStack.pop();
    cout << "Original after pop:" << endl << charStack;
    cout << "Copy (should be unchanged):" << endl << copyStack;

    // Test assignment operator
    cout << "\nTesting Assignment Operator (stackC = stackB)..." << endl;
    ArrayStack<char> assignStack(10); // Different size to test copy
    assignStack.push('Z');
    assignStack = copyStack;
    cout << "Source (the copy):" << endl << copyStack;
    cout << "Destination (assignStack):" << endl << assignStack;
    cout << "Popping from SOURCE stack..." << endl;
    copyStack.pop();
    cout << "Source after pop:" << endl << copyStack;
    cout << "Destination (should be unchanged):" << endl << assignStack;

    // Test rotation on the assigned stack
    testRotate(assignStack);

    cout << "\n========= Testing Complete =========\n" << endl;

    return 0;
}
