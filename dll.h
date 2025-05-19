#ifndef DLL_H
#define DLL_H

#include "peminjaman.h"

// Struktur node untuk Double Linked List
typedef struct NodeDLL {
    Peminjaman data;
    struct NodeDLL* next;
    struct NodeDLL* prev;
} NodeDLL;

// Fungsi-fungsi operasi Double Linked List
NodeDLL* createNodeDLL(Peminjaman data);
void insertDLL(NodeDLL** head, NodeDLL** tail, Peminjaman data);
int deleteFirstDLL(NodeDLL** head, NodeDLL** tail);
int deleteByIDDLL(NodeDLL** head, NodeDLL** tail, int id);
void displayDLL(NodeDLL* head);
int isEmptyDLL(NodeDLL* head);

// Menu untuk Double Linked List
void menuDLL(NodeDLL** head, NodeDLL** tail);

#endif /* DLL_H */