#include <stdio.h>

int main() {
    int jumlahSiswa;
    char nama[100][50];
    int nilai[100];
    int totalNilai = 0;
    float rataRata;

    printf("Masukkan jumlah siswa: ");
    scanf("%d", &jumlahSiswa);

    // Input data siswa
    for (int i = 0; i < jumlahSiswa; i++) {
        printf("\nData Siswa ke-%d\n", i + 1);

        printf("Nama Siswa : ");
        scanf(" %[^\n]", nama[i]); // membaca string dengan spasi

        printf("Nilai Siswa: ");
        scanf("%d", &nilai[i]);

        totalNilai += nilai[i];
    }

    // Hitung rata-rata
    rataRata = (float)totalNilai / jumlahSiswa;

    // Tampilkan laporan
    printf("\n========================================");
    printf("\n        LAPORAN DATA SISWA");
    printf("\n========================================");
    printf("\n%-5s %-20s %-10s %-15s\n", "No", "Nama", "Nilai", "Status");

    for (int i = 0; i < jumlahSiswa; i++) {
        char status[20];

        if (nilai[i] >= 75) {
            sprintf(status, "Lulus");
        } else {
            sprintf(status, "Tidak Lulus");
        }

        printf("%-5d %-20s %-10d %-15s\n",
               i + 1, nama[i], nilai[i], status);
    }

    printf("========================================\n");
    printf("Total Nilai      : %d\n", totalNilai);
    printf("Rata-rata Kelas  : %.2f\n", rataRata);
    printf("========================================\n");

    return 0;
}
