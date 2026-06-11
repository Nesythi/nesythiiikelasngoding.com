#include <stdio.h>
#include <string.h>a
// Model Data
struct Mahasiswa {
char nama[50];
float nilai;
char grade;
};
int main() {
int n, i, j;
struct Mahasiswa mhs[100];
struct Mahasiswa temp;
float totalNilai = 0, rataRata;
float maxNilai, minNilai;
int lulus = 0, tidakLulus = 0;
printf("===DATA MAHASISWA MAHASISWI ===\n");
printf("Masukkan jumlah mahasiswa: ");
scanf("%d", &n);
getchar(); // Membersihkan buffer newline
// 1. INPUT DATA (Gabungan logika Gambar 1 & 4)
for(i = 0; i < n; i++) {
printf("\nData Mahasiswa ke-%d\n", i + 1);
printf("Nama: ");
fgets(mhs[i].nama, sizeof(mhs[i].nama), stdin);
mhs[i].nama[strcspn(mhs[i].nama, "\n")] = 0; // Menghapus newline
// Validasi Nilai (Logika Gambar 4)
do {
printf("Nilai (0-100): ");

2

scanf("%f", &mhs[i].nilai);
getchar(); // Bersihkan buffer
if(mhs[i].nilai < 0 || mhs[i].nilai > 100) {
printf("ERROR: Nilai harus antara 0-100!\n");
}
} while(mhs[i].nilai < 0 || mhs[i].nilai > 100);
// Penentuan Grade & Status Kelulusan (Logika Gambar 2 & 4)
if(mhs[i].nilai >= 85) mhs[i].grade = 'A';
else if(mhs[i].nilai >= 70) mhs[i].grade = 'B';
else if(mhs[i].nilai >= 60) mhs[i].grade = 'C';
else if(mhs[i].nilai >= 50) mhs[i].grade = 'D';
else mhs[i].grade = 'E';
if(mhs[i].nilai >= 60) lulus++;
else tidakLulus++;
totalNilai += mhs[i].nilai;
// Inisialisasi max/min pada data pertama
if(i == 0) {
maxNilai = mhs[i].nilai;
minNilai = mhs[i].nilai;
} else {
if(mhs[i].nilai > maxNilai) maxNilai = mhs[i].nilai;
if(mhs[i].nilai < minNilai) minNilai = mhs[i].nilai;
}
}
// 2. SORTING - Bubble Sort Descending (Logika Gambar 2)
for(i = 0; i < n - 1; i++) {
for(j = 0; j < n - i - 1; j++) {
if(mhs[j].nilai < mhs[j+1].nilai) {
temp = mhs[j];
mhs[j] = mhs[j+1];
mhs[j+1] = temp;
}
}
}
// 3. OUTPUT ANALISIS (Logika Gambar 3)

3

rataRata = totalNilai / n;
printf("\n======================================\n");
printf(" ANALISIS DATA MAHASISWA \n");
printf("======================================\n");
printf("Rata-rata Nilai : %.2f\n", rataRata);
printf("Nilai Tertinggi : %.2f\n", maxNilai);
printf("Nilai Terendah : %.2f\n", minNilai);
printf("Jumlah Lulus : %d\n", lulus);
printf("Jumlah Gagal : %d\n", tidakLulus);
// 4. OUTPUT TABEL (Logika Gambar 1 & 2)
printf("\n======================================\n");
printf(" NO | NAMA | NILAI | PREDIKAT \n");
printf("--------------------------------------\n");
for(i = 0; i < n; i++) {
printf(" %-2d | %-14s | %-5.2f | %-5c \n",
i + 1, mhs[i].nama, mhs[i].nilai, mhs[i].grade);
}
printf("======================================\n");
return 0;
}
