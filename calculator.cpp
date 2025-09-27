#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;
    char operasi;
    
    cout << "==== KALKULATOR SEDERHANA ====" << endl;
    
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    
    cout << "Masukkan operasi (+, -, *, /): ";
    cin >> operasi;
    
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    
    switch(operasi) {
        case '+':
            cout << "Hasil: " << angka1 + angka2 << endl;
            break;
        case '-':
            cout << "Hasil: " << angka1 - angka2 << endl;
            break;
        case '*':
            cout << "Hasil: " << angka1 * angka2 << endl;
            break;
        case '/':
            if(angka2 != 0)
                cout << "Hasil: " << angka1 / angka2 << endl;
            else
                cout << "Error! Pembagian dengan nol tidak diperbolehkan." << endl;
            break;
        default:
            cout << "Operasi tidak valid!" << endl;
    }
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}