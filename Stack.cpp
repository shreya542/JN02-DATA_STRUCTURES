#include <iostream>
#define size 10
using namespace std;

class Stack {
    int data[size];
    int top;

public: 
    Stack() {
        top = 0; 
    }

    void push(int element) {
        if (isFull() == 1)
            cout << "stack is full";
        else
            data[top++] = element;
    }

    int pop() {
        if (isEmpty() == 1)
            return -1;
        else
            return data[--top]; 
    }

    int isEmpty() {
        if (top == 0)
            return 1;
        else
            return 0;
    }

    int isFull() {
        if (top == size)
            return 1;
        else
            return 0;
    }

    int peek() {
        if (isEmpty() == 1)
            return -1;
        else
            return data[top - 1]; 
    }
};

int main() {
    cout << "Implementation of stack";
    Stack st;
    st.push(10);
    st.push(40);
    st.push(70);
    st.push(30);
    cout << "\nstack is empty?:  " << st.isEmpty();
    cout << "\nstack is full?:  " << st.isFull();
    cout << "\nelement at top position?:  " << st.peek();
    cout << "\nelement removed from stack:  " << st.pop();
    cout << "\nelement at top position?:  " << st.peek();

    return 0;
}




//Code by: Shreyasi Bagul