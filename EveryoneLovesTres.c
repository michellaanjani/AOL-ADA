#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
//jalankan di https://www.onlinegdb.com/online_c_compiler

int main() {
    //harus habis dibagi 66 dan 33, karena dan keduanya harus bersamaan dan 
    //bila habis dibagi 66 pasti habis dibagi 33 kesimpulan harus dibagi 66 saja.
    //KPK 66: 2, 3, 11 ->digit terakhir harus 6 agar bisa di bagi 2, 
    //habis dibagi 3 itu pasti terjadi karena semua digit 3 dan 6 bisa dibagi 3
    //yang perlu diperhatikan habis dibagi 2 dan 11
    int test; // deklarasi var untuk menyimpan test case
    scanf(" %d", &test); //Input test case oleh user
    int n; //var untuk menampung jumlah digit yang diinginkan user
    char **result = (char **)malloc(test * sizeof(char *));   // Alokasi memori untuk menyimpan hasil setiap kasus uji

    for(int t = 0; t < test; t++) { //loop studi khasus sesuai test case
        scanf(" %d", &n); // input jumlah digit yang diinginkan oleh user
        // Tidak mungkin jika n = 1 karena bilangan hanya terdiri dari 3 atau 6 lebih kecil dari 66
        // digit 3 tidak bisa karena 333, 633, 363, 336, 663, 636, 366, 666 
        //336, 636, 366, 666 tidak mungkin karena jumlah digit ganjil dan jumlah digit genep harus sama untuk habis dibagi 11
        result[t] = (char *)malloc((n + 1) * sizeof(char)); // Alokasi memori untuk hasil bilangan dengan panjang n
        if (n == 1 || n == 3) { //check apakah digit yang diminta itu 1 atau 3 karena mereka tidak bisa habis di bagi 66, penjelasan diatas
            result[t] = "-1";// set hasil = -1 untuk test case ke t
            continue; //skip code selanjutnya dan lanjut ke test case berikutnya karena sudah ketemu hasilnya
        }

        // Untuk panjang n, digit terakhir harus 6 untuk memenuhi kelipatan 2
        // Sisanya harus terdiri dari kombinasi 3 dan 6 untuk memenuhi kepilatan 3 juga permintaan soal
        // jumlah nilai pada digit ganjil harus sama dengan jumlah nilai pada digit genap untuk kelipatan 11
        //contoh n genap= 4: 3 3 6 6 -> jumlah digit ganjil 3 + 6 = 9 sama dengan jumlah digit genap 3 + 6 = 9
        //contoh n ganjil= 5: 3 6 3 6 6 -> jumlah digit ganjil 3 + 3 + 6 = 12 sama dengan jumlah digit genap 6 + 6 = 12
         //contoh n genap= 6: 3 3 3 3 6 6 -> jumlah digit ganjil 3 + 3 + 6 = 12 sama dengan jumlah digit genap 3 + 3 + 6 = 12
        //contoh n ganjil= 7: 3 3 3 6 3 6 6 -> jumlah digit ganjil 3 + 3 + 3 + 6 = 15 sama dengan jumlah digit genap 3 + 6 + 6 = 15
        //ada pola bila diperhatikan jika digit ganjil hasilnya bilangan kedua terakhir adalah 6 6 selain itu 3 agar nilai minimum tercapai
        //pola digit ganjil akir selalu 6 3 6 6 

        for (int j = 0; j < n; j++) { // loop sebanyak jumlah digit
            if(n % 2 == 0) { //apakah genap
                if(j < n - 2) // untuk semua digit kecuali 2 terakhir diisi 3
                    result[t][j] = '3';
                else if(j >= n - 2) // dua digit akhir diisi  6
                    result[t][j] = '6';
            }
            else{ //selain genap berarti ganjil
                if(j < n - 4 || j == n - 3){ 
                    result[t][j] = '3'; // untuk semua digit sebelum 4 digit akhir dan digit ke 3 dari akhir diisi 3
                }
                else // selain diatas diisi 6
                    result[t][j] = '6';
            }
            
        }
        result[t][n] = '\0'; // akir dari string hasil
    }
    for(int i = 0; i < test; i++){ // print hasil sejumlah test case
        printf("%s\n", result[i]);
    }
        

    free(result); //bebaskan memori hasil

    return 0; //akir program

}
