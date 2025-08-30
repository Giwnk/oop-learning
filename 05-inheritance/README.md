# 📘 Inheritance di C++  

## 📖 Deskripsi  
Inheritance (pewarisan) adalah konsep **Object-Oriented Programming (OOP)** yang memungkinkan sebuah **class turunan (child class)** mewarisi atribut (variabel) dan method (fungsi) dari **class induk (parent class)**.  

Tujuan utamanya adalah **code reusability, struktur lebih rapi, dan pengembangan yang lebih mudah**. Hubungan inheritance biasanya mengikuti pola **"is-a"** (contoh: `Student is-a Person`).  

---

## ✨ Fitur Utama
- **Code Reusability**: Menghindari penulisan ulang kode.  
- **Struktur Hierarkis**: Menggambarkan hubungan antar objek.  
- **Overriding**: Child class dapat menimpa method parent.  
- **Polymorphism**: Memungkinkan pemanggilan method yang berbeda lewat parent pointer/reference.  
- **Virtual Inheritance**: Mengatasi diamond problem.  

---

## 🔧 Tipe Inheritance di C++
- **Single Inheritance** → Satu parent, satu child.  
- **Multilevel Inheritance** → Parent → Child → Subchild.  
- **Multiple Inheritance** → Satu child punya beberapa parent.  
- **Hierarchical Inheritance** → Satu parent, banyak child.  

---

## 🖥️ Contoh Kode Dasar

### Single Inheritance
```cpp
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void setPerson(string n, int a) { name = n; age = a; }
    void showPerson() { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Student : public Person {
private:
    string major;
public:
    void setStudent(string n, int a, string m) {
        setPerson(n, a);
        major = m;
    }
    void showStudent() {
        showPerson();
        cout << "Major: " << major << endl;
    }
};

int main() {
    Student s;
    s.setStudent("Andi", 20, "Computer Science");
    s.showStudent();
}
```

---

## 🎯 Tujuan & Alasan
- Mengurangi duplikasi kode.  
- Mempermudah perawatan & pengembangan program.  
- Membuat model program lebih dekat dengan dunia nyata.  
- Mendukung konsep OOP seperti polymorphism.  

---

## 🌍 Contoh Nyata & Analogi
- **Kehidupan Sehari-hari**:  
  - `Kendaraan` → parent.  
  - `Mobil`, `Motor`, `Bus` → child.  
- **Akademik**:  
  - `Person` → parent.  
  - `Mahasiswa`, `Dosen` → child.  
- **Analogi**:  
  - Mirip **warisan keluarga** → anak dapat sifat/atribut dari orang tua, tapi bisa punya ciri khas sendiri.  
  - Mirip **template folder** → folder child dapat isi folder parent, tapi bisa nambah file sendiri.  

---

## 📝 Latihan Kecil
1. Buat class `Animal` dengan method `makeSound()`.  
2. Buat class `Dog` yang override method tersebut untuk menampilkan `"Woof!"`.  
3. Buat object `Dog` lalu panggil methodnya.  

---

## ❓ Mini Quiz
```cpp
class A {
public:
    void sayHello() { cout << "Hello from A" << endl; }
};

class B : public A {
public:
    void sayHello() { cout << "Hello from B" << endl; }
};

int main() {
    B obj;
    obj.sayHello();    // Output?
    obj.A::sayHello(); // Output?
}
```

**Jawaban:**  
1. `Hello from B`  
2. `Hello from A`  

---

## ⚠️ Masalah Umum dalam Inheritance

**Diamond Problem**: Child mewarisi 2x dari parent yang sama, analoginya Warisan kakek dihitung dobel. Solusinya Gunakan **virtual inheritance** 

**Overriding Salah**: Child override method tapi salah logika, analoginya Anak nyetir mobil tanpa rem. Solusinya Gunakan `override` & method `virtual`

**Deep Inheritance**: Terlalu banyak level turunan, bikin ribet, analoginya Silsilah 8 generasi. Solusinya Pertimbangkan **composition (has-a)**

**Access Issue**: Salah pilih specifier → atribut terkunci, analoginya Warisan rumah, sertifikat dikunci. Solusinya Gunakan **public inheritance** jika ingin hubungan is-a

**Object Slicing**: Child di-assign ke parent by value → atribut child hilang, analoginya Pizza utuh dipotong biar muat di kotak kecil. Solusinya Gunakan **pointer/reference** + **virtual function**

---

## 📦 Object Slicing (Detail)
### Masalah
Child object disimpan ke parent object by value → atribut tambahan child hilang.  
```cpp
Student s("Budi", "CS");
Person p = s;   // slicing terjadi
p.introduce();  // cuma versi Person
```

### Solusi
- Pakai **reference/pointer**:
```cpp
Person &p = s; // reference
p.introduce();
```
- Gunakan **virtual function** untuk polymorphism.  

---

## 📌 Pointer vs Reference (Ringkasan)

| Aspek        | Pointer                   | Reference                          |
|--------------|---------------------------|------------------------------------|
| Penyimpanan  | Menyimpan alamat memori   | Alias/nama lain dari variabel      |
| Null         | Bisa null                 | Tidak bisa null                    |
| Rebinding    | Bisa ubah target          | Tidak bisa diganti setelah binding |
| Overhead     | Lebih fleksibel           | Lebih sederhana                    |
| Tujuan       | Kontrol penuh (low-level) | Alias praktis (high-level)         |

---

## 🧠 Insight Penting
- Inheritance menggambarkan **hubungan "is-a"**.  
- Gunakan dengan bijak → kadang **composition** lebih baik.  
- **Polymorphism** hanya bisa dicapai dengan pointer/reference + `virtual`.  
- Hati-hati dengan **object slicing** dan **diamond problem**.  

---

## 🗒️ Catatan Tambahan
- Selalu evaluasi: apakah benar-benar butuh inheritance?  
- Gunakan keyword `override` untuk menghindari bug overriding.  
- Pahami perbedaan antara **copy vs reference vs pointer** untuk menghindari slicing.  
