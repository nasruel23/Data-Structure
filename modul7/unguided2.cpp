#include <iostream>
#include <string>
using namespace std;

// Implementasi linked list
struct Node {
    string nama;
    string nim;
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

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
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
        cout << "Jumlah antrian: " << countQueue() << endl;
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
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
    int choice;
    string nama, nim;

    do {
        cout << "\n";
        cout << "---------------------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Hapus Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Hapus Semua Antrian\n";
        cout << "5. Exit\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                queue.enqueueAntrian(nama, nim);
                break;
            case 2:
                queue.dequeueAntrian();
                break;
            case 3:
                queue.viewQueue();
                break;
            case 4:
                queue.clearQueue();
                cout << "Semua antrian telah dihapus.\n";
                break;
            case 5:
                cout << "Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan masukkan angka 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}
