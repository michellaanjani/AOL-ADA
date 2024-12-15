#include <stdio.h>

int main() {
    int test; // Membaca int sebagai test case untuk batasan loop permintaan khasus 
    scanf("%d", &test);
    long long a, b; // Jumlah koin yang dimiliki Alice dan jumlah minimum untuk membuka deposito Profitable
    long long result[test]; //hasil yaitu uang maksimum yang bisa Alice tabungkan di deposito Profitable

    for(int i = 0; i < test; i++) { //loop sejumlah test case
        scanf("%lld %lld", &a, &b); // long int untuk menampung input user, a = Jumlah koin yang dimiliki Alice, b = jumlah minimum untuk membuka deposito Profitable
        
        if (a >= b) { 
            // Jika Alice memiliki cukup koin untuk membuka deposito Profitable
            result[i] = a; // set hasil untuk test case ke i sebagai a, yang artinya Alice mampu menabungkan semua uangnya di deposito Profitable karena memenuhi batas minimum
        } else {
            // Jika tidak cukup, hitung jumlah koin yang bisa disimpan setelah membuka deposito Unprofitable
            //dp ~deposit profitable, us ~uang sekarang
            //dp-2x = us-x syarat bila menabung sejumlah x di d.unprofitable, batas min d.profitable akan dikurangi dengan 2x
            //dp-2(dp-us) = us-(dp-us) ubah x menjadi dp-us
            //dp-2dp+2us = us-dp+us
            //-dp+2us = 2us-dp
            //2us-dp = 2us-dp hasil akhir sama kedua sisi yang berarti batas minimum = uang sekarang, sehingga alice bisa menabung di deposit profitable sejumlah = minimumnya
            long long x_min = (b - a);
            if (a - x_min > 0) {
                result[i] = a - x_min;
            } else {
                result[i] = 0;
            }
        }
    }
    for(int i = 0; i < test; i++) { //print tiap result untuk setiap test
        printf("%lld\n", result[i]);
    }

    return 0;
}
