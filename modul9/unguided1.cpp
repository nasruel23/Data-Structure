#include <iostream>
#include <iomanip>
using namespace std;

// NIM: 2311102044
int nim_2311102044 = 2311102044;

// Maksimal jumlah simpul (kota)
const int MAX = 10;

void displayGraph(int graph[MAX][MAX], string cities[MAX], int n) {
    cout << "\n\t";
    for (int i = 0; i < n; ++i) {
        cout << setw(10) << cities[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(10) << cities[i] << "\t";
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INT_MAX) {
                cout << setw(10) << "INF" << "\t";
            } else {
                cout << setw(10) << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    // Array untuk menyimpan nama-nama simpul (kota)
    string cities[MAX];
    cout << "Silakan masukan nama simpul\n";
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> cities[i];
    }

    // Array untuk menyimpan graf dalam bentuk matriks ketetanggaan
    int graph[MAX][MAX];

    // Inisialisasi matriks ketetanggaan dengan nilai tak hingga (INT_MAX)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }

    cout << "Silakan masukan bobot antar simpul\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cities[i] << "--> " << cities[j] << ": ";
            int weight;
            cin >> weight;
            graph[i][j] = weight;
        }
    }

    displayGraph(graph, cities, n);

    return 0;
}