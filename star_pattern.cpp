#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "==== PEMBUAT POLA BINTANG ====" << endl;
    cout << "Masukkan jumlah baris: ";
    cin >> n;
    
    cout << "\nPola Piramida:\n";
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << "\nPola Berlian:\n";
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
    for(int i = n - 1; i >= 1; --i) {
        for(int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        for(int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}