#include <iostream>
using namespace std;

// Fungsi untuk menukar dua nilai dalam array
void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi partisi: di sini kita memilih pivot dan membagi data jadi dua bagian
int partisi(int arr[], int low, int high, int depth) {
    int pivot = arr[high];  // Kita pakai elemen paling kanan sebagai pivot
    int i = low - 1;

    string indent(depth * 2, ' ');
    cout << indent << "Memilih pivot: " << pivot << endl;

    for (int j = low; j < high; j++) {
        cout << indent << "Bandingkan " << arr[j] << " dengan pivot " << pivot;
        if (arr[j] <= pivot) {
            i++;
            tukar(arr[i], arr[j]);
            cout << " => Tukar " << arr[i] << " dan " << arr[j];
        }
        cout << endl;
    }

    // Tempatkan pivot di posisi yang semestinya
    tukar(arr[i + 1], arr[high]);
    cout << indent << "Letakkan pivot pada posisi yang benar => ";
    for (int k = low; k <= high; k++) cout << arr[k] << " ";
    cout << endl;

    return i + 1;
}

// Fungsi Quick Sort (rekursif)
void quickSort(int arr[], int low, int high, int depth = 0) {
    string indent(depth * 2, ' ');
    if (low < high) {
        cout << indent << "\nQuickSort pada indeks [" << low << " - " << high << "]" << endl;
        int pi = partisi(arr, low, high, depth);

        // Rekursi ke sisi kiri dan kanan dari pivot
        quickSort(arr, low, pi - 1, depth + 1);
        quickSort(arr, pi + 1, high, depth + 1);
    }
}

int main() {
    int n;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan " << n << " nilai:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nData awal: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\nProses Quick Sort:\n";

    quickSort(arr, 0, n - 1);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
