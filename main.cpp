//  main.cpp
//  Tubes AKA (Analisis Kompleksitas Algoritma)
//  Tema : Algoritma Josephus
//  Anggota Kelompok:   1. Kevin Jonathan Rotty (103052330047)
//                      2. Enuka Lula
//  DS-47-03

#include <iostream>
#include <chrono>
using namespace std;

int josephus_iteratif(int N, int k) {
    int hasil = 0;
    int sisaPemain = N;
    for (int i = 2; i <= sisaPemain; i++) {
        hasil = (hasil + k) % i;
    }
    return hasil;
}

int josephus_rekursif(int N, int k) {
    int sisaPemain = N;
    if (sisaPemain == 1) {
        return 0;
    } else {
        return (josephus_rekursif(sisaPemain - 1, k) + k) % sisaPemain;
    }
}

int main(){
    int N, k;
    
    cout << "==== WELCOME TO JOSEPHUS MINIGAME ====" << endl;
    cout << endl;
    cout << "Masukkan jumlah pemain: ";
    cin >> N;
    cout << "Pemain urutan keberapa yang ingin dihapus: ";
    cin >> k;
    cout << endl;
    
    cout << "Hasil menggunakan algoritma iteratif" << endl;
    auto start_iteratif = chrono::high_resolution_clock::now();
    int hasil = josephus_iteratif(N, k);
    auto end_iteratif = chrono::high_resolution_clock::now();
    auto duration_iteratif = chrono::duration_cast<chrono::microseconds>(end_iteratif - start_iteratif);
    cout << "Pemenangnya adalah pemain dengan nomor urut: ";
    cout << hasil+1 << endl;
    
    cout << endl;
    
    cout << "Waktu eksekusi algoritma iteratif: " << duration_iteratif.count() << " mikrodetik" << endl;
    
    cout << endl;
    
    cout << "Hasil menggunakan algoritma rekursif" << endl;
    auto start_rekursif = chrono::high_resolution_clock::now();
    hasil = josephus_rekursif(N, k);
    auto end_rekursif = chrono::high_resolution_clock::now();
    auto duration_rekursif = chrono::duration_cast<chrono::microseconds>(end_rekursif - start_rekursif);
    cout << "Pemenangnya adalah pemain dengan nomor urut: ";
    cout << hasil+1 << endl;
    cout << endl;
    
    cout << "Waktu eksekusi algoritma rekursif: " << duration_rekursif.count() << " mikrodetik" << endl;
    cout << endl;
}
