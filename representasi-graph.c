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
        printf("Graph ini adalah graph terhubung.\n");
    else
        printf("Graph ini adalah graph tidak terhubung.\n");
}

// Fungsi untuk mengecek apakah graph berarah atau tidak
int cekGraphBerarah(int a[MAX][MAX], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != a[j][i]) {
                return 1; // Graph berarah
            }
        }
    }
    return 0; // Graph tidak berarah
}

// Fungsi untuk menghitung derajat suatu vertex
void hitungDerajatVertex(int a[MAX][MAX], int n) {
    int ver = n;
    printf("\nDerajat Setiap Vertex:\n");

    int derajat[ver];
    for(int i = 1; i <= n; i++){
        derajat[i] = 0;
           for(int j = 1; j <= n; j++){
            derajat[i] += a[i][j];
            }
        printf("\nDerajat Vertex %d: %d", i, derajat[i]); //hasil derajat
    }
}


// Fungsi untuk menghitung total derajat semua vertex
void hitungTotalDerajat(int a[MAX][MAX], int n) {
    int totalDerajat = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            totalDerajat += a[i][j];
        }
    }
    printf("Derajat Semua Vertex: %d\n", totalDerajat);
}


// Fungsi untuk mengecek apakah ada loop dalam graph
void cekLoop(int a[MAX][MAX], int n) {
    int adaLoop = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i][i] == 1) {
            adaLoop = 1;
            printf("Terdapat loop pada vertex %d.\n", i);
        }
    }
    if (!adaLoop) {
        printf("Graph ini tidak memiliki loop.\n");
    }
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
    printf("\n");

    // Cek keterhubungan graph
    cekKeterhubungan(a, n);

    // Cek apakah graph berarah atau tidak
    if (cekGraphBerarah(a, n))
        printf("Graph ini adalah graph berarah.\n");
    else
        printf("Graph ini adalah graph tidak berarah.\n");

    // Cek apakah ada loop dalam graph
    cekLoop(a, n);

    // Hitung derajat vertex tertentu
    hitungDerajatVertex(a, n);
    printf("\n");

    // Hitung total derajat semua vertex
    hitungTotalDerajat(a, n);

    return 0;
}
