#include <iostream>
#include <string>

using namespace std;

bool binarySearch(string kata, char cari, int awal, int akhir) {
  if (awal > akhir) return false;
  int tengah = (awal + akhir) / 2;
  if (kata[tengah] == cari) {
    cout << "\nHuruf '" << cari << "' ditemukan pada indeks ke-" << tengah << endl;
    return true;
  } else if (kata[tengah] < cari) {
    return binarySearch(kata, cari, tengah + 1, akhir);
  } else {
    return binarySearch(kata, cari, awal, tengah - 1);
  }
}

bool selectionSort(string& kata) {
  if (kata.empty()) return false;
  for (int i = 0; i < kata.size() - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < kata.size(); j++) {
      if (kata[j] < kata[minIndex]) {
        minIndex = j;
      }
    }
    swap(kata[i], kata[minIndex]);
  }
  return true;
}

int main() {
  string kata;
  char cari;
  cout << "Masukkan kata/kalimat: ";
  getline(cin, kata);
  selectionSort(kata);
  cout << "Kata/kalimat setelah diurutkan: " << kata << endl;
  bool found = false;

  do {
    cout << "\nMasukkan huruf yang ingin dicari: ";
    cin >> cari;
    found = binarySearch(kata, cari, 0, kata.size() - 1);
    if (!found) {
      cout << "\nHuruf '" << cari << "' tidak ditemukan." << endl;
      cout << "\nApakah ingin mencari huruf lain? (Y/T): ";
      char pilihan;
      cin >> pilihan;
      found = (pilihan == 'Y' || pilihan == 'y');
    }
  } while (found);
  return 0;
}
