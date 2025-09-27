#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int angka, asli, remainder, n = 0, hasil = 0;
    vector<int> digits;
    
    cout << "==== CEK BILANGAN ARMSTRONG ====" << endl;
    cout << "Masukkan bilangan positif: ";
    cin >> angka;
    
    asli = angka;
    
    while (asli != 0) {
        asli /= 10;
        ++n;
    }
    
    asli = angka;
    
    while (asli != 0) {
        remainder = asli % 10;
        digits.push_back(remainder);
        hasil += pow(remainder, n);
        asli /= 10;
    }
    
    cout << "\nPenjelasan:" << endl;
    cout << "Bilangan " << angka << " memiliki " << n << " digit." << endl;
    cout << "Perhitungan: ";
    
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i] << "^" << n;
        if (i > 0) cout << " + ";
    }
    
    cout << " = ";
    
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << pow(digits[i], n);
        if (i > 0) cout << " + ";
    }
    
    cout << " = " << hasil << endl;
    
    if (hasil == angka)
        cout << "\n" << angka << " adalah bilangan Armstrong karena jumlah setiap digit yang dipangkatkan " << n << " sama dengan bilangan itu sendiri." << endl;
    else
        cout << "\n" << angka << " bukan bilangan Armstrong karena jumlah setiap digit yang dipangkatkan " << n << " tidak sama dengan bilangan itu sendiri." << endl;
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}