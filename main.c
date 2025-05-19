#include <stdio.h>
#include <stdlib.h>
#include "peminjaman.h"
#include "sll.h"
#include "dll.h"
#include "array.h"

// Fungsi untuk menampilkan semua peminjaman
void tampilkanSemuaPeminjaman(NodeSLL* headSLL, NodeDLL* headDLL, Peminjaman array[], int countArray) {
    printf("\n===== DAFTAR SEMUA PEMINJAMAN =====\n");
    
    printf("\n--- PEMINJAMAN DI SINGLE LINKED LIST ---\n");
    displaySLL(headSLL);
    
    printf("\n--- PEMINJAMAN DI DOUBLE LINKED LIST ---\n");
    displayDLL(headDLL);
    
    printf("\n--- PEMINJAMAN DI ARRAY ---\n");
    displayArray(array, countArray);
}

int main() {
    NodeSLL* headSLL = NULL;
    NodeDLL* headDLL = NULL;
    NodeDLL* tailDLL = NULL;
    Peminjaman arrayPinjaman[MAX_ARRAY];
    int countArray = 0;
    
    int pilihan;
    
    do {
        printf("\n===== SISTEM MANAJEMEN PERPUSTAKAAN =====\n");
        printf("1. Menggunakan Single Linked List (SLL)\n");
        printf("2. Menggunakan Double Linked List (DLL)\n");
        printf("3. Menggunakan Array\n");
        printf("4. Tampilkan List Peminjaman\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        
        scanf("%d", &pilihan);
        getchar(); // mengonsumsi karakter newline
        
        switch (pilihan) {
            case 1:
                menuSLL(&headSLL);
                break;
            case 2:
                menuDLL(&headDLL, &tailDLL);
                break;
            case 3:
                menuArray(arrayPinjaman, &countArray);
                break;
            case 4:
                tampilkanSemuaPeminjaman(headSLL, headDLL, arrayPinjaman, countArray);
                break;
            case 0:
                printf("Terima kasih telah menggunakan sistem perpustakaan!\n");
                break;
            default:
                printf("Invalid choice. \n");
        }
    } while (pilihan != 0);
    
    // Pembebasan memori
    NodeSLL* currentSLL = headSLL;
    while (currentSLL != NULL) {
        NodeSLL* temp = currentSLL;
        currentSLL = currentSLL->next;
        free(temp);
    }
    
    NodeDLL* currentDLL = headDLL;
    while (currentDLL != NULL) {
        NodeDLL* temp = currentDLL;
        currentDLL = currentDLL->next;
        free(temp);
    }
    
    return 0;
}