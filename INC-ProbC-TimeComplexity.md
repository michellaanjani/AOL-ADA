#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair *pairs;
    int ukuran;
    int kapasitas;
} Map;

void initMap(Map *map) {
    map->ukuran = 0;
    map->kapasitas = 10;
    map->pairs = (Pair *)malloc(map->kapasitas * sizeof(Pair));
}

void addToMap(Map *map, int key) {
	int i;
    for (i = 0; i < map->ukuran; i++) {
        if (map->pairs[i].key == key) {
            map->pairs[i].value++;
            return;
        }
    }
    if (map->ukuran == map->kapasitas) {
        map->kapasitas *= 2;
        map->pairs = (Pair *)realloc(map->pairs, map->kapasitas * sizeof(Pair));
    }
    map->pairs[map->ukuran].key = key;
    map->pairs[map->ukuran].value = 1;
    map->ukuran++;
}

int getMaxFrequency(Map *map) {
    int maxFreq = 0;
    int i;
    for (i = 0; i < map->ukuran; i++) {
        if (map->pairs[i].value > maxFreq) {
            maxFreq = map->pairs[i].value;
        }
    }
    return maxFreq;
}

int main() {
    int n;
    scanf("%d", &n);

    int *kacang = (int *)malloc(n * sizeof(int)); 
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &kacang[i]);
    }

    int *jumlah = (int *)malloc(n * sizeof(int)); 
    jumlah[0] = 0;

    int j;
    for (j = 0; j < n - 1; j++) {
        int total = kacang[j] + kacang[j + 1];
        if (jumlah[j] != total) {
            jumlah[j + 1] = total; 
        } else {
            jumlah[j + 1] = 0; 
        }
    }

    Map freq;
    initMap(&freq);

    int l;
    for (l = 0; l < n; l++) {
        if (jumlah[l] != 0) {
            addToMap(&freq, jumlah[l]); 
        }
    }

    int maxFreq = getMaxFrequency(&freq); 
    printf("%d\n", maxFreq);

    
    free(kacang);
    free(jumlah);
    free(freq.pairs);

    return 0;
}
