#include <stdio.h>

int main() {
    int test; // Membaca int sebagai test case untuk batasan loop permintaan khasus 
    scanf("%d", &test);
    long long a, b; // Jumlah koin yang dimiliki Alice dan jumlah minimum untuk membuka deposito Profitable
    long long result[test]; //hasil yaitu uang maksimum yang bisa Alice tabungkan

    for(int i = 0; i < test; i++) {
        scanf("%lld %lld", &a, &b);
        
        if (a >= b) {
            // Jika Alice memiliki cukup koin untuk membuka deposito Profitable
            result[i] = a;
        } else {
            // Jika tidak cukup, hitung jumlah koin yang bisa disimpan setelah membuka deposito Unprofitable
            //dp ~deposit profitable, us ~uang sekarang
            //dp-2x = us-x
            //dp-2(dp-us) = us-(dp-us)
            //dp-2dp+2us = us-dp+us
            //-dp+2us = 2us-dp
            //2us-dp = 2us-dp
            long long x_min = (b - a);
            if (a - x_min > 0) {
                result[i] = a - x_min;
            } else {
                result[i] = 0;
            }
        }
    }
    for(int i = 0; i < test; i++) {
        printf("%lld\n", result[i]);
    }
    getchar();
    getchar();
    return 0;
}
