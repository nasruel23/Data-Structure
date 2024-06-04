#include <iostream>
using namespace std;

int main() {
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]); // Ukuran array
  cout << "Data array : ";
  for (int i = 0; i < 10; i++) {
    cout << data[i] << " ";
  }
  cout << endl;

  int angkaDicari;
  cout << "\nMasukkan angka yang ingin dicari: ";
  cin >> angkaDicari;
  int kemunculan = 0;

  // Algoritma Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == angkaDicari) {
      kemunculan++;
    }
  }

  // Output hasil pencarian
  if (kemunculan > 0) {
    cout << "Angka " << angkaDicari << " muncul sebanyak " << kemunculan << " kali dalam array." << endl;
  } else {
    cout << "Angka " << angkaDicari << " tidak ditemukan dalam array." << endl;
  }

  return 0;
}