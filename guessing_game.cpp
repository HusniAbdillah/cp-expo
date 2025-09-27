#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    int angkaRahasia = rand() % 100 + 1;
    int tebakan;
    int percobaan = 0;
    bool tebakanBenar = false;
    
    cout << "==== PERMAINAN TEBAK ANGKA ====" << endl;
    cout << "Saya telah memilih angka antara 1 dan 100." << endl;
    cout << "Dapatkah Anda menebaknya?" << endl << endl;
    
    while (!tebakanBenar) {
        cout << "Masukkan tebakan Anda: ";
        cin >> tebakan;
        percobaan++;
        
        if (tebakan < angkaRahasia) {
            cout << "Terlalu RENDAH! Coba lagi." << endl << endl;
        } else if (tebakan > angkaRahasia) {
            cout << "Terlalu TINGGI! Coba lagi." << endl << endl;
        } else {
            cout << "\nSELAMAT! Anda berhasil menebak angka " << angkaRahasia << "!" << endl;
            cout << "Jumlah percobaan: " << percobaan << endl;
            tebakanBenar = true;
        }
    }
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}