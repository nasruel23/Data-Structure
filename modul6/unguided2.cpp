#include <iostream>
#include <stack>

using namespace std;

void reverseSentence(string str) {
  stack<char> s; // Deklarasi stack untuk menyimpan karakter kalimat

  for (char ch : str) { // Memasukkan karakter kalimat ke stack
    s.push(ch);
  }

  while (!s.empty()) { // Mengeluarkan karakter dari stack dan menampilkan secara terbalik
    cout << s.top();
    s.pop();
  }
}

int main() {
  string input;
  int pilihan;

  do {
    cout << "\nMenu Program Pembalik Kalimat:\n";
    cout << "1. Masukkan Kalimat\n";
    cout << "2. Exit\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    if (pilihan == 1) {
      cout << "Masukkan kalimat (minimal 3 kata): ";
      cin.ignore(); // Mengabaikan newline character
      getline(cin, input);

      // Hitung jumlah kata dalam kalimat
      int wordCount = 1;
      for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
          wordCount++;
        }
      }

      // Periksa apakah kalimat memiliki minimal 3 kata
      if (wordCount < 3) {
        cout << "Maaf, kalimat harus minimal 3 kata.\n";
        continue;
      }

      reverseSentence(input);
      cout << endl;
    } else if (pilihan == 2) {
      break;
    } else {
      cout << "Pilihan tidak valid. Silakan masukkan 1 atau 2.\n";
    }
  } while (true);

  return 0;
}