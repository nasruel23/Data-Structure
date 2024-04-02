#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa{
    string nama;
    int usia;
    Mahasiswa *next;
};

Mahasiswa *head = nullptr;

void insertDepan(string nama, int usia){
    Mahasiswa *node = new Mahasiswa;
    node->nama = nama;
    node->usia = usia;
    node->next = head;
    head = node;
}

void insertBelakang(string nama, int usia){
    Mahasiswa *node = new Mahasiswa;
    node->nama = nama;
    node->usia = usia;
    node->next = nullptr;
    if (head == nullptr){
        head = node;
        return;
    }

    Mahasiswa *curr = head;
    while (curr->next !=nullptr){
        curr = curr->next;
    }
    curr->next = node;
}

void insertTengah(string nama, int usia, int pos){
    Mahasiswa *node = new Mahasiswa;
    node->nama = nama;
    node->usia = usia;
    Mahasiswa *curr = head;
    for (int i=0; i < pos - 1; i++){
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
}

void hapusData(string nama){
    if (head == nullptr){
        return;
    }
    if (head->nama == nama){
        Mahasiswa *node = head;
        head = head->next;
        delete node;
        return;
    }
    Mahasiswa *curr = head;
    while (curr->next != nullptr && curr->next->nama != nama){
        curr = curr->next;
    }
    if (curr->next != nullptr){
        Mahasiswa *node = curr->next;
        curr->next = curr->next->next;
        delete node;
    }
}

void ubahData(string nama, int usia){
    if (head == nullptr){
        cout << "Tidak ada data yang bisa diubah" << endl;
        return;
    }
    Mahasiswa *node = head;
    string key;
    cout << "Masukkan nama yang ingin diubah: ";
    cin >> key;
    while (node != nullptr){
        if (node->nama == key){
            cout << "Masukkan nama baru: ";
            cin >> node->nama;
            cout << "Masukkan usia baru: ";
            cin >> node->usia;
            return;
        }
        node = node->next;
    }
    cout << "Data berhasil diubah" << endl;
}

void tampilkanData(){
    Mahasiswa *curr = head;
    while (curr != nullptr){
        cout << curr->nama << " " << curr->usia << endl;
        curr = curr->next;
    }
}

int main(){
    int pilihan, usia, posisi;
    string nama;

    do
    {
        // Tampilkan menu
        cout << "Menu:" << endl;
        cout << "1. Insert Depan" << endl;
        cout << "2. Insert Belakang" << endl;
        cout << "3. Insert Tengah" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Ubah Data" << endl;
        cout << "6. Tampilkan Data" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan){
        case 1: 
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan usia: ";
        cin >> usia;
        insertDepan(nama, usia);
        break;
        case 2:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan usia: ";
        cin >> usia;
        insertBelakang(nama, usia);
        break;
        case 3:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan usia: ";
        cin >> usia;
        cout << "Masukkan posisi: ";
        cin >> posisi;
        insertTengah(nama, usia, posisi);
        break;
        case 4:
        cout << "Masukkan nama: ";
        cin >> nama;
        hapusData(nama);
        break;
        case 5:
        ubahData(nama, usia);
        break;
        case 6:
        tampilkanData();
        break;
        case 7:
        cout << "Terima kasih." << endl;
        break;
        default:
        cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 7);

    return 0;
}