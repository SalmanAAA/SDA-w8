#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Menambahkan data ke array dan mengurutkan berdasarkan prioritas
int insertArray(Peminjaman array[], int* count, Peminjaman data) {
    if (*count >= MAX_ARRAY) {
        return 0; // Array penuh
    }
    
    // Tambahkan data baru
    array[*count] = data;
    (*count)++;
    
    // Urutkan array berdasarkan prioritas (bubble sort)
    for (int i = 0; i < *count - 1; i++) {
        for (int j = 0; j < *count - i - 1; j++) {
            if (array[j].tipeAnggota < array[j + 1].tipeAnggota) {
                // Tukar posisi
                Peminjaman temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    return 1; // Berhasil ditambahkan
}

// Menghapus data pertama dari array
int deleteFirstArray(Peminjaman array[], int* count) {
    if (*count <= 0) {
        return 0; // Array kosong
    }
    
    // Geser semua elemen ke kiri
    for (int i = 0; i < *count - 1; i++) {
        array[i] = array[i + 1];
    }
    
    (*count)--;
    return 1; // Berhasil dihapus
}

// Menghapus data berdasarkan ID dari array
int deleteByIDArray(Peminjaman array[], int* count, int id) {
    if (*count <= 0) {
        return 0; // Array kosong
    }
    
    // Cari indeks data dengan ID yang sesuai
    int indexToDelete = -1;
    for (int i = 0; i < *count; i++) {
        if (array[i].id == id) {
            indexToDelete = i;
            break;
        }
    }
    
    // Jika ID tidak ditemukan
    if (indexToDelete == -1) {
        return 0;
    }
    
    // Geser semua elemen setelah indeks yang dihapus
    for (int i = indexToDelete; i < *count - 1; i++) {
        array[i] = array[i + 1];
    }
    
    (*count)--;
    return 1; // Berhasil dihapus
}

// Menampilkan seluruh data di array
void displayArray(Peminjaman array[], int count) {
    if (count <= 0) {
        printf("Array kosong!\n");
        return;
    }
    
    printf("%-5s %-20s %-30s %-10s %-20s\n", "No.", "Nama Peminjam", "Judul Buku", "Stok", "Tipe Anggota");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-30s %-10d %-20s\n", 
               i + 1, 
               array[i].namaPeminjam, 
               array[i].judulBuku, 
               array[i].stokBuku, 
               getNamaTipeAnggota(array[i].tipeAnggota));
    }
}

// Menu untuk Array
void menuArray(Peminjaman array[], int* count) {
    int pilihan;
    
    do {
        printf("\n===== MENU ARRAY =====\n");
        printf("1. Tambah Peminjaman\n");
        printf("2. Hapus Peminjaman Teratas\n");
        printf("3. Hapus Peminjaman Target\n");
        printf("4. Tampilkan Peminjaman\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("Pilihan Anda: ");
        
        scanf("%d", &pilihan);
        getchar(); // mengonsumsi karakter newline
        
        switch (pilihan) {
            case 1: {
                Peminjaman pinjaman = inputPeminjaman();
                if (insertArray(array, count, pinjaman)) {
                    printf("Peminjaman berhasil ditambahkan ke Array!\n");
                } else {
                    printf("Array penuh! Tidak dapat menambahkan peminjaman baru.\n");
                }
                break;
            }
            case 2:
                if (*count <= 0) {
                    printf("Array peminjaman kosong!\n");
                } else {
                    deleteFirstArray(array, count);
                    printf("Peminjaman teratas berhasil dihapus dari Array!\n");
                }
                break;
            case 3:
                if (*count <= 0) {
                    printf("Array peminjaman kosong!\n");
                } else {
                    int id;
                    printf("Masukkan ID peminjaman yang akan dihapus: ");
                    scanf("%d", &id);
                    getchar(); // mengonsumsi karakter newline
                    
                    if (deleteByIDArray(array, count, id)) {
                        printf("Peminjaman dengan ID %d berhasil dihapus dari Array!\n", id);
                    } else {
                        printf("Peminjaman dengan ID %d tidak ditemukan!\n", id);
                    }
                }
                break;
            case 4:
                printf("\n===== DAFTAR PEMINJAMAN (ARRAY) =====\n");
                displayArray(array, *count);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}
