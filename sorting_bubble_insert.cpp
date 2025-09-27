#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void printArray(vector<int>& arr, int n, int highlight = -1) {
    system("cls");
    for (int i = 0; i < n; i++) {
        if (i == highlight)
            cout << "\033[1;31m" << arr[i] << " \033[0m";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
    Sleep(100);
}

void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            printArray(arr, n, j);
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    printArray(arr, n);
    cout << "Bubble Sort selesai!" << endl;
}

void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        printArray(arr, n, i);
        
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
            printArray(arr, n, j+1);
        }
        arr[j+1] = key;
    }
    printArray(arr, n);
    cout << "Insertion Sort selesai!" << endl;
}

int main() {
    int n, choice;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Masukkan " << n << " elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Pilih algoritma sorting:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cin >> choice;
    
    switch(choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        default: cout << "Pilihan tidak valid" << endl;
    }
    
    return 0;
}