#include <iostream>
using namespace std;

class Mahasiswa{ // Deklarasi class baru
    public:
    // Attributes atau Data yang ada pada object
        string nama;
        int nim;

};

int main(int argc, char const *argv[])
{
    Mahasiswa mahasiswa1; // Deklarasi object baru
    Mahasiswa mahasiswa2;
    Mahasiswa mahasiswa3;
    // Dengan satu class, kita bisa membuat object yang attributesnya sama

    mahasiswa1.nama = "Giwank"; // Set data pada object
    mahasiswa1.nim = 1313624038;

    mahasiswa2.nama = "Naya";
    mahasiswa2.nim = 1313624018;

    mahasiswa3.nama = "Naya";
    mahasiswa3.nim = 1313624028;

    cout << "Nama Mahasiswa 1: " << mahasiswa1.nama << ", NIM Mahasiswa 1: " << mahasiswa1.nim << endl; // Cek nama dan nim yang sudah di set pada object
    cout << "Nama Mahasiswa 2: " << mahasiswa2.nama << ", NIM Mahasiswa 2: " << mahasiswa2.nim << endl;
    cout << "Nama Mahasiswa 3: " << mahasiswa3.nama << ", NIM Mahasiswa 3: " << mahasiswa3.nim << endl;
    return 0;
}

