#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

// Enum untuk tipe anggota perpustakaan
typedef enum {
    MASYARAKAT = 1,  // Prioritas terendah
    MAHASISWA = 2,
    DOSEN = 3        // Prioritas tertinggi
} TipeAnggota;

// Struktur data untuk informasi peminjaman
typedef struct {
    int id;
    char namaPeminjam[50];
    char judulBuku[100];
    int stokBuku;
    TipeAnggota tipeAnggota;
} Peminjaman;

// Fungsi untuk mendapatkan nama tipe anggota
const char* getNamaTipeAnggota(TipeAnggota tipe);

// Fungsi untuk input data peminjaman
Peminjaman inputPeminjaman();

#endif /* PEMINJAMAN_H */