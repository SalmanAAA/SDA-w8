#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Membuat node baru untuk SLL
NodeSLL* createNodeSLL(Peminjaman data) {
    NodeSLL* newNode = (NodeSLL*) malloc(sizeof(NodeSLL));
    if (newNode == NULL) {
        printf("Error: Gagal mengalokasikan memori!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Menambahkan data ke SLL dengan mempertimbangkan prioritas
void insertSLL(NodeSLL** head, Peminjaman data) {
    NodeSLL* newNode = createNodeSLL(data);

    if (*head == NULL || data.tipeAnggota > (*head)->data.tipeAnggota) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    NodeSLL* current = *head;
    while (current->next != NULL && current->next->data.tipeAnggota >= data.tipeAnggota) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Menghapus node pertama di SLL
int deleteFirstSLL(NodeSLL** head) {
    if (*head == NULL) return 0;

    NodeSLL* temp = *head;
    *head = (*head)->next;
    free(temp);
    return 1;
}

// Menghapus berdasarkan ID
int deleteByIDSLL(NodeSLL** head, int id) {
    if (*head == NULL) return 0;

    if ((*head)->data.id == id) {
        NodeSLL* temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    NodeSLL* current = *head;
    while (current->next != NULL && current->next->data.id != id) {
        current = current->next;
    }

    if (current->next == NULL) return 0;

    NodeSLL* temp = current->next;
    current->next = temp->next;
    free(temp);
    return 1;
}

// Menampilkan seluruh data dalam SLL
void displaySLL(NodeSLL* head) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    NodeSLL* current = head;
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

int isEmptySLL(NodeSLL* head) {
    return head == NULL;
}

// Menu interaktif
void menuSLL(NodeSLL** head) {
    int pilihan;

    do {
        printf("\n===== MENU SINGLE LINKED LIST =====\n");
        printf("1. Tambah Peminjaman\n");
        printf("2. Hapus Peminjaman Teratas\n");
        printf("3. Hapus Peminjaman Target\n");
        printf("4. Tampilkan Peminjaman\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("Pilihan Anda: ");
        
        scanf("%d", &pilihan);
        getchar(); // mengonsumsi newline

        switch (pilihan) {
            case 1: {
                Peminjaman pinjaman = inputPeminjaman();
                insertSLL(head, pinjaman);
                printf("Peminjaman berhasil ditambahkan ke SLL!\n");
                break;
            }
            case 2:
                if (isEmptySLL(*head)) {
                    printf("List peminjaman kosong!\n");
                } else {
                    deleteFirstSLL(head);
                    printf("Peminjaman teratas berhasil dihapus dari SLL!\n");
                }
                break;
            case 3:
                if (isEmptySLL(*head)) {
                    printf("List peminjaman kosong!\n");
                } else {
                    int id;
                    printf("Masukkan ID peminjaman yang akan dihapus: ");
                    scanf("%d", &id);
                    getchar();
                    
                    if (deleteByIDSLL(head, id)) {
                        printf("Peminjaman dengan ID %d berhasil dihapus dari SLL!\n", id);
                    } else {
                        printf("Peminjaman dengan ID %d tidak ditemukan!\n", id);
                    }
                }
                break;
            case 4:
                printf("\n===== DAFTAR PEMINJAMAN (SLL) =====\n");
                displaySLL(*head);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}
