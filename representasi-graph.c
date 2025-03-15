#include <stdio.h>
#include <stdlib.h>

#define MAX 101 // Maksimum jumlah vertex (gunakan indeks dari 1)

// Fungsi untuk mengecek keterhubungan graph
void cekKeterhubungan(int a[MAX][MAX], int n) {
    int hm[MAX] = {0}; // Matrix bantuan
    int T[MAX] = {0};  // Penanda vertex yang sudah dicek
    int i, j, idx;
    
    // Ambil sembarang vertex pertama (vertex 1)
    T[1] = 1;
    for (i = 1; i <= n; i++) {
        if (a[1][i] == 1) {
            hm[i] = 1;
        }
    }
    
    // Iterasi untuk memeriksa keterhubungan
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (hm[j] == 1 && T[j] == 0) {
                T[j] = 1;
                for (idx = 1; idx <= n; idx++) {
                    if (a[j][idx] == 1 && hm[idx] == 0) {
                        hm[idx] = 1;
                    }
                }
            }
        }
    }
    
    // Cek apakah semua vertex terhubung
    int isConnected = 1;
    for (i = 1; i <= n; i++) {
        if (T[i] == 0) {
            isConnected = 0;
            break;
        }
    }
    
    if (isConnected)
        printf("Graph ini terhubung.\n");
    else
        printf("Graph ini tidak terhubung.\n");
}

int main() {
    int a[MAX][MAX] = {0}; // Inisialisasi matriks adjacency dengan 0
    int n, i, j;
    
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &n);
    
    // Input hubungan antar vertex
    printf("\nMasukkan hubungan antar vertex:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Hubungan vertex %d dengan vertex %d = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    // Cetak matriks adjacency
    printf("\nMatriks Adjacency:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    // Cek keterhubungan graph
    cekKeterhubungan(a, n);
    
    return 0;
}
