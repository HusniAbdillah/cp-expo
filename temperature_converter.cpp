#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double suhu;
    int pilihan;
    
    cout << "==== KONVERTER SUHU ====" << endl;
    cout << "1. Celsius ke Fahrenheit" << endl;
    cout << "2. Celsius ke Kelvin" << endl;
    cout << "3. Fahrenheit ke Celsius" << endl;
    cout << "4. Fahrenheit ke Kelvin" << endl;
    cout << "5. Kelvin ke Celsius" << endl;
    cout << "6. Kelvin ke Fahrenheit" << endl;
    
    cout << "Pilih konversi (1-6): ";
    cin >> pilihan;
    
    cout << "Masukkan suhu: ";
    cin >> suhu;
    
    cout << fixed << setprecision(2);
    
    switch(pilihan) {
        case 1:
            cout << suhu << " °C = " << (suhu * 9/5) + 32 << " °F" << endl;
            break;
        case 2:
            cout << suhu << " °C = " << suhu + 273.15 << " K" << endl;
            break;
        case 3:
            cout << suhu << " °F = " << (suhu - 32) * 5/9 << " °C" << endl;
            break;
        case 4:
            cout << suhu << " °F = " << (suhu - 32) * 5/9 + 273.15 << " K" << endl;
            break;
        case 5:
            cout << suhu << " K = " << suhu - 273.15 << " °C" << endl;
            break;
        case 6:
            cout << suhu << " K = " << (suhu - 273.15) * 9/5 + 32 << " °F" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }
    
    cout << "\nTekan Enter untuk keluar...";
    cin.ignore();
    cin.get();
    return 0;
}