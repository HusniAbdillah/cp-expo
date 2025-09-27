#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void printDP(vector<vector<int>>& dp, vector<int>& weights, vector<int>& values, 
             int n, int W, int i = -1, int w = -1) {
    system("cls");
    cout << "0-1 Knapsack Problem (Dynamic Programming)\n\n";
    
    cout << "Items (weight, value):\n";
    for (int j = 0; j < n; j++) {
        if (j == i)
            cout << "\033[1;32m[" << j << ": " << weights[j] << "kg, $" << values[j] << "]\033[0m  ";
        else
            cout << "[" << j << ": " << weights[j] << "kg, $" << values[j] << "]  ";
    }
    cout << "\n\nKapasitas Knapsack: " << W << "kg\n\n";
    
    cout << "Tabel DP[item][kapasitas]:\n";
    cout << "    ";
    for (int j = 0; j <= W; j++)
        cout << j << " ";
    cout << endl;
    
    for (int j = 0; j <= n; j++) {
        if (j == i + 1)
            cout << "\033[1;32m" << j << "\033[0m   ";
        else
            cout << j << "   ";
            
        for (int k = 0; k <= W; k++) {
            if (j == i + 1 && k == w)
                cout << "\033[1;32m" << dp[j][k] << "\033[0m ";
            else
                cout << dp[j][k] << " ";
        }
        cout << endl;
    }
    
    Sleep(500);
}

int knapsack(vector<int>& weights, vector<int>& values, int W, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    printDP(dp, weights, values, n, W);
    
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
                printDP(dp, weights, values, n, W, i - 1, w);
            }
            else {
                dp[i][w] = dp[i - 1][w];
                printDP(dp, weights, values, n, W, i - 1, w);
            }
        }
    }
    
    cout << "\nItem yang dipilih:\n";
    int res = dp[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i-1][w]) {
            cout << "Item " << i-1 << " (weight: " << weights[i-1] << ", value: " << values[i-1] << ")\n";
            res -= values[i-1];
            w -= weights[i-1];
        }
    }
    
    return dp[n][W];
}

int main() {
    int n, W;
    
    cout << "Masukkan jumlah item: ";
    cin >> n;
    
    vector<int> weights(n), values(n);
    
    cout << "Masukkan " << n << " berat item:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];
        
    cout << "Masukkan " << n << " nilai item:\n";
    for (int i = 0; i < n; i++)
        cin >> values[i];
        
    cout << "Masukkan kapasitas knapsack: ";
    cin >> W;
    
    int maxValue = knapsack(weights, values, W, n);
    cout << "\nNilai maksimum: $" << maxValue << endl;
    
    return 0;
}