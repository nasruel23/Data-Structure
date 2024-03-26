#include <iostream>
using namespace std;

// seting jumlah array
int nomor[10];
int main() {

    // inputan user
    cout << "Input Array (10)" << endl;
    for (int i=0; i < 10; i++) {
        cout << "Array ke " << i+1 << ": ";
        cin >> nomor[i];
    }

    // tampilan data
    cout << "=============================" << endl;
    cout << "Array: ";
    for (int i = 0; i < 10; i++){
        cout << nomor[i] << " ";
    }
    cout << endl;
    
    // seting genap dan ganjil
    cout << "Nomor Genap: ";
    for (int i=0; i < 10; i++){
        if (nomor[i] % 2 == 0) {
            cout << nomor[i] << ", ";
        }
    }
    cout << endl;
    cout << "Nomor Ganjil: ";
    for (int i=0; i < 10; i++){
        if (nomor[i] % 2 != 0){
            cout << nomor[i] << ", ";
        }
    }

    return 0;
}