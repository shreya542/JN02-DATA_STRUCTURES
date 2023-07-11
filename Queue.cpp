#include <iostream>
#define Size 20
using namespace std;

class Queue {
    int data[Size];
    int rear, front;

public:
    Queue() {
        front = rear = -1;
    }

    void insert(int element) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
        } else {
            data[++rear] = element;
        }
    }

    int remove() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[front++];
        }
    }

    int isEmpty() {
        if (rear == -1)
            return 1;
        else
            return 0;
    }

    int isFull() {
        if (rear == Size - 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[front + 1];
        }
    }
};

int main() {
    cout << "Queue Implementation" << endl;
    Queue st;
    st.insert(10);
    st.insert(20);
    cout << "Queue is empty? " << st.isEmpty() << endl;
    cout << "Queue is Full? " << st.isFull() << endl;
    cout << "Element is at Position: " << st.peek() << endl;
    cout << "Element removed from the Queue: " << st.remove() << endl;
    cout << "Element removed from the Queue: " << st.remove() << endl;
    cout << "Element removed from the Queue: " << st.remove() << endl;
    cout << "Element is at Position: " << st.peek() << endl;
    return 0;
}
