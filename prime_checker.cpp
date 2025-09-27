#include <iostream>
using namespace std;

int main() {
    int n, i;
    bool isPrime = true;
    
    cout << "==== CEK BILANGAN PRIMA ====" << endl;
    cout << "Masukkan bilangan positif: ";
    cin >> n;
    
    if (n == 0 || n == 1) {
        isPrime = false;
    } else {
        for(i = 2; i <= n/2; ++i) {
            if(n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    
    if (isPrime)
        cout << n << " adalah bilangan prima." << endl;
    else
        cout << n << " bukan bilangan prima." << endl;
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}