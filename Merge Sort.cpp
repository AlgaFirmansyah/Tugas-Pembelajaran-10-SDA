#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array
void cetakArray(int arr[], int start, int end) {
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Fungsi untuk menggabungkan dua bagian array yang sudah diurutkan
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Menyalin data ke array kiri dan kanan
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    cout << "\nSekarang kita gabungkan bagian berikut:\n";
    cout << "Bagian kiri  : ";
    for (int x = 0; x < n1; x++) cout << L[x] << " ";
    cout << "\nBagian kanan : ";
    for (int x = 0; x < n2; x++) cout << R[x] << " ";
    cout << endl;

    // Proses penggabungan dengan perbandingan nilai
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Jika ada sisa di kiri
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Jika ada sisa di kanan
    while (j < n2) {
        arr[k++] = R[j++];
    }

    cout << "Hasil setelah digabung dan diurutkan: ";
    cetakArray(arr, left, right);
}

// Fungsi utama merge sort (rekursif)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        cout << "\nMembagi data dari indeks [" << left << " - " << right << "] menjadi dua bagian:\n";
        cout << "Bagian kiri  : ";
        cetakArray(arr, left, mid);
        cout << "Bagian kanan : ";
        cetakArray(arr, mid + 1, right);

        // Lanjutkan pembagian
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan kembali dengan rapi
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    cout << "Berapa banyak angka yang ingin kamu urutkan? ";
    cin >> n;

    int arr[n];
    cout << "Silakan masukkan " << n << " angka satu per satu:\n";
    for (int i = 0; i < n; i++) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nInilah data sebelum diurutkan: ";
    cetakArray(arr, 0, n - 1);

    cout << "\n=== Mulai proses Merge Sort ===\n";
    mergeSort(arr, 0, n - 1);

    cout << "\nAkhirnya, data berhasil diurutkan: ";
    cetakArray(arr, 0, n - 1);

    return 0;
}
