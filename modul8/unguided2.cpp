#include <iostream>
#include <string>

using namespace std;

int main() {
  string kata;
  int jumlahVokal = 0;

  cout << "Masukkan kata/kalimat: ";
  getline(cin, kata);

  for (char huruf : kata) {
    if (tolower(huruf) == 'a' || tolower(huruf) == 'e' || tolower(huruf) == 'i' ||
        tolower(huruf) == 'o' || tolower(huruf) == 'u') {
      jumlahVokal++;
    }
  }

  cout << "\nJumlah huruf vokal dalam kata/kalimat '" << kata << "' adalah: " << jumlahVokal << endl;

  return 0;
}