#include <iostream>
using namespace std;

// Implementasi linked list
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* back;
    int count;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    bool isFull() {
        return false; 
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        count++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            count--;
            if (front == nullptr) {
                back = nullptr;
            }
        }
    }

    int countQueue() {
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". " << current->data << endl;
            current = current->next;
            position++;
        }
        if (position == 1) {
            cout << "Antrian kosong" << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}