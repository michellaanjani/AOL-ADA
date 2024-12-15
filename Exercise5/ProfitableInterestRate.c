#include <stdio.h>
//jalankan code di https://www.onlinegdb.com/online_c_compiler
int main() {
    int test; // Membaca int sebagai test case untuk batasan loop permintaan kasus
    scanf("%d", &test); // Input jumlah test case
    
    long long a, b; // Jumlah koin yang dimiliki Alice dan jumlah minimum untuk membuka deposito Profitable
    long long result[test]; // Array untuk menyimpan hasil untuk setiap test case

    // Loop untuk setiap test case
    for(int i = 0; i < test; i++) {
        scanf("%lld %lld", &a, &b); // Input jumlah koin yang dimiliki Alice (a) dan jumlah minimum (b)
        
        // Jika Alice memiliki cukup koin untuk membuka deposito Profitable
        if (a >= b) {
            result[i] = a; // Alice bisa menabungkan seluruh uangnya di deposito Profitable
        } else {
            // Jika tidak cukup, hitung jumlah koin yang bisa disimpan setelah membuka deposito Unprofitable
            // Penjelasan logika (dalam bahasa kode):
            // dp ~ deposito profitable, us ~ uang sekarang
            // dp - 2x = us - x => batas minimum deposito Profitable akan dikurangi dengan 2x
            // dp - 2(dp - us) = us - (dp - us)
            // dp - 2dp + 2us = us - dp + us
            // -dp + 2us = 2us - dp => hasil akhir sama di kedua sisi
            // Artinya, batas minimum = uang sekarang, jadi Alice bisa menabung di deposito Profitable sejumlah minimum tersebut
            long long x_min = (b - a);  // Menghitung selisih minimum yang kurang
            if (a - x_min > 0) {
                result[i] = a - x_min; // Jika masih ada uang yang tersisa setelah membuka deposito Unprofitable
            } else {
                result[i] = 0; // Jika tidak ada uang yang tersisa, set hasil ke 0
            }
        }
    }

    // Output hasil untuk setiap test case
    for(int i = 0; i < test; i++) {
        printf("%lld\n", result[i]); // Mencetak hasil untuk setiap test case
    }

    return 0; // Mengakhiri program
}
