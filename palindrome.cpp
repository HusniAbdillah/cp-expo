#include <iostream>
using namespace std;

int main() {
    string teks;
    bool isPalindrome = true;
    
    cout << "==== CEK PALINDROME ====" << endl;
    cout << "Masukkan teks: ";
    getline(cin, teks);
    
    int panjang = teks.length();
    
    for(int i = 0; i < panjang / 2; i++) {
        if(teks[i] != teks[panjang - i - 1]) {
            isPalindrome = false;
            break;
        }
    }
    
    if(isPalindrome)
        cout << "\"" << teks << "\" adalah palindrome." << endl;
    else
        cout << "\"" << teks << "\" bukan palindrome." << endl;
    
    cout << "\nTekan Enter untuk keluar...";
    cin.get();
    return 0;
}