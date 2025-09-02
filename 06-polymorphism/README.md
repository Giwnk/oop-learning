### Polymorphism
=====================
## Definisi
    Polymorphism itu artinya “banyak bentuk”.
    Dalam C++ → sebuah objek atau method bisa punya “banyak versi” tergantung konteks penggunaannya.
    Intinya: satu nama, banyak perilaku.

## Fungsi
    - Bikin kode lebih fleksibel & reusable.
    - Bisa pake satu interface untuk berbagai implementasi.
    - Mempermudah maintenance program → kalo ada perubahan di satu tempat, yang lain nggak perlu diutak-atik terlalu banyak.

## Tujuan
    - Supaya program lebih modular (dipisah-pisah dengan rapi).
    - Biar gampang dipakai untuk abstraksi → kita fokus ke apa yang dilakukan, bukan bagaimana.
    - Cocok buat konsep OOP nyata: class parent ngatur aturan umum, class turunan bisa beda-beda cara kerjanya.

## Jenis Polymorphism di C++
    Ada dua tipe utama:
    1. Compile-time polymorphism (diketahui waktu compile):
        - Overloading (function overload, operator overload).
        - Contoh: fungsi print() bisa dipanggil untuk int, string, atau double.
    2. Runtime polymorphism (diketahui waktu program jalan):
        - Virtual function (overriding).
        - Contoh: method speak() di class Animal, bisa berbeda di Dog dan Cat.


## Contoh Kode
    1. Overloading

        #include <iostream>
        using namespace std;

        class Print {
        public:
            void show(int x) {
                cout << "Angka: " << x << endl;
            }

            void show(string text) {
                cout << "Teks: " << text << endl;
            }
        };

        int main() {
            Print p;
            p.show(42);         // Panggil versi integer
            p.show("Halo!");    // Panggil versi string
        }

    2. Overriding
        #include <iostream>
        using namespace std;

        class Animal {
        public:
            virtual void speak() {
                cout << "Hewan berbunyi..." << endl;
            }
        };

        class Dog : public Animal {
        public:
            void speak() override {
                cout << "Guk guk!" << endl;
            }
        };

        class Cat : public Animal {
        public:
            void speak() override {
                cout << "Meong!" << endl;
            }
        };

        int main() {
            Animal* a1 = new Dog();
            Animal* a2 = new Cat();

            a1->speak();  // Output: Guk guk!
            a2->speak();  // Output: Meong!
        }

## Permasalahan di Inheritance (Tanpa Polymorphism)
    Ketika pakai inheritance aja, biasanya muncul problem kayak:
    - Code Duplication (duplikasi kode)
        Kalau kita bikin method di parent class, tapi tiap subclass butuh cara berbeda → kita harus nulis ulang method dengan nama beda → bikin ribet.
    - Kesulitan Abstraksi
        Class induk (parent) biasanya cuma tahu aturan umum.
        Kalau tanpa polymorphism, parent nggak bisa manggil method subclass dengan fleksibel.
    - Object Slicing Problem
        Kalau kita simpan objek subclass ke dalam variabel bertipe parent (bukan pointer/reference), data atau behavior unik subclass kepotong (sliced).
        Akhirnya fungsi spesifik subclass nggak bisa jalan.
    - Kurang Fleksibel dalam Mengelola Koleksi Objek
        Misalnya kita punya array berisi Dog, Cat, Bird. Kalau nggak ada polymorphism, kita harus bikin array terpisah per tipe, atau manual ngecek satu-satu dengan if/switch.
        Ribet banget.
    - Diamond Problem
        Diamond problem muncul saat sebuah class mewarisi dari dua class berbeda, yang keduanya ternyata mewarisi dari satu base class yang sama.
        Struktur warisannya bentuknya kayak belah ketupat (diamond), makanya disebut diamond problem.

