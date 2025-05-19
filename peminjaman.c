#include <stdio.h>
#include <stdlib.h>
#include "peminjaman.h"

// Fungsi untuk mendapatkan nama tipe anggota
const char* getNamaTipeAnggota(TipeAnggota tipe) {
    switch (tipe) {
        case MASYARAKAT:
            return "Masyarakat Umum";
        case MAHASISWA:
            return "Mahasiswa";
        case DOSEN:
            return "Dosen";
        default:
            return "Tidak dikenal";
    }
}

// Fungsi untuk input data peminjaman
Peminjaman inputPeminjaman() {
    static int idCounter = 1;
    Peminjaman pinjaman;
    int pilihan;
    
    pinjaman.id = idCounter++;
    
    printf("Masukkan nama peminjam: ");
    scanf(" %[^\n]", pinjaman.namaPeminjam);
    
    printf("Masukkan judul buku: ");
    scanf(" %[^\n]", pinjaman.judulBuku);
    
    printf("Masukkan stok buku: ");
    scanf("%d", &pinjaman.stokBuku);
    
    printf("Pilih tipe anggota:\n");
    printf("1. Masyarakat Umum\n");
    printf("2. Mahasiswa\n");
    printf("3. Dosen\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    
    switch (pilihan) {
        case 1:
            pinjaman.tipeAnggota = MASYARAKAT;
            break;
        case 2:
            pinjaman.tipeAnggota = MAHASISWA;
            break;
        case 3:
            pinjaman.tipeAnggota = DOSEN;
            break;
        default:
            printf("Pilihan tidak valid. Defaultnya adalah Masyarakat Umum.\n");
            pinjaman.tipeAnggota = MASYARAKAT;
    }
    
    return pinjaman;
}