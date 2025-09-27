#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void visualizeSearch(vector<int>& arr, int left, int right, int mid, int target) {
    system("cls");
    cout << "Mencari " << target << " dalam array:\n";
    for (int i = 0; i < arr.size(); i++) {
        if (i == mid)
            cout << "\033[1;32m[" << arr[i] << "]\033[0m ";
        else if (i >= left && i <= right)
            cout << "\033[1;33m" << arr[i] << "\033[0m ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
    Sleep(1000);
}

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        visualizeSearch(arr, left, right, mid, target);
        
        if (arr[mid] == target) {
            cout << "Elemen ditemukan pada indeks " << mid << endl;
            return mid;
        }
        
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    cout << "Elemen tidak ditemukan" << endl;
    return -1;
}

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        visualizeSearch(arr, 0, i, i, target);
        
        if (arr[i] == target) {
            cout << "Elemen ditemukan pada indeks " << i << endl;
            return i;
        }
    }
    
    cout << "Elemen tidak ditemukan" << endl;
    return -1;
}

int main() {
    int n, target, choice;
    
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Masukkan " << n << " elemen (terurut untuk binary search): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Masukkan elemen yang dicari: ";
    cin >> target;
    
    cout << "Pilih algoritma pencarian:\n";
    cout << "1. Binary Search (array harus terurut)\n";
    cout << "2. Linear Search\n";
    cin >> choice;
    
    if (choice == 1)
        binarySearch(arr, target);
    else if (choice == 2)
        linearSearch(arr, target);
    else
        cout << "Pilihan tidak valid\n";
    
    return 0;
}