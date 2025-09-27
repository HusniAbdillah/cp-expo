#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double pokok, bunga, tahun;
    int pilihan;
    
    cout << "==== KALKULATOR BUNGA ====" << endl;
    cout << "1. Bunga Sederhana" << endl;
    cout << "2. Bunga Majemuk" << endl;
    cout << "Pilih jenis bunga (1/2): ";
    cin >> pilihan;
    
    cout << "Masukkan jumlah pokok (Rp): ";
    cin >> pokok;
    
    cout << "Masukkan suku bunga (% per tahun): ";
    cin >> bunga;
    
    cout << "Masukkan jangka waktu (tahun): ";
    cin >> tahun;
    
    cout << fixed << setprecision(0);
    
    if(pilihan == 1) {
        double hasil = pokok * bunga/100 * tahun;
        cout << "\nHasil Perhitungan Bunga Sederhana:" << endl;
        cout << "Bunga: Rp " << hasil << endl;
        cout << "Total: Rp " << pokok + hasil << endl;
    }
    else if(pilihan == 2) {
        double hasil = pokok * pow(1 + bunga/100, tahun) - pokok;
        cout << "\nHasil Perhitungan Bunga Majemuk:" << endl;
        cout << "Bunga: Rp " << hasil << endl;
        cout << "Total: Rp " << pokok + hasil << endl;
    }
    else {
        cout << "Pilihan tidak valid!" << endl;
    }
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}