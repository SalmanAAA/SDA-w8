#ifndef SLL_H
#define SLL_H

#include "peminjaman.h"

// Struktur node untuk Single Linked List
typedef struct NodeSLL {
    Peminjaman data;
    struct NodeSLL* next;
} NodeSLL;

// Fungsi-fungsi operasi Single Linked List
NodeSLL* createNodeSLL(Peminjaman data);
void insertSLL(NodeSLL** head, Peminjaman data);
int deleteFirstSLL(NodeSLL** head);
int deleteByIDSLL(NodeSLL** head, int id);
void displaySLL(NodeSLL* head);
int isEmptySLL(NodeSLL* head);

// Menu untuk Single Linked List
void menuSLL(NodeSLL** head);

#endif /* SLL_H */