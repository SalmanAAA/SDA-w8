#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

// Membuat node baru untuk DLL
NodeDLL* createNodeDLL(Peminjaman data) {
    NodeDLL* newNode = (NodeDLL*) malloc(sizeof(NodeDLL));
    if (newNode == NULL) {
        printf("Error: Gagal mengalokasikan memori!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Menambahkan data ke DLL dengan mempertimbangkan prioritas
void insertDLL(NodeDLL** head, NodeDLL** tail, Peminjaman data) {
    NodeDLL* newNode = createNodeDLL(data);
    
    // Jika list kosong
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
    
    // Jika prioritas baru lebih tinggi dari head
    if (data.tipeAnggota > (*head)->data.tipeAnggota) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    
    // Temukan posisi yang tepat berdasarkan prioritas
    NodeDLL* current = *head;
    while (current->next != NULL && current->next->data.tipeAnggota >= data.tipeAnggota) {
        current = current->next;
    }
    
    // Jika menyisipkan di ujung list
    if (current->next == NULL) {
        current->next = newNode;
        newNode->prev = current;
        *tail = newNode;
    } else {
        // Sisipkan di tengah list
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Menghapus node pertama di DLL
int deleteFirstDLL(NodeDLL** head, NodeDLL** tail) {
    if (*head == NULL) {
        return 0; // List kosong
    }
    
    NodeDLL* temp = *head;
    
    // Jika hanya ada satu node
    if (*head == *tail) {
        *head = NULL;
        *tail = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    
    free(temp);
    return 1; // Berhasil dihapus
}

// Menghapus node berdasarkan ID di DLL
int deleteByIDDLL(NodeDLL** head, NodeDLL** tail, int id) {
    if (*head == NULL) {
        return 0; // List kosong
    }
    
    // Jika node yang dihapus adalah head
    if ((*head)->data.id == id) {
        return deleteFirstDLL(head, tail);
    }
    
    // Jika node yang dihapus adalah tail
    if ((*tail)->data.id == id) {
        NodeDLL* temp = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        free(temp);
        return 1; // Berhasil dihapus
    }
    
    // Cari node dengan ID yang sesuai
    NodeDLL* current = *head;
    while (current != NULL && current->data.id != id) {
        current = current->next;
    }
    
    // Jika ID tidak ditemukan
    if (current == NULL) {
        return 0;
    }
    
    // Hapus node dari tengah list
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return 1; // Berhasil dihapus
}

// Menampilkan seluruh data di DLL
void displayDLL(NodeDLL* head) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }
    
    NodeDLL* current = head;
    int i = 1;
    
    printf("%-5s %-20s %-30s %-10s %-20s\n", "No.", "Nama Peminjam", "Judul Buku", "Stok", "Tipe Anggota");
    printf("---------------------------------------------------------------------------------\n");
    
    while (current != NULL) {
        printf("%-5d %-20s %-30s %-10d %-20s\n", 
               i++, 
               current->data.namaPeminjam, 
               current->data.judulBuku, 
               current->data.stokBuku, 
               getNamaTipeAnggota(current->data.tipeAnggota));
        current = current->next;
    }
}

// Memeriksa apakah DLL kosong
int isEmptyDLL(NodeDLL* head) {
    return head == NULL;
}

// Menu untuk Double Linked List
void menuDLL(NodeDLL** head, NodeDLL** tail) {
    int pilihan;
    
    do {
        printf("\n===== MENU DOUBLE LINKED LIST =====\n");
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
                insertDLL(head, tail, pinjaman);
                printf("Peminjaman berhasil ditambahkan ke DLL!\n");
                break;
            }
            case 2:
                if (isEmptyDLL(*head)) {
                    printf("List peminjaman kosong!\n");
                } else {
                    deleteFirstDLL(head, tail);
                    printf("Peminjaman teratas berhasil dihapus dari DLL!\n");
                }
                break;
            case 3:
                if (isEmptyDLL(*head)) {
                    printf("List peminjaman kosong!\n");
                } else {
                    int id;
                    printf("Masukkan ID peminjaman yang akan dihapus: ");
                    scanf("%d", &id);
                    getchar(); // mengonsumsi karakter newline
                    
                    if (deleteByIDDLL(head, tail, id)) {
                        printf("Peminjaman dengan ID %d berhasil dihapus dari DLL!\n", id);
                    } else {
                        printf("Peminjaman dengan ID %d tidak ditemukan!\n", id);
                    }
                }
                break;
            case 4:
                printf("\n===== DAFTAR PEMINJAMAN (DLL) =====\n");
                displayDLL(*head);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}