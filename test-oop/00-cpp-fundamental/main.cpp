#include <iostream>
using namespace std;

char gradeFunction(int rataRataNilai){
    if (rataRataNilai >= 90)
    {
        return 'A';
    }
    else if (rataRataNilai >= 80)
    {
        return 'B';
    }
    else if (rataRataNilai >= 70)
    {
        return 'C';
    }
    else if (rataRataNilai >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
    
}


int main(int argc, char const *argv[])
{
    int banyakMatkul;
    double jumlahNilai = 0, nilai;

    
    cout << "Selamat Datang Di Program!!" << endl; 
    cout << "Masukkan Banyak Matkul Anda: ";
    cin >> banyakMatkul;

    for (int i = 0; i < banyakMatkul; i++)
    {   
        cout << "Masukkan Nilai Matkul ke-" << i+1 << ": ";
        cin >> nilai;
        jumlahNilai += nilai;
    }
    
    double rataRataNilai = jumlahNilai / banyakMatkul;
    
    cout << "Rata Rata Nilai Anda Adalah: " << rataRataNilai << endl;
    cout << "Predikat Akhir Anda Adalah: " << gradeFunction(rataRataNilai) << endl;


    return 0;
}