## Peran Polymorphism sebagai Solusi
    - Mengurangi Code Duplication
        Parent class bisa punya interface umum (misal speak() di Animal).
        Subclass cukup override method itu.
        Jadi kita nggak perlu bikin method baru dengan nama lain → cukup satu nama, perilaku disesuaikan.
    - Abstraksi Lebih Natural
        Parent class bisa jadi abstrak (abstract class) atau punya virtual function.
        Kita bisa fokus pakai objek sebagai "tipe umum", tanpa peduli implementasi detail.
    - Mengatasi Object Slicing
        Dengan pointer/reference ke parent, polymorphism memastikan method subclass tetep jalan.
        Jadi meskipun variabelnya bertipe parent, method yang dipanggil sesuai objek aslinya.
    - Fleksibilitas Koleksi Objek
        Dengan polymorphism, kita bisa simpan berbagai objek turunan dalam satu array/list bertipe parent.
        Pas di-iterate, tiap objek tetap memanggil perilaku sesuai subclass masing-masing.
## Perbedaan Utama Dari Overloading dan Overriding
    Overloading (Compile-time Polymorphism)
        - Nama method sama,
        - Parameter beda (jumlah atau tipe datanya beda),
        - Isi/implementasi otomatis beda karena disesuaikan dengan parameter.
        - Diputuskan saat compile time.
        - Bisa terjadi dalam satu class.

    Overriding (Runtime Polymorphism)
        - Nama method sama,
        - Parameter sama,
        - Isi/implementasi beda (disesuaikan subclass).
        - Diputuskan saat runtime.
        - Terjadi di hubungan inheritance (parent–child class).
        - Butuh virtual di parent (biar polymorphism aktif).

## Virtual Function
    # Definisi
    Virtual function adalah fungsi di dalam class parent (base class) yang ditandai dengan keyword virtual, supaya saat dipanggil lewat pointer/reference ke parent, fungsi itu bisa di-override oleh subclass (derived class).
    Simpelnya,
    Kalau tanpa virtual, C++ bakal jalankan fungsi versi parent (static binding).
    Kalau pakai virtual, C++ bakal jalankan fungsi versi objek aslinya (dynamic binding).
    # Ciri Ciri
    - Didefinisikan di class base dengan keyword virtual.
    - Bisa di-override di class turunan.
    - Dipanggil lewat pointer/reference ke base class.
    - Mendukung konsep runtime polymorphism (dynamic binding).

## Keyword virtual dan override dalam Overriding
    Virtual
        - Didefinisikan di base class (parent).
        - Fungsinya: bilang ke compiler bahwa fungsi ini bisa dioverride di subclass.
        - Kalau nggak pakai virtual, method di subclass dengan nama sama cuma dianggap fungsi baru (hiding), bukan override → polymorphism nggak jalan.
        - Jadi kalau mau runtime polymorphism, virtual di parent itu wajib.
    Override
        - Dipakai di derived class (child).
        - Fungsinya: kasih tahu compiler bahwa kita maksudnya ingin override method virtual dari parent.
        - Kalau ternyata nggak cocok (misalnya salah nulis parameter), compiler bakal error.
        - Jadi override itu opsional, tapi sangat dianjurkan biar aman dari bug halus.

## Bagaimana pointer bekerja dalam polymorphism di C++
    1. Pointer dibuat bertipe parent class
        - Kenapa parent? Karena parent itu “wadah besar” yang bisa menampung semua turunan.
        - Jadi, kalau pointer kita pakai tipe Parent*, otomatis dia bisa menunjuk ke object Child1, Child2, bahkan object parent itu sendiri.
        - Kalau pointer pakai tipe Child*, dia cuma bisa menunjuk ke object Child aja → kurang fleksibel.
    2. Pointer menyimpan alamat object turunan
        - Ketika kita buat object turunan (misal Car, Bike, dll), pointer Vehicle* bisa diarahkan ke object itu.
        - Pointer tidak menyimpan object, tapi menyimpan alamat memori object.
    3. Virtual + overriding bikin polymorphism bekerja
        - Kalau method di parent ditandai dengan virtual, lalu di subclass di-override, maka saat kita manggil v->method(),
        yang dipanggil adalah method sesuai object turunan yang sedang ditunjuk pointer.
        - Jadi pointer v itu kayak “remote control universal”, tombolnya sama (misal drive()), tapi hasilnya tergantung mesin mana yang sedang dikontrol (Car atau Bike).