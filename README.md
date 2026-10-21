# Panduan Instalasi dan Konfigurasi C++ Menggunakan Visual Studio Code dan MinGW-w64

Panduan ini disusun sebagai bahan pendamping praktikum mata kuliah **Algoritma dan Pemrograman** dan **Struktur Data**, khususnya bagi mahasiswa yang baru mulai mempelajari bahasa pemrograman C++ di Windows.

Melalui panduan ini, mahasiswa akan mempelajari cara menyiapkan lingkungan pemrograman C++, mulai dari instalasi editor, pemasangan compiler, konfigurasi lingkungan, menjalankan program pertama, hingga memahami dan mengatasi error yang umum terjadi.

Panduan ini menggunakan **Visual Studio Code (VS Code)** sebagai editor dan **MinGW-w64 melalui MSYS2 UCRT64** sebagai toolchain C++.

---

## Daftar Isi

1. [Tujuan Panduan](#1-tujuan-panduan)
2. [Mengenal Tools yang Digunakan](#2-mengenal-tools-yang-digunakan)
3. [Persiapan Sebelum Instalasi](#3-persiapan-sebelum-instalasi)
4. [Instalasi Visual Studio Code](#4-instalasi-visual-studio-code)
5. [Instalasi Compiler MinGW-w64](#5-instalasi-compiler-mingw-w64)
6. [Konfigurasi PATH pada Windows](#6-konfigurasi-path-pada-windows)
7. [Instalasi Ekstensi C/C++](#7-instalasi-ekstensi-cc)
8. [Membuat Project C++ Pertama](#8-membuat-project-c-pertama)
9. [Compile dan Menjalankan Program](#9-compile-dan-menjalankan-program)
10. [Memahami Proses Kompilasi](#10-memahami-proses-kompilasi)
11. [Troubleshooting dan Solusi Error](#11-troubleshooting-dan-solusi-error)
12. [Tips Penggunaan VS Code untuk Praktikum](#12-tips-penggunaan-vs-code-untuk-praktikum)
13. [Latihan Mandiri](#13-latihan-mandiri)
14. [Checklist Keberhasilan Instalasi](#14-checklist-keberhasilan-instalasi)
15. [Referensi Resmi](#15-referensi-resmi)

---

## 1. Tujuan Panduan

Setelah mengikuti panduan ini, mahasiswa diharapkan mampu:

- Memahami perbedaan antara editor kode, compiler, dan debugger.
- Menginstal Visual Studio Code dan toolchain C++ pada Windows.
- Mengonfigurasi PATH agar compiler dapat diakses dari terminal.
- Membuat dan menyimpan file dengan ekstensi `.cpp`.
- Melakukan kompilasi program menggunakan `g++`.
- Menjalankan program hasil kompilasi melalui terminal.
- Memahami pesan error dasar saat menulis dan menjalankan program.
- Melakukan pemeriksaan awal secara mandiri sebelum meminta bantuan.

Panduan ini tidak hanya berfokus pada keberhasilan instalasi, tetapi juga membantu mahasiswa memahami proses kerja program C++.

## 2. Mengenal Tools yang Digunakan

Sebelum melakukan instalasi, mahasiswa perlu memahami fungsi setiap komponen yang digunakan.

### 2.1. Visual Studio Code

Visual Studio Code adalah editor kode yang digunakan untuk menulis, mengedit, dan mengelola file program.

VS Code menyediakan fitur seperti:

- Syntax highlighting untuk membantu membaca kode.
- IntelliSense untuk memberikan saran kode.
- Deteksi kesalahan sintaks tertentu.
- Terminal terintegrasi.
- Integrasi dengan debugger dan berbagai ekstensi.

Namun, VS Code pada dasarnya adalah editor. Instalasi VS Code saja tidak otomatis menyediakan compiler C++.

### 2.2. Compiler C++

Compiler adalah perangkat lunak yang menerjemahkan kode sumber menjadi bentuk program yang dapat dijalankan oleh komputer.

Dalam panduan ini, compiler yang digunakan adalah `g++`, yaitu compiler C++ dari GCC.

Sebagai contoh, kode berikut merupakan kode sumber C++:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

Kode tersebut perlu dikompilasi terlebih dahulu sebelum dapat dijalankan sebagai program Windows.

### 2.3. MinGW-w64

MinGW-w64 menyediakan toolchain yang memungkinkan program C dan C++ dikompilasi untuk Windows menggunakan GCC.

Komponen yang relevan antara lain:

| Komponen | Fungsi |
|---|---|
| `g++` | Mengompilasi program C++. |
| `gcc` | Compiler driver yang umum digunakan untuk C dan juga dapat menangani proses build yang berkaitan. |
| `gdb` | Debugger untuk memeriksa jalannya program. |
| Linker | Menggabungkan object file dan library menjadi executable. |

Komponen tersebut dipasang sebagai bagian dari toolchain melalui MSYS2.

### 2.4. MSYS2

MSYS2 adalah lingkungan distribusi perangkat lunak yang menyediakan pengelolaan paket melalui perintah `pacman`.

Melalui MSYS2, mahasiswa dapat memasang dan memperbarui toolchain MinGW-w64 tanpa harus mencari compiler dari sumber yang tidak jelas.

Dalam panduan ini, lingkungan yang dipilih adalah **UCRT64**. Dokumentasi MSYS2 merekomendasikan UCRT64 bagi pengguna yang belum memiliki kebutuhan khusus terhadap lingkungan lain.

### 2.5. PATH pada Windows

PATH adalah variabel lingkungan yang berisi daftar direktori tempat Windows mencari program ketika sebuah perintah dijalankan.

Sebagai contoh, ketika mahasiswa mengetik:

```powershell
g++ --version
```

Windows perlu menemukan program `g++.exe`.

Jika folder compiler belum tersedia di PATH, perintah tersebut mungkin tidak dikenali meskipun compiler sebenarnya sudah terpasang.

### 2.6. Hubungan Antar-Komponen

Alur kerja secara sederhana dapat digambarkan sebagai berikut:

```text
Mahasiswa menulis kode
          |
          v
     File main.cpp
          |
          v
     Compiler g++
          |
          v
     Proses kompilasi
          |
          v
      main.exe
          |
          v
    Program dijalankan
          |
          v
    Hasil tampil di terminal
```

VS Code digunakan untuk menulis kode dan mengakses terminal, sedangkan compiler bertanggung jawab untuk mengompilasi kode tersebut.

---

## 3. Persiapan Sebelum Instalasi

Sebelum memulai, pastikan perangkat memenuhi kebutuhan dasar berikut:

- Sistem operasi Windows 10 atau Windows 11 64-bit.
- Koneksi internet untuk mengunduh installer dan paket compiler.
- Ruang penyimpanan yang cukup.
- Hak akses untuk memasang aplikasi dan mengubah User Path.
- Aplikasi terminal yang tersedia di Windows.

Disarankan menggunakan direktori project yang sederhana, misalnya:

```text
C:\belajar-cpp
```

Hindari menyimpan project praktikum di folder sistem Windows. Untuk memudahkan proses awal, gunakan folder dengan nama sederhana dan hindari karakter yang tidak diperlukan.

**Catatan:** Panduan ini mengasumsikan instalasi MSYS2 berada pada lokasi default `C:\msys64`. Jika memilih lokasi lain, sesuaikan semua path pada langkah berikutnya.

---

## 4. Instalasi Visual Studio Code

### 4.1. Mengunduh VS Code

1. Buka situs resmi Visual Studio Code:

   https://code.visualstudio.com/

2. Pilih installer untuk Windows.
3. Unduh installer sesuai perangkat.
4. Jalankan file installer yang telah diunduh.

### 4.2. Menjalankan Installer

Ikuti petunjuk instalasi yang ditampilkan.

Jika tersedia, aktifkan opsi integrasi menu konteks untuk memudahkan membuka folder dengan VS Code. Opsi menambahkan VS Code ke PATH juga dapat dipilih jika diperlukan.

Setelah proses instalasi selesai, buka Visual Studio Code.

### 4.3. Memeriksa Instalasi

Pastikan VS Code dapat dibuka dan digunakan untuk membuat file baru.

Pada tahap ini, mahasiswa belum harus dapat menjalankan C++, karena compiler akan dipasang pada langkah berikutnya.

---

## 5. Instalasi Compiler MinGW-w64

Pada bagian ini, kita akan memasang compiler C++ menggunakan MSYS2.

### 5.1. Mengunduh MSYS2

1. Buka situs resmi MSYS2:

   https://www.msys2.org/

2. Unduh installer yang tersedia.
3. Jalankan installer.
4. Ikuti instruksi instalasi.
5. Gunakan lokasi default `C:\msys64` jika tidak ada kebutuhan khusus.
6. Setelah instalasi selesai, buka aplikasi **MSYS2 UCRT64** melalui Start Menu.

Pastikan terminal yang dibuka adalah UCRT64, bukan terminal MSYS biasa. Lingkungan ini menentukan toolchain dan direktori yang digunakan.

### 5.2. Memperbarui Paket MSYS2

Pada terminal MSYS2 UCRT64, jalankan:

```bash
pacman -Syu
```

Perintah tersebut digunakan untuk memperbarui basis paket dan komponen MSYS2.

Jika proses pembaruan meminta terminal ditutup, tutup terminal sesuai instruksi, buka kembali MSYS2 UCRT64, kemudian jalankan pembaruan yang diminta. Ikuti petunjuk yang ditampilkan sampai proses selesai.

### 5.3. Memasang Toolchain MinGW-w64

Buka kembali terminal MSYS2 UCRT64 jika diperlukan.

Jalankan perintah:

```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

Keterangan:

- `pacman` adalah pengelola paket MSYS2.
- `-S` digunakan untuk memasang paket.
- `--needed` membantu menghindari pemasangan ulang paket yang sudah memenuhi kebutuhan.
- `base-devel` menyediakan sejumlah alat pengembangan.
- `mingw-w64-ucrt-x86_64-toolchain` adalah kelompok paket toolchain untuk lingkungan UCRT64 64-bit.

Jika diminta memilih paket atau mengonfirmasi instalasi, ikuti petunjuk terminal. Untuk pilihan default, tekan Enter jika sesuai, dan ketik `Y` apabila diminta menyetujui pemasangan.

Tunggu sampai proses selesai. Jangan menutup terminal saat pemasangan masih berlangsung.

### 5.4. Memeriksa Compiler di MSYS2

Masih dari terminal MSYS2 UCRT64, jalankan:

```bash
g++ --version
```

Kemudian:

```bash
gdb --version
```

Jika informasi versi ditampilkan, berarti masing-masing perintah berhasil ditemukan pada lingkungan tersebut.

Namun, ini belum membuktikan bahwa compiler sudah bisa diakses dari terminal VS Code. Kita akan menguji hal tersebut setelah konfigurasi PATH.

---

## 6. Konfigurasi PATH pada Windows

Bagian ini penting agar perintah `g++` dan `gdb` dapat dikenali dari terminal Windows maupun terminal terintegrasi VS Code.

### 6.1. Menentukan Lokasi Compiler

Jika MSYS2 dipasang di lokasi default dan toolchain yang digunakan adalah UCRT64, folder yang perlu ditambahkan adalah:

```text
C:\msys64\ucrt64\bin
```

Folder tersebut berisi executable toolchain, termasuk `g++.exe` jika pemasangan berhasil.

Pastikan lokasi ini sesuai dengan lokasi instalasi aktual di komputer.

### 6.2. Menambahkan Folder ke User Path

Ikuti langkah berikut:

1. Buka pencarian Windows.
2. Ketik `Edit environment variables for your account`.
3. Buka menu yang ditemukan.
4. Pada bagian **User variables**, pilih variabel `Path`.
5. Klik **Edit**.
6. Klik **New**.
7. Masukkan:

   ```text
   C:\msys64\ucrt64\bin
   ```

8. Klik **OK** pada jendela yang terbuka sampai semua perubahan tersimpan.

Disarankan mengubah User Path agar konfigurasi hanya berlaku untuk akun pengguna tersebut, tanpa perlu mengubah konfigurasi sistem secara keseluruhan.

**Penting:** Jangan menghapus entri PATH yang sudah ada. Cukup tambahkan direktori compiler sebagai entri baru.

### 6.3. Memuat Ulang Terminal

Setelah PATH diubah:

1. Tutup terminal Windows yang sedang terbuka.
2. Tutup terminal terintegrasi VS Code.
3. Buka kembali VS Code.
4. Pilih **Terminal → New Terminal**.

Terminal yang sudah terbuka sebelum perubahan PATH mungkin belum membaca nilai terbaru.

### 6.4. Menguji PATH

Pada terminal PowerShell di VS Code, jalankan:

```powershell
g++ --version
```

Lalu:

```powershell
gdb --version
```

Untuk memeriksa lokasi executable yang ditemukan Windows, gunakan:

```powershell
where.exe g++
```

Dan:

```powershell
where.exe gdb
```

Jika lokasi yang muncul sesuai dengan instalasi yang diharapkan, konfigurasi PATH kemungkinan sudah benar.

Jika perintah tidak dikenali, periksa kembali lokasi folder dan konfigurasi PATH sebelum melanjutkan.

---

## 7. Instalasi Ekstensi C/C++

Compiler dan ekstensi VS Code memiliki fungsi berbeda. Karena itu, keduanya perlu dikonfigurasi.

### 7.1. Memasang Ekstensi

1. Buka Visual Studio Code.
2. Klik menu **Extensions** pada sidebar.
3. Cari `C/C++`.
4. Pastikan penerbitnya adalah **Microsoft**.
5. Klik **Install**.

Ekstensi ini menyediakan dukungan bahasa C/C++, seperti IntelliSense, informasi diagnostik, dan integrasi debugging.

### 7.2. Apa yang Dilakukan Ekstensi?

Ekstensi membantu editor memahami struktur kode. Misalnya, ekstensi dapat memberikan saran nama variabel atau menandai kemungkinan kesalahan sintaks.

Namun, garis merah di editor tidak selalu sama dengan kegagalan kompilasi. Sebaliknya, tidak adanya garis merah juga tidak menjamin program bebas dari error.

Hasil kompilasi di terminal tetap perlu diperiksa.

### 7.3. Mengenali Terminal VS Code

Buka:

**Terminal → New Terminal**

Terminal ini dapat menggunakan PowerShell, Command Prompt, atau shell lain yang tersedia.

Untuk mengikuti contoh perintah dalam panduan ini, gunakan PowerShell. Perintah untuk menjalankan file `.exe` pada PowerShell sedikit berbeda dengan shell lain.

---

## 8. Membuat Project C++ Pertama

Sekarang kita akan membuat program sederhana untuk memastikan lingkungan C++ berfungsi.

### 8.1. Membuat Folder Project

Buat folder bernama:

```text
belajar-cpp
```

Sebagai contoh, lokasi foldernya adalah:

```text
C:\belajar-cpp
```

Buka VS Code, kemudian pilih:

**File → Open Folder**

Pilih folder `belajar-cpp` yang telah dibuat.

Membuka folder project membantu VS Code mengenali lokasi file dan membuat terminal bekerja dalam konteks direktori tersebut.

### 8.2. Membuat File `main.cpp`

Pada panel Explorer:

1. Klik ikon New File.
2. Masukkan nama `main.cpp`.
3. Tekan Enter.
4. Tulis kode berikut.

```cpp
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
```

Simpan file dengan menekan `Ctrl + S`.

### 8.3. Memahami Kode

| Bagian kode | Fungsi |
|---|---|
| `#include <iostream>` | Menyediakan fasilitas input dan output standar. |
| `#include <string>` | Menyediakan tipe data `string`. |
| `using namespace std;` | Memungkinkan penggunaan nama seperti `cout` dan `string` tanpa awalan `std::`. |
| `int main()` | Fungsi utama yang menjadi titik masuk program. |
| `string nama;` | Menyimpan teks nama pengguna. |
| `int angka1, angka2;` | Menyimpan dua bilangan bulat. |
| `getline(cin, nama)` | Membaca satu baris input untuk nama. |
| `cin >> angka1` | Membaca angka pertama. |
| `cout` | Menampilkan teks atau nilai ke output standar. |
| `angka1 + angka2` | Menghitung penjumlahan kedua angka. |
| `return 0;` | Mengakhiri fungsi `main` dengan status keberhasilan. |

---

## 9. Compile dan Menjalankan Program

Kita akan menggunakan terminal untuk mengompilasi dan menjalankan program secara manual.

Cara ini disarankan untuk mahasiswa pemula karena memperlihatkan proses kompilasi secara langsung.

### 9.1. Memastikan Terminal Berada di Folder yang Benar

Buka terminal VS Code dan jalankan:

```powershell
dir
```

Pastikan file `main.cpp` terlihat pada daftar file.

Jika file tidak terlihat, terminal mungkin berada di direktori yang salah. Buka folder project yang benar atau pindah ke direktori yang menyimpan file.

### 9.2. Mengompilasi Program

Jalankan:

```powershell
g++ main.cpp -o main.exe
```

Penjelasan perintah:

- `g++` memanggil compiler C++.
- `main.cpp` adalah file sumber yang dikompilasi.
- `-o` menentukan nama file output.
- `main.exe` adalah nama executable yang dihasilkan.

Jika kompilasi berhasil, terminal biasanya kembali ke prompt tanpa menampilkan pesan error.

Periksa folder project. Seharusnya terdapat file:

```text
main.cpp
main.exe
```

Jika muncul pesan error, baca pesan tersebut dan periksa kode atau konfigurasi sebelum mencoba menjalankan program.

### 9.3. Menjalankan Program

Pada terminal PowerShell, jalankan:

```powershell
.\main.exe
```

Contoh interaksi:

```text
=== Program Pertama C++ ===
Masukkan nama: Budi
Masukkan angka pertama: 10
Masukkan angka kedua: 20

Halo, Budi!
Hasil penjumlahan: 30
```

Jika hasil serupa muncul, program berhasil dijalankan.

Angka dan nama yang ditampilkan dapat berbeda sesuai input mahasiswa.

### 9.4. Perbedaan Compile dan Run

**Compile** berarti menerjemahkan kode sumber menjadi executable.

```powershell
g++ main.cpp -o main.exe
```

**Run** berarti menjalankan executable yang dihasilkan.

```powershell
.\main.exe
```

Jika kode sumber diubah, lakukan kompilasi ulang agar executable mencerminkan perubahan terbaru.

### 9.5. Mengapa Menggunakan Terminal Terlebih Dahulu?

Tombol Run dari ekstensi tambahan atau konfigurasi tertentu terkadang menyembunyikan sebagian proses kompilasi. Untuk tahap awal pembelajaran, menjalankan perintah secara manual membantu mahasiswa mengenali:

- Perintah compiler yang digunakan.
- Nama file sumber yang dikompilasi.
- Nama executable yang dihasilkan.
- Pesan error yang muncul saat kompilasi gagal.

Setelah memahami proses ini, mahasiswa dapat mempelajari build task dan debugging melalui VS Code.

---

## 10. Memahami Proses Kompilasi

Secara konseptual, proses build C++ terdiri atas beberapa tahap:

1. **Preprocessing:** memproses direktif seperti `#include` dan makro.
2. **Compilation:** menerjemahkan kode yang telah diproses menjadi kode tingkat lebih rendah.
3. **Assembly:** menghasilkan object file dari kode assembly.
4. **Linking:** menghubungkan object file dengan komponen atau library yang diperlukan untuk menghasilkan executable.

Pada penggunaan sehari-hari, perintah `g++` biasanya menjalankan tahapan tersebut secara otomatis.

Sebagai contoh:

```powershell
g++ main.cpp -o main.exe
```

Mahasiswa tidak perlu menjalankan setiap tahapan secara manual untuk program sederhana.

### Perbedaan Error Kompilasi dan Error Saat Program Berjalan

**Error kompilasi** terjadi ketika compiler tidak dapat membangun program, misalnya karena kesalahan sintaks.

Contoh:

```cpp
cout << "Hello"
```

Jika tidak ada tanda titik koma pada akhir pernyataan, compiler dapat memberikan pesan error.

**Error saat runtime** terjadi ketika executable berhasil dibuat, tetapi program mengalami masalah ketika dijalankan.

Contohnya, program yang melakukan operasi pembagian dengan nilai nol perlu ditangani dengan benar agar tidak menghasilkan perilaku yang tidak diharapkan.

Memahami perbedaan ini membantu mahasiswa menentukan apakah masalahnya berada pada kode sumber, proses kompilasi, atau logika program.

---

## 11. Troubleshooting dan Solusi Error

Bagian ini berisi beberapa masalah yang sering muncul ketika menyiapkan lingkungan C++.

Pesan error dapat berbeda menurut versi compiler, terminal, dan konfigurasi komputer. Gunakan pesan yang tampil sebagai petunjuk untuk melakukan pemeriksaan.

### 11.1. Error: `g++ is not recognized`

Contoh pesan:

```text
'g++' is not recognized as an internal
or external command, operable program or batch file.
```

**Penyebab yang mungkin:**

- Compiler belum dipasang.
- Toolchain yang dipasang tidak menyertakan `g++`.
- Folder compiler belum ditambahkan ke PATH.
- Terminal belum dimulai ulang setelah perubahan PATH.

**Solusi:**

1. Pastikan instalasi toolchain MinGW-w64 telah selesai.
2. Periksa keberadaan `g++.exe` di folder `C:\msys64\ucrt64\bin`.
3. Pastikan folder tersebut sudah tercantum pada User Path.
4. Buka terminal baru.
5. Jalankan `g++ --version`.

Jika masih gagal, jalankan:

```powershell
where.exe g++
```

Jika tidak ada lokasi yang ditampilkan, Windows belum menemukan executable melalui PATH.

### 11.2. Error: `fatal error: iostream: No such file or directory`

Contoh:

```text
fatal error: iostream: No such file or directory
```

**Penyebab yang mungkin:**

- Toolchain C++ belum terpasang lengkap.
- Compiler yang dipanggil berasal dari instalasi yang berbeda.
- Konfigurasi compiler atau header standar bermasalah.

**Solusi:**

1. Jalankan `where.exe g++` untuk memeriksa lokasi compiler.
2. Pastikan compiler yang ditemukan sesuai dengan instalasi MSYS2 yang digunakan.
3. Periksa apakah toolchain UCRT64 terpasang dengan benar.
4. Jika perlu, perbaiki instalasi paket melalui MSYS2.

Jangan langsung mengunduh file `iostream` dari internet. Header tersebut merupakan bagian dari library standar C++ yang disediakan toolchain.

### 11.3. Error: `main.cpp: No such file or directory`

Contoh:

```text
cc1plus: fatal error: main.cpp: No such file or directory
compilation terminated.
```

**Penyebab yang mungkin:**

- Terminal berada di folder yang salah.
- File tersimpan dengan nama berbeda.
- Ekstensi file bukan `.cpp`.

**Solusi:**

Periksa isi direktori:

```powershell
dir
```

Pastikan `main.cpp` muncul. Jika belum, buka folder project yang benar atau gunakan path file yang sesuai.

Periksa juga apakah file sebenarnya bernama `main.cpp.txt`.

### 11.4. Error: `expected ';' before ...`

Contoh kode yang salah:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello"
    return 0;
}
```

Pesan error dapat menunjukkan lokasi dekat `return`, meskipun penyebabnya adalah tanda titik koma yang hilang pada baris sebelumnya.

**Solusi:**

Perbaiki menjadi:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello";
    return 0;
}
```

Jika pesan error menunjuk satu baris, periksa juga baris sebelumnya karena lokasi error yang ditampilkan tidak selalu tepat pada sumber masalah.

### 11.5. Error: `undefined reference to 'main'`

**Penyebab yang mungkin:**

- Fungsi `main()` tidak tersedia atau salah ditulis.
- File yang dikompilasi bukan file yang berisi fungsi utama.
- Ada masalah pada proses linking atau perintah build.

**Solusi:**

Pastikan file memiliki fungsi utama yang valid, misalnya:

```cpp
int main() {
    return 0;
}
```

Kemudian periksa kembali perintah kompilasi dan file sumber yang digunakan.

### 11.6. Error: `undefined reference to ...`

Error ini umumnya berasal dari linker yang tidak menemukan definisi simbol atau fungsi yang dibutuhkan.

**Penyebab yang mungkin:**

- Fungsi dideklarasikan tetapi implementasinya tidak tersedia.
- File sumber lain belum ikut dikompilasi.
- Library yang dibutuhkan belum dihubungkan.
- Nama fungsi atau tanda tangan fungsi tidak sesuai.

**Solusi:**

Periksa apakah implementasi fungsi tersedia dan semua file sumber yang dibutuhkan ikut dalam perintah build.

Untuk program sederhana yang hanya menggunakan `main.cpp`, mulai dengan:

```powershell
g++ main.cpp -o main.exe
```

Jika project terdiri atas beberapa file `.cpp`, sesuaikan perintah agar seluruh file yang diperlukan ikut dikompilasi dan dihubungkan.

### 11.7. Error: Executable Tidak Ditemukan

Contoh:

```text
The term '.\main.exe' is not recognized...
```

**Penyebab yang mungkin:**

- Proses kompilasi belum berhasil.
- File output memiliki nama berbeda.
- Terminal berada di direktori yang salah.

**Solusi:**

1. Jalankan `dir`.
2. Periksa apakah `main.exe` tersedia.
3. Jika tidak tersedia, lakukan kompilasi ulang.
4. Periksa pesan error compiler sebelum menjalankan executable.

Jangan menganggap file executable pasti terbentuk hanya karena perintah compile sudah dijalankan.

### 11.8. Program Berjalan, tetapi Tidak Menampilkan Output

**Penyebab yang mungkin:**

- Program sedang menunggu input pengguna.
- Program tidak memiliki perintah output yang sesuai.
- Program keluar sebelum mencapai bagian output.
- Output tidak ditampilkan sesuai alur logika program.

**Solusi:**

Periksa apakah program meminta input melalui `cin` atau `getline`. Masukkan nilai sesuai permintaan program.

Jika program tetap tidak menampilkan output, periksa alur kode dan pastikan perintah output dapat dijalankan.

### 11.9. IntelliSense Menampilkan Garis Merah

Garis merah pada editor tidak selalu berarti compiler gagal.

**Penyebab yang mungkin:**

- Ekstensi belum mendeteksi compiler yang benar.
- Konfigurasi IntelliSense belum sesuai.
- File atau include path belum dikenali.
- Kode memang memiliki kesalahan.

**Solusi:**

1. Pastikan ekstensi C/C++ dari Microsoft sudah terpasang.
2. Jalankan `g++ --version`.
3. Gunakan Command Palette (`Ctrl + Shift + P`).
4. Cari `C/C++: Select IntelliSense Configuration` atau `C/C++: Edit Configurations (UI)`.
5. Pilih compiler yang benar, jika tersedia.

Jika editor menunjukkan garis merah, tetapi compiler berhasil membangun program, periksa konfigurasi IntelliSense dan pesan diagnostiknya secara terpisah.

### 11.10. Error: `The value of miDebuggerPath is invalid`

Pesan ini dapat muncul ketika konfigurasi debugging menggunakan lokasi debugger yang salah atau debugger tidak ditemukan.

**Solusi:**

1. Jalankan `gdb --version`.
2. Pastikan GDB terpasang.
3. Periksa apakah lokasi `gdb.exe` berada di dalam direktori toolchain yang diharapkan.
4. Jika konfigurasi debugging menyimpan path tertentu, pastikan path tersebut sesuai dengan instalasi aktual.

Jika `g++` tersedia tetapi `gdb` tidak ditemukan, periksa pemasangan komponen debugger pada toolchain MSYS2.

### 11.11. Error: `Permission denied` atau Executable Tidak Dapat Ditimpa

**Penyebab yang mungkin:**

- File executable sedang digunakan oleh proses lain.
- File output tidak dapat ditulis pada lokasi tersebut.
- Folder project memiliki pembatasan izin.

**Solusi:**

1. Hentikan program yang sedang berjalan.
2. Pastikan file output tidak sedang digunakan.
3. Periksa lokasi project dan izin tulis folder.
4. Coba kompilasi kembali setelah masalah teratasi.

Jika pesan error berbeda, jangan langsung menghapus banyak file atau mengubah konfigurasi sistem. Identifikasi penyebabnya terlebih dahulu.

### 11.12. Perintah `pacman` Gagal Saat Instalasi

Jika pemasangan paket gagal, periksa pesan yang ditampilkan MSYS2.

**Kemungkinan penyebab:**

- Koneksi internet bermasalah.
- Pembaruan MSYS2 belum selesai.
- Terminal yang digunakan bukan lingkungan yang diharapkan.
- Terjadi masalah sinkronisasi atau pengunduhan paket.

**Solusi:**

1. Pastikan koneksi internet berfungsi.
2. Ikuti instruksi pembaruan yang ditampilkan MSYS2.
3. Pastikan terminal yang digunakan adalah MSYS2 UCRT64.
4. Ulangi perintah instalasi setelah masalah teratasi.

Jangan menjalankan perintah instalasi dari PowerShell biasa jika instruksi mengharuskan perintah tersebut dijalankan melalui terminal MSYS2.

### 11.13. Cara Melaporkan Error kepada Asisten Praktikum

Jika masalah belum teratasi, siapkan informasi berikut:

- Pesan error lengkap dari terminal.
- Perintah yang dijalankan.
- Nama dan lokasi file yang dikompilasi.
- Hasil `g++ --version`.
- Hasil `where.exe g++` jika perintah tersedia.
- Screenshot terminal dan bagian kode yang relevan.

Informasi tersebut membantu proses diagnosis agar tidak hanya menebak penyebab masalah.

---

## 12. Tips Penggunaan VS Code untuk Praktikum

### 12.1. Gunakan Folder Project yang Jelas

Simpan file berdasarkan pertemuan atau materi praktikum.

Contoh:

```text
algoritma-pemrograman/
├── pertemuan-01/
│   ├── main.cpp
│   └── latihan.cpp
├── pertemuan-02/
│   ├── percabangan.cpp
│   └── latihan.cpp
└── pertemuan-03/
    ├── perulangan.cpp
    └── latihan.cpp
```

Struktur tersebut hanya contoh. Sesuaikan dengan kebutuhan mata kuliah.

### 12.2. Gunakan Nama File yang Bermakna

Contoh:

- `variabel.cpp`
- `percabangan.cpp`
- `perulangan.cpp`
- `fungsi.cpp`
- `array.cpp`

Nama file yang jelas memudahkan mahasiswa mengenali materi yang sedang dipelajari.

### 12.3. Periksa Pesan Error Sebelum Meminta Bantuan

Jika program gagal dikompilasi:

1. Baca pesan error pertama yang relevan.
2. Periksa nomor baris yang ditampilkan.
3. Periksa baris tersebut dan baris sebelumnya.
4. Pastikan file sudah disimpan.
5. Coba kompilasi ulang setelah melakukan perbaikan.

Kebiasaan ini membantu mahasiswa memahami proses debugging sejak awal.

### 12.4. Jangan Bergantung pada Tombol Run

Tombol Run dapat berasal dari ekstensi atau konfigurasi build yang berbeda. Untuk pembelajaran awal, pahami terlebih dahulu perintah compile dan run melalui terminal.

Setelah itu, mahasiswa dapat mempelajari konfigurasi build task dan debugger jika dibutuhkan.

---

## 13. Latihan Mandiri

Setelah menyelesaikan instalasi dan berhasil menjalankan program pertama, kerjakan latihan berikut.

### Latihan 1 — Identitas Mahasiswa

Buat program yang menampilkan:

- Nama.
- NIM.
- Program studi.
- Nama mata kuliah.

Gunakan `cout` untuk menampilkan informasi.

### Latihan 2 — Operasi Aritmetika

Buat program yang menerima dua bilangan bulat, kemudian menampilkan hasil:

- Penjumlahan.
- Pengurangan.
- Perkalian.

### Latihan 3 — Mengenali Error Sintaks

Ubah program secara sengaja dengan menghilangkan satu tanda titik koma.

Kompilasi program dan amati pesan error yang muncul.

Setelah itu, perbaiki kode dan kompilasi ulang.

Tujuan latihan ini adalah mengenali bahwa pesan compiler dapat membantu menunjukkan letak masalah.

### Latihan 4 — Memahami Compile dan Run

Lakukan langkah berikut:

1. Buat file `latihan.cpp`.
2. Kompilasi menjadi `latihan.exe`.
3. Jalankan program.
4. Ubah teks output pada kode.
5. Simpan dan kompilasi ulang.
6. Jalankan kembali executable.

Amati apa yang terjadi jika mahasiswa hanya menyimpan perubahan tanpa melakukan kompilasi ulang.

---

## 14. Checklist Keberhasilan Instalasi

Gunakan checklist berikut untuk memastikan lingkungan pemrograman siap digunakan.

- [ ] Visual Studio Code berhasil dipasang dan dibuka.
- [ ] Ekstensi C/C++ dari Microsoft sudah terpasang.
- [ ] MSYS2 berhasil dipasang.
- [ ] Toolchain MinGW-w64 UCRT64 berhasil dipasang.
- [ ] Folder `C:\msys64\ucrt64\bin` sudah ditambahkan ke User Path, jika menggunakan lokasi default.
- [ ] Perintah `g++ --version` berhasil dijalankan dari terminal VS Code.
- [ ] Perintah `gdb --version` berhasil dijalankan jika debugging akan digunakan.
- [ ] File `main.cpp` berhasil dibuat dan disimpan.
- [ ] Perintah `g++ main.cpp -o main.exe` berhasil dijalankan.
- [ ] File `main.exe` berhasil dihasilkan.
- [ ] Program berhasil dijalankan melalui `.\main.exe`.
- [ ] Mahasiswa memahami perbedaan antara compile dan run.

Jika seluruh langkah yang relevan berhasil dilakukan, lingkungan dasar C++ sudah siap digunakan untuk praktikum.

---

## 15. Referensi Resmi

Gunakan dokumentasi resmi berikut untuk mempelajari lebih lanjut atau memeriksa pembaruan instruksi instalasi.

1. **Visual Studio Code** — situs unduhan dan informasi editor  
   https://code.visualstudio.com/

2. **VS Code: Using GCC with MinGW** — panduan konfigurasi C++ pada Windows  
   https://code.visualstudio.com/docs/cpp/config-mingw

3. **VS Code: C/C++ Extension** — dokumentasi ekstensi C/C++  
   https://code.visualstudio.com/docs/languages/cpp

4. **MSYS2** — situs resmi dan instruksi instalasi  
   https://www.msys2.org/

5. **MSYS2: Environments** — penjelasan perbedaan lingkungan UCRT64, MINGW64, dan lainnya  
   https://www.msys2.org/docs/environments/

6. **MSYS2: Package Management** — dokumentasi pengelolaan paket melalui `pacman`  
   https://www.msys2.org/docs/package-management/

Instruksi instalasi dan versi software dapat berubah. Jika terdapat perbedaan antara panduan ini dan dokumentasi resmi terbaru, periksa dokumentasi resmi sebelum melanjutkan.

---

## Penutup

Menyiapkan lingkungan pemrograman merupakan langkah awal sebelum mempelajari algoritma dan pemecahan masalah menggunakan C++.

Dengan memahami fungsi editor, compiler, PATH, proses kompilasi, serta cara membaca error, mahasiswa diharapkan dapat lebih mandiri saat mengikuti praktikum.

Jangan hanya berfokus pada apakah program berhasil dijalankan. Pahami juga bagaimana kode sumber diubah menjadi executable dan bagaimana pesan error dapat digunakan untuk menemukan masalah.

**Selamat belajar dan selamat mencoba C++!**
