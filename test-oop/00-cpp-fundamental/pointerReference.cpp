#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int angka = 50; // Variabel Angka
    int* ptr = &angka; // Membuat variabel Pointer yang menyimpan alamat Variabel Angka
    
    // Operator "&" dipakai buat ngambil alamat memori dari variabel angka.

    cout << "Nilai angka: " << angka << endl; // Nilai dari variabel Angka
    cout << "Alamat angka: " << ptr << endl; // Alamat Angka
    cout << "Nilai lewat pointer: " << *ptr << endl; // Nilai variabel angka melalui pointer

    *ptr = 30; // jika kita ubah nilai melalui pointer, maka nilai dari variabel angka juga berubah
    cout << "Nilai angka: " << angka << endl;

    return 0;
}
