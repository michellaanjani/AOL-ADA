#include <stdio.h>
#include <stdlib.h>
int main() {
    int test;
    scanf(" %d", &test);  
    fflush(stdout);

    int *result = (int*)malloc(test * sizeof(int)); 
    int n;
    int valid;
    for(int t = 0; t < test; t++) {
        scanf(" %d", &n); 
        fflush(stdout);
        int *v = (int*)malloc(n * sizeof(int)); 
        
        result[t] = 1;  
        valid = 1;
        for (int i = 0; i < n; i++) {
            scanf(" %d", &v[i]);  
            fflush(stdout);
            if(i > 0 && abs(v[i] - v[i - 1]) != 5 && abs(v[i] - v[i - 1]) != 7 && valid == 1) {	
                result[t] = 0;  
                valid = 0;
            }
        }
        free(v);
    }
    
    for(int i = 0; i < test; i++){
        if (result[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    free(result);
    return 0;
}
