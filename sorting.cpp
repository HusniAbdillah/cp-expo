#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    
    cout << "==== PROGRAM PENGURUTAN ====" << endl;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Masukkan " << n << " angka:" << endl;
    
    for(int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i+1) << ": ";
        cin >> arr[i];
    }
    
    cout << "\nArray sebelum diurutkan: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    sort(arr.begin(), arr.end());
    
    cout << "\nArray setelah diurutkan (ascending): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << "\nArray setelah diurutkan (descending): ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\n\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}