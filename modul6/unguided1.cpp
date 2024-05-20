#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string str) {
  // Konversi semua huruf menjadi huruf kecil
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }

  // Buat stack untuk menampung karakter kalimat
  stack<char> s;

  // Masukkan karakter kalimat ke stack
  for (int i = 0; i < str.length(); i++) {
    s.push(str[i]);
  }

  // Bandingkan karakter dari depan dan belakang kalimat
  for (int i = 0; i < str.length() / 2; i++) {
    if (str[i] != s.top()) {
      return false;
    }
    s.pop();
  }

  return true;
}

int main() {
  string input;
  int pilihan;

  do {
    cout << "\nMenu Program Pemeriksa Kalimat Palindrom:\n";
    cout << "1. Masukkan Kata/Kalimat\n";
    cout << "2. Exit\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    if (pilihan == 1) {
      cout << "Masukkan kata/kalimat: ";
      cin.ignore(); // Mengabaikan newline character
      getline(cin, input);

      if (isPalindrome(input)) {
        cout << input << " adalah kalimat palindrom.\n";
      } else {
        cout << input << " bukan kalimat palindrom.\n";
      }
    } else if (pilihan == 2) {
      break;
    } else {
      cout << "Pilihan tidak valid. Silakan masukkan 1 atau 2.\n";
    }
  } while (true);

  return 0;
}