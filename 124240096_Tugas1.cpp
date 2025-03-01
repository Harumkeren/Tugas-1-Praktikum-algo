#include <iostream>
#include <string>
using namespace std;

struct A
{
    string nama;
    int harga;
}; 
A barang[100];
int jumlahData = 0;

void swap(A &a, A &b) {
    A temp = a;
    a = b;
    b = temp;
}

int partition(int awal, int akhir) {
    int pivot = barang[akhir].harga; 
    int i = awal - 1;

    for (int j = awal; j < akhir; j++) {
        if (int(barang[j].harga) < pivot) {
            i++;
            swap(barang[i], barang[j]);
        }
    }
    swap(barang[i + 1], barang[akhir]);
    return i + 1;
}

void quick_sort(int awal, int akhir) {
    if (awal < akhir) {
        int pivot = partition(awal, akhir);
        quick_sort(awal, pivot - 1);
        quick_sort(pivot + 1, akhir);
    }
}

void sequential_search(int key) {
    bool found = false;
    for (int i = 0; i < jumlahData; i++) {
        if (barang[i].harga == key ) {
            cout << "\nData ditemukan:" << endl;
            cout << "Nama barang\t: " << barang[i].nama << endl;
            cout << "Harga barang\t: " << barang[i].harga << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }  
    
}
void inputData() {
    cout << "Masukkan jumlah data: ";
    cin >> jumlahData;
    for (int i = 0; i < jumlahData; i++) {
        cout << "Masukkan nama barang: ";
        cin >> barang[i].nama;
        cout << "Masukkan harga barang: ";
        cin >> barang[i].harga;
    }
}
void tampilData() {
    cout << "\nData barang:" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "------------\n";
        cout << "Nama: "  << barang[i].nama << "\n";
        cout << "------------\n"; 
        cout << "Harga: " << barang[i].harga << "\n";
        cout << "------------\n";
    }
}
// Bubble Sort = urutin berdasarkan nama 
void urutnama() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (barang[j].nama > barang[j + 1].nama) {
                swap(barang[j], barang[j + 1]);
            }
        }
    }   
}
// Binary Search = nama
void binary_search(string key) {
    int kiri = 0, kanan = jumlahData - 1;
    bool found = false;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (barang[tengah].nama == key) {
            cout << "\nData ditemukan:" << endl;
            cout << "Nama barang\t: " << barang[tengah].nama << endl;
            cout << "\nHarga barang\t: " << barang[tengah].harga << endl;
            found = true;
            break; // langsung keluar jika ketemu
        }
        if (barang[tengah].nama < key) {
            kiri = tengah + 1; // cari ke kanan
        } else {
            kanan = tengah - 1; // cari ke kiri
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }   
}
void menu(){
    int pilih;
    do
    {
        cout << "------------------------------------\n";
        cout << "Selamat datang di Toko Kelontong B-2\n";
        cout << "------------------------------------\n";
        cout << "Menu :\n";
        cout << "1. Input Barang\n";
        cout << "2. Data Barang\n";
        cout << "3. Pencarian Data\n";
        cout << "4. Pengurutan Barang\n";
        cout << "5. Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu : ";cin >> pilih;
        system("cls");
        switch (pilih)
        {
        case 1:
            inputData();
            break;
        case 2:
            tampilData();
            break;
        case 3:
            int pilihsearch;
            cout << "----------------------------------------\n";
            cout << "Menu Pencarian\n";
            cout << "1. Berdasarkan nama  (Binary Search)\n";
            cout << "2. Berdasarkan harga (Sequential Search)\n";
            cout << "----------------------------------------\n";
            cout << "Pilih menu : ";cin >> pilihsearch;
            cout << " ";
            if (pilihsearch == 1) { // Binary Search by nama
                string namaKey;
                cout << "Masukkan nama barang yang dicari: ";
                cin >> namaKey;
                urutnama(); // datanya urut buat binary
                binary_search(namaKey);
            } 
            else if (pilihsearch == 2) { // Sequential Search untuk harga
                int hargaKey;
                cout << "Masukkan harga barang yang dicari: ";
                cin >> hargaKey;
                sequential_search(hargaKey);
            } 
            else {
                cout << "Pilihan tidak valid!" << endl;
            }
            
            break;
        case 4:
            cout << "Pengurutan barang berdasarkan harga (Quick Sort)\n";
            quick_sort(0, jumlahData - 1);
            tampilData();
            break;
        case 5:
            cout << "Terimakasih";
            break;
        default:
        cout << "Pilihan tidak valid";
            break;
        }
        if (pilih == 5) break;
        cout << "\nTekan enter untuk kembali ke menu...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (pilih != 5);   
}

int main(){
    menu();
    return 0;
}