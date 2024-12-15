#include <stdio.h>// 1

int main() { // 1
    int test; // 1
    scanf("%d", &test); // 1
    long long a, b; // 1
    long long result[test]; // 1

    for(int i = 0; i < test; i++) { // test + 1
        scanf("%lld %lld", &a, &b); // test * 1
        
        if (a >= b) { // test * 1
            result[i] = a;
        } else { 
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
    for(int i = 0; i < test; i++) { //test + 1
        printf("%lld\n", result[i]); //test * 1
    }

    return 0; // 1
}

Jadi time complexity O(test) -> O(n)
Hal ini karena tidak ada nested loop dan loop terpisah sehinga tidak ada pangkat 2, pangkat terbesar adalah test pangkat 1 atau n pangkat 1
