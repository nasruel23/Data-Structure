#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Deklarasi (nama sebagai key, harga sebagai value)
    map<string, double> menu = {
        {"Nasi Goreng", 20000},
        {"Mie Ayam", 18000},
        {"Bakso", 15000},
        {"Es Teh", 5000},
        {"Jus Alpukat", 8000},
    };

    // Menampilkan
    cout << "============================" << endl;
    cout << "DAFTAR MENU\n";

    // Iterasi dengan iterator
    for (auto it = menu.begin(); it != menu.end(); ++it) {
    cout << it->first << " - Rp" << it->second << endl;
    }
    
    return 0;
}