#include <iostream>
using namespace std;

class Mahasiswa{
    public:
    // Attributes atau Data yang ada pada object
        string nama;
        int nim,semester;
    
    // Constructor akan dipanggil pertama kali saat objek otomatis dibuat atau seperti rangkaian awal
    Mahasiswa(string inputNama,int inputNim, int inputSemester ){
        nama = inputNama;
        nim = inputNim;
        semester = inputSemester;
    }
    // Methods atau fitur yg bisa dilakukan oleh class
    void tampilkanData(){
        cout << "Berikut Data Anda: " << endl;
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "Semester: " << semester << endl;
    }
};

int main(int argc, char const *argv[])
{

    string nama;
    int nim,semester;
    cout << "Masukkan nama anda: ";
    cin >> nama;

    cout << "Masukkan NIM anda: ";
    cin >> nim;

    cout << "Masukkan Semester anda: ";
    cin >> semester;

    Mahasiswa mhs1(nama,nim,semester); // Membuat object dan constructor akan berjalan saat pertama kali object dibuat
    mhs1.tampilkanData();
    return 0;
}
