#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    
    cout << "Visualisasi Sieve of Eratosthenes:" << endl;
    
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            cout << "\nLangkah " << p-1 << ": Menandai kelipatan " << p << endl;
            
            for (int i = p * p; i <= n; i += p) {
                if (isPrime[i]) {
                    isPrime[i] = false;
                    cout << i << " ditandai bukan prima" << endl;
                }
            }
        }
    }
    
    cout << "\nBilangan prima dari 1 hingga " << n << " adalah: ";
    for (int p = 2; p <= n; p++) {
        if (isPrime[p])
            cout << p << " ";
    }
    cout << endl;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cout << "Masukkan batas atas untuk mencari bilangan prima: ";
    cin >> n;
    
    sieveOfEratosthenes(n);
    
    return 0;
}