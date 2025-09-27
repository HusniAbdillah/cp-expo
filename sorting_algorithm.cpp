#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void printArray(vector<int>& arr, string title, int highlight1 = -1, int highlight2 = -1, 
                pair<int, int> range = {-1, -1}) {
    system("cls");
    cout << title << "\n\n";
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == highlight1)
            cout << "\033[1;31m" << arr[i] << " \033[0m";
        else if (i == highlight2)
            cout << "\033[1;32m" << arr[i] << " \033[0m"; 
        else if (i >= range.first && i <= range.second && range.first != -1)
            cout << "\033[1;33m" << arr[i] << " \033[0m"; 
        else
            cout << arr[i] << " ";
    }
    cout << endl;
    Sleep(300);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    printArray(arr, "Quick Sort - Pivot: " + to_string(pivot), high, -1, {low, high});
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            printArray(arr, "Quick Sort - Swap: " + to_string(arr[i]) + " <-> " + to_string(arr[j]), 
                      i, j, {low, high});
        }
    }
    swap(arr[i + 1], arr[high]);
    printArray(arr, "Quick Sort - Final Swap for Pivot", i + 1, high, {low, high});
    
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    printArray(arr, "Merge Sort - Dividing", -1, -1, {left, right});
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        printArray(arr, "Merge Sort - Merging", k-1, -1, {left, right});
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        printArray(arr, "Merge Sort - Copying remaining Left", k-1, -1, {left, right});
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        printArray(arr, "Merge Sort - Copying remaining Right", k-1, -1, {left, right});
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
        
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
        printArray(arr, "Heap Sort - Heapify: Swap " + to_string(arr[i]) + " <-> " + to_string(arr[largest]), 
                 i, largest);
                 
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        printArray(arr, "Heap Sort - Building Heap", i);
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        printArray(arr, "Heap Sort - Extract Max: " + to_string(arr[i]), 0, i);
        
        heapify(arr, i, 0);
    }
}

int main() {
    int n, choice;
    
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Masukkan " << n << " elemen: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    cout << "Pilih algoritma sorting:\n";
    cout << "1. Quick Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Heap Sort\n";
    cin >> choice;
    
    switch (choice) {
        case 1:
            quickSort(arr, 0, n - 1);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        case 3:
            heapSort(arr);
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
    
    printArray(arr, "Array setelah diurutkan");
    
    return 0;
}