#ifndef ARRAY_H
#define ARRAY_H

#include "peminjaman.h"

// Konstanta untuk ukuran maksimum array
#define MAX_ARRAY 100

// Fungsi-fungsi operasi Array
int insertArray(Peminjaman array[], int* count, Peminjaman data);
int deleteFirstArray(Peminjaman array[], int* count);
int deleteByIDArray(Peminjaman array[], int* count, int id);
void displayArray(Peminjaman array[], int count);

// Menu untuk Array
void menuArray(Peminjaman array[], int* count);

#endif /* ARRAY_H */