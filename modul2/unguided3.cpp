#include <iostream>
using namespace std;
int min, max;
double rata2, total;
int isi[10];

int main(){
  // deklarasi
  int min, max;
  double rata2, total;

  // setting jumlah nilai array
  int isi[10];
  
  // input user
  cout << "Input 10 Nilai Array" << endl;
  for (int i=0; i < 10; i++){
    cout << "array ke- " << i+1 << " : ";
    cin >> isi[i];
  }
  cout << endl;
  // tampilan
  cout << "Array: ";
  for (int i=0; i < 10; i++){
    cout << isi[i] << " ";
  }
  cout << endl;

  max=isi[0];
  for (int i=0; i < 10; i++){
    if (max < isi[i]){
      max = isi[i];
    }
  }
  cout << "Nilai Maksimum: " << max << endl;

  min=isi[0];
  for (int i=0; i < 10; i++){
    if (min > isi[i]){
      min = isi[i];
    }
  }
  cout << "Nilai Minimum: " << min << endl;

  for (int i=0; i < 10; i++){
    total += isi[i];
    rata2 = total/10;
  }
  cout << "Rata-rata dari Array adalah " << rata2;
  return 0;
}