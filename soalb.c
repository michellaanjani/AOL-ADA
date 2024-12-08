#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    //harus habis dibagi 66 dan 33, karena dan keduanya harus bersamaan dan 
    //bila habis dibagi 66 pasti habis dibagi 33 kesimpulan harus dibagi 66 saja.
    //KPK 66: 2, 3, 11 ->digit terakhir harus 6 agar bisa di bagi 2, 
    //habis dibagi 3 itu pasti terjadi karena semua digit 3 dan 6 bisa dibagi 3
    //yang perlu diperhatikan habis dibagi 2 dan 11
    int test;
    scanf(" %d", &test);
    int n;
    char **result = (char **)malloc(test * sizeof(char *));

    for(int t = 0; t < test; t++) {
        scanf(" %d", &n);
        // Tidak mungkin jika n = 1 karena bilangan hanya terdiri dari 3 atau 6 lebih kecil dari 66
        // digit 3 tidak bisa karena 333, 633, 363, 336, 663, 636, 366, 666 
        //336, 636, 366, 666 tidak mungkin karena jumlah digit ganjil dan jumlah digit genep harus sama untuk habis dibagi 11
        result[t] = (char *)malloc((n + 1) * sizeof(char));
        if (n == 1 || n == 3) {
            result[t] = "-1";
            continue;
        }

        // Untuk panjang n, digit terakhir harus 6 untuk memenuhi kelipatan 6
        // Sisanya harus terdiri dari kombinasi 3 dan 6.

        for (int j = 0; j < n; j++) {
            if(n % 2 == 0) {	
                if(j < n - 2)
                    result[t][j] = '3';
                else if(j >= n - 2)
                    result[t][j] = '6';
            }
            else{
                if(j < n - 4 || j == n - 3){
                    result[t][j] = '3';
                }
                else if(j >= n - 4)
                    result[t][j] = '6';
            }
            
        }
        result[t][n] = '\0';
    }
    for(int i = 0; i < test; i++){
        printf("%s\n", result[i]);
    }
        

    free(result);
    getchar();
    getchar();
    getchar();

    return 0;

}
