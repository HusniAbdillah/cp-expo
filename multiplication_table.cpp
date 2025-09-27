#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    
    cout << "==== PEMBUAT TABEL PERKALIAN ====" << endl;
    cout << "Masukkan nilai maksimum (n): ";
    cin >> n;
    
    cout << "\nTabel perkalian " << n << " x " << n << ":\n\n";
    
    cout << "    | ";
    for(int i = 1; i <= n; i++) {
        cout << setw(4) << i;
    }
    
    cout << "\n----+-";
    for(int i = 1; i <= n; i++) {
        cout << "----";
    }
    cout << endl;
    
    for(int i = 1; i <= n; i++) {
        cout << setw(4) << i << " | ";
        for(int j = 1; j <= n; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}