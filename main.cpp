#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama;
    int angka1, angka2;

    cout << "=== Program Pertama C++ ===" << endl;

    cout << "Masukkan nama: ";
    getline(cin, nama);

    cout << "Masukkan angka pertama: ";
    cin >> angka1;

    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "\nHalo, " << nama << "!" << endl;
    cout << "Hasil penjumlahan: "
         << angka1 + angka2 << endl;

    return 0;
}