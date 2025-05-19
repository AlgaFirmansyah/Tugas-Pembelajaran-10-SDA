#include <iostream>
using namespace std;
 
// Buat function dengan algoritma selection sort
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    // Tukar posisi element terkecil dengan element pada indeks i
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}
 
int main() {
  int i, n;
 
  // Baca angka input dari user
  cout << "Input jumlah element array: ";
  cin >> n;
  cout << endl;
 
  int arr[n];
  cout <<  "Input "<< n << " angka (dipisah dengan enter): ";
  cout << endl;
 
  for(i = 0; i < n; i++){
    cout << "Angka ke-" << i+1 <<": ";
    cin >> arr[i];
  }
 
  // Urutkan array dengan algoritma selection sort
  selectionSort(arr, n);
 
  // Tampilan hasil pengurutan
  cout << endl;
  cout << "Array setelah diurutkan: ";
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
 
  return 0;
}
