#include <iostream>
using namespace std;
// Main program
int main () {
    char op;
    float num1, num2;

    // It allows user to enter operator i.e. +, -, *, /
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;

    // It allows user to enter the operands
    cout << "Masukkan dua angka: ";
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
        // If user enter +
        case '+':
            cout << "Hasil penjumlahan: " << num1 + num2;
            break;
        // If user enter -
        case '-':
            cout << "Hasil pengurangan: " << num1 - num2;
            break;
        // If user enter *
        case '*':
            cout << "Hasil perkalian: " << num1 * num2;
            break;
        // If user enter /
        case '/':
        if (num2 !=0)
            cout << "Hasil pembagian: " << num1 / num2;
        else 
            cout << "Error! Tidak dapat melakukan pembagian dengan nol!";
            break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}