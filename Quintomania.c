#include <stdio.h>
#include <stdlib.h>
// gunakan https://www.onlinegdb.com/online_c_compiler
int main() {
    int test; // var penyimpanan nilai int untuk test case
    scanf(" %d", &test);  // membaca input user untuk test case
    fflush(stdout); // menghilangkan buffer hidden character

    int *result = (int*)malloc(test * sizeof(int)); // alokasi memori untuk var result untuk menyimpan hasil tiap test case
    int n; //var untuk menampung nilai sementara berapa banyak nada yang ada dalam suatu melodi
    int valid; // deklarasi var valid 
    for(int t = 0; t < test; t++) { // loop sebanyak test case
        scanf(" %d", &n); // user input untuk test case ke i banyak nada dalam suatu melodi mau berapa
        fflush(stdout); // menghilangkan buffer hidden character
        int *v = (int*)malloc(n * sizeof(int)); // alokasi memori untuk menyimpan nada-nada sejumlah n
        
        result[t] = 1;  //set result awal = 1 atau true 
        valid = 1; //set var valid =  1 atau true
        for (int i = 0; i < n; i++) { // loop sebanyak jumlah nada dalam suatu melodi
            scanf(" %d", &v[i]);  // membaca input user untuk nada-nada dalam suatu melodi untuk di check secara berurutan apa jaraknya 5 atau 7
            fflush(stdout); // menghilangkan buffer hidden character
            if(i > 0 && abs(v[i] - v[i - 1]) != 5 && abs(v[i] - v[i - 1]) != 7 && valid == 1) {	
                // bila valid sudah 0 maka if tidak akan dijalankan, hasil sudah ada tapi user tetap perlu menginput nada sesuai n
                // untuk iterasi kedua dan seterusnya bandingkan jarak dengan nada di iterasi sebelumnya bila tidak 5 dan tidak 7 set result 0 (namun tetap lanjut membaca sesuai n)
                result[t] = 0;  
                valid = 0;
            }
        }
        free(v); // bebaskan memori yang dialokasikan untuk nilai dari nada-nada
    }
    
    for(int i = 0; i < test; i++){ //loop sebanyak test case untuk mencetak hasil
        if (result[i]) { // saat result ke i = 1 maka akan di print 'YES' yang berarti jarak antar int berurutan 5 atau 7
            printf("YES\n");
        } else {
            printf("NO\n"); // selain itu print 'NO'
        }
    }

    free(result); // membebaskan memori untuk result
    return 0; // mengakhiri program
}
