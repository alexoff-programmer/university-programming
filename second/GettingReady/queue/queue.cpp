// Попытка написать свою очередь

#include <iostream>

struct Node {
    int value;
    Node* next;
};

class Queue {
    Node* top = nullptr;
    Node* end = nullptr;
    int len = 0;

public:
    Queue() {}

    void put(int value) {
        Node* pItem = new Node{ value, nullptr };
        if (len == 0) {
            top = end = pItem;
        }
        else {
            end->next = pItem;
            end = pItem;
        }
        len++;
    }

    int pop() {
        if (len == 0) {
            return 0;
        }

        Node* temp = top;
        int res = top->value;
        top = top->next;

        delete temp;
        len--;

        if (len == 0) {
            end = nullptr;
        }
        return res;
    }

    int peek() {
        return top->value;
    }

    void show() {
        if (len == 0) {
            return;
        }

        int value;

        for (int i = 0; i < len; i++) {
            value = pop();
            std::cout << value << " ";
            put(value);
        }
    }

    bool isEmpty() {
        return !len;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};


int main()
{
    Queue q;
    q.put(5);
    std::cout << q.pop();

    for (int i = 0; i < 10; i++) {
        q.put(i);
    }
    q.show();
    q.clear();
    q.put(5);
    q.show();
}
