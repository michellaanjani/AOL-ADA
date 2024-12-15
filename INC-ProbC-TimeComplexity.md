#include <stdio.h> // 1
#include <stdlib.h> // 1

typedef struct { // 1
    int key; // 1
    int value; // 1
} Pair; // 1


typedef struct { // 1
    Pair *pairs; // 1
    int ukuran; // 1
    int kapasitas; // 1
} Map; // 1

void initMap(Map *map) { // 1
    map->ukuran = 0; // 1
    map->kapasitas = 10; // 1
    map->pairs = (Pair *)malloc(map->kapasitas * sizeof(Pair)); // 1
}

void addToMap(Map *map, int key) { // 1
	int i; // 1
    for (i = 0; i < map->ukuran; i++) { // map->ukuran + 1
        if (map->pairs[i].key == key) { // map->ukuran * 1
            map->pairs[i].value++; 
            return;
        }
    }
    if (map->ukuran == map->kapasitas) { // 1
        map->kapasitas *= 2; // 1
        map->pairs = (Pair *)realloc(map->pairs, map->kapasitas * sizeof(Pair)); // 1
    }
    map->pairs[map->ukuran].key = key; // 1
    map->pairs[map->ukuran].value = 1; // 1
    map->ukuran++; // 1
}

int getMaxFrequency(Map *map) { // 1
    int maxFreq = 0; // 1
    int i; // 1
    for (i = 0; i < map->ukuran; i++) { // map->ukuran + 1
        if (map->pairs[i].value > maxFreq) { // map->ukuran * 1
            maxFreq = map->pairs[i].value;
        }
    }
    return maxFreq; // 1
}

int main() { // 1
    int n; // 1
    scanf("%d", &n); // 1

    int *kacang = (int *)malloc(n * sizeof(int));  // 1
    int i; // 1
    for (i = 0; i < n; i++) { // n + 1
        scanf("%d", &kacang[i]); //n * 1
    }

    int *jumlah = (int *)malloc(n * sizeof(int)); // 1
    jumlah[0] = 0; // 1

    int j; // 1
    for (j = 0; j < n - 1; j++) { // n
        int total = kacang[j] + kacang[j + 1]; //(n - 1) * 1 
        if (jumlah[j] != total) { //(n - 1) * 1 
            jumlah[j + 1] = total; 
        } else {
            jumlah[j + 1] = 0; 
        }
    }

    Map freq; // 1 
    initMap(&freq); // 1

    int l; // 1
    for (l = 0; l < n; l++) { // n + 1
        if (jumlah[l] != 0) { // n * 1
            addToMap(&freq, jumlah[l]); //n * O(n) paling tinggi
        }
    }

    int maxFreq = getMaxFrequency(&freq); // 1
    printf("%d\n", maxFreq); // 1

    
    free(kacang); // 1
    free(jumlah); // 1
    free(freq.pairs); // 1

    return 0; // 1
}

kesimpulan time complexity O(n^2)
