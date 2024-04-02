#include <iostream>
using namespace std;

float celciusToFahrenheit(float celcius) {
    return (celcius * 9/5) + 32;
}
float fahrenheitToCelcius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    float suhu,  hasil;
    int pilihan;

// Menampilkan menu program
cout << "Mau konversi yang mana?" << endl;
cout << "1. Celcius ke Fahrenheit" << endl;
cout << "2. Fahrenheit ke Celcius" <<endl;
cout << "Pilihan kamu: ";
cin >> pilihan;

cout << "Masukkan nilai suhu: ";
cin >> suhu;

// Proses konversi
switch (pilihan) {
    case 1:
        hasil = celciusToFahrenheit(suhu);
        cout << "Fyi, " << suhu << " derajat Celcius sama dengan " << hasil << " derajat Fahrenheit " << endl;
        break;
    case 2:
        hasil = fahrenheitToCelcius(suhu);
        cout << "Fyi, " << suhu << " derajat Fahrenheit sama dengan " << hasil << " derajat Celcius " << endl;
        break;
    default:
        cout << "Pilihan tidak valid!" << endl;
}

   return 0;
}
