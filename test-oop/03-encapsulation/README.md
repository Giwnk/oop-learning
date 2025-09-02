# Encapsulation
    Encapsulation adalah pembungkusan data dan metode yang memanipulasi data itu jadi satu kesatuan di dalam sebuah class, sambil membatasi akses langsung dari luar.
    Simpelnya "Objek punya rahasia, dan rahasia itu cuma bisa diakses lewat jalur resmi."

# Tujuan Encapsulation
    -Menyembunyikan data agar nggak bisa diakses sembarangan dari luar class.
    -Hanya bisa diakses lewat metode khusus (getter/setter).
    -Tujuan: keamanan data & mencegah perubahan nggak sengaja.

# Konsep Penyembunyian Data
    Data disembunyikan dari akses langsung oleh kode di luar class.
    Hal ini dilakukan dengan access modifier (private, protected, public).
    Tujuannya mencegah:
    - Perubahan data secara sembarangan.
    - Kebingungan akibat banyak kode langsung mengutak-atik variabel internal.

# Access Modifier
    Access modifier adalah kata kunci yang menentukan siapa saja yang boleh mengakses member (atribut & metode) dari suatu class.
    Tujuannya:
    - Mengontrol akses ke data & fungsi.
    - Menerapkan encapsulation dengan benar.

    Jenis access modifier:
    1. Public
        - Bisa diakses dari mana saja (dalam class itu sendiri, class lain, atau fungsi luar).
        - Cocok untuk metode umum (misalnya setter/getter) atau atribut yang memang ingin terbuka.
    2. Private
        - Hanya bisa diakses dari dalam class itu sendiri.
        - Class lain tidak bisa langsung mengakses.
        - Cocok untuk atribut sensitif yang ingin dilindungi.
    3. Protected
        - Mirip private, tapi bisa diakses oleh class turunan (derived class).
        - Cocok untuk atribut yang ingin diwariskan tapi tetap tidak terbuka untuk umum

# Setter dan Getter
    Untuk mengakses atribut atau data yang dimana akses nya adlaah private atau protected, kita perlu menggunakan Setter dan Getter.
    - Setter → Metode untuk mengatur/mengubah nilai atribut.
    - Getter → Metode untuk mengambil/membaca nilai atribut.

    Fungsi Setter dan Getter:
    Setter:
    - Mengubah nilai atribut secara aman → Perubahan selalu lewat satu pintu.
    - Validasi sebelum simpan data → Misalnya umur nggak boleh negatif.
    - Menyembunyikan detail implementasi → Kalau nanti cara penyimpanan berubah, kode luar ngga ikut diubah.
    - Memberi kontrol penuh → Bisa tambahkan logika tambahan sebelum atau sesudah data diubah.
    Getter:
    - Membaca nilai atribut dengan aman → Tidak bisa mengubah data tanpa izin.
    - Bisa memodifikasi output → Misalnya format angka atau huruf kapital semua.
    - Tetap fleksibel kalau implementasi internal berubah.

    Tips Praktis:
    - Gunakan nama yang jelas → setNama(), getUmur() (Java style) atau SetNama(), GetUmur() (C++ style tergantung konvensi).
    - Lakukan validasi di setter untuk mencegah data “rusak”.
    - Getter sebaiknya tidak mengubah data, cukup mengembalikan nilai.
    - Jangan buat setter/getter untuk semua atribut kalau nggak perlu (anti-pattern: “JavaBean syndrome”).
    - Kalau atribut sifatnya read-only, cukup sediakan getter.
    - Kalau atribut sifatnya write-only (misalnya password), cukup sediakan setter.

# Kenapa private Melindungi Atribut?
    private memastikan variabel tidak bisa diubah langsung dari luar class.
    Semua perubahan harus lewat jalur resmi (setter), sehingga kita bisa:
        - Melakukan validasi sebelum data disimpan.
        - Menjaga integritas data (misal, umur nggak bisa negatif).
    Kalau atribut public, semua kode bisa ubah sesuka hati.


