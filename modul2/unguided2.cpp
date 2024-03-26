#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    cout << "Masukkan elemen ke-1: ";
    cin >> x;
    cout << "Masukkan elemen ke-2: ";
    cin >> y;
    cout << "Masukkan elemen ke-3: ";
    cin >> z;

    int isi[x][y][z];
    cout << "Input array: " << endl;
    for (int a=0; a < x; a++){
        for (int b=0; b < y; b++){
            for (int c=0; c < z; c++){
                cout << "Input Array["<<a<<"]["<<b<<"]["<<c<<"] :";
                cin >> isi[a][b][c];
            }
        }
        cout << endl;
    }

    for (int a=0; a < x; a++){
        for (int b=0; b < y; b++){
            for (int c=0; c < z; c++){
                cout << "Data Array["<<a<<"]["<<b<<"]["<<c<<"] :" << isi[a][b][c] << endl;
            }
        }
    }

    for (int a=0; a < x; a++){
        for (int b=0; b < y; b++){
            for (int c=0; c < z; c++){
                cout << isi[a][b][c];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}