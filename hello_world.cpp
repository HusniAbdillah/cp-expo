#include <iostream>
using namespace std;

int main() {
    cout << "==================================" << endl;
    cout << "    SELAMAT DATANG DI EXPO CP    " << endl;
    cout << "==================================" << endl;
    cout << "\nHalo! Ini adalah program C++ pertama saya!" << endl;
    
    string nama;
    cout << "\nMasukkan nama Anda: ";
    getline(cin, nama);
    
    cout << "Halo " << nama << ", selamat belajar C++!" << endl;
    
    cout << "\nTekan Enter untuk keluar...";
    cin.get();
    return 0;
}