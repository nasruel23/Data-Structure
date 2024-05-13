#include <iostream>
#include <vector>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string nim; // NIM 10 digit (tipe data string)
    float nilai;
};

// Kelas HashTable
class HashTable {
private:
    static const int size = 10; // Ukuran tabel hash
    vector<Mahasiswa> table[size];

    // Fungsi hash sederhana
    int hashFunction(const string &nim) {
        int sum = 0;
        for (char c : nim) {
            sum += c;
        }
        return sum % size;
    }

public:
    // Menambahkan data mahasiswa ke tabel hash
    void tambahData(const string &nim, float nilai) {
        Mahasiswa mhs;
        mhs.nim = nim;
        mhs.nilai = nilai;
        int index = hashFunction(nim);
        table[index].push_back(mhs);
    }

    // Menghapus data mahasiswa dari tabel hash berdasarkan NIM
    void hapusData(const string &nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Mencari data mahasiswa berdasarkan NIM
    void cariNIM(const string &nim) {
        int index = hashFunction(nim);
        for (const auto &mhs : table[index]) {
            if (mhs.nim == nim) {
                cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Mencari data mahasiswa berdasarkan nilai (80-90)
    void cariNilai() {
        cout << "Data mahasiswa dengan nilai antara 80-90:" << endl;
        for (int i = 0; i < size; ++i) {
            for (const auto &mhs : table[i]) {
                if (mhs.nilai >= 80 && mhs.nilai <= 90) {
                    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice;
    do {
        cout << endl;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "OPSI MENU" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari NIM data mahasiswa" << endl;
        cout << "4. Cari NILAI data mahasiswa (80-90)" << endl;
        cout << "5. Keluar/Exit" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nim;
                float nilai;
                cout << "Masukkan NIM (10 digit): ";
                cin >> nim;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                hashTable.tambahData(nim, nilai);
                break;
            }
            case 2: {
                string nim;
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                cout << "Data mahasiswa dengan NIM " << nim << " telah berhasil dihapus." << endl;
                break;
            }
            case 3: {
                string nim;
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> nim;
                hashTable.cariNIM(nim);
                break;
            }
            case 4: {
                hashTable.cariNilai();
                break;
            }
            case 5: {
                cout << "Program telah selesai. Terimakasih!" << endl;
                break;
            }
            default:
                cout << "Pilihan Anda salah. Silakan coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}