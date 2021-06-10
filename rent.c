#include <stdio.h>
#include <stdlib.h>
#define BUFFERMAX 40
#define MAXORDER 10001
#define INFNTY 2000000

struct order{
    char trade_id[BUFFERMAX];
    int start;
    int duration;
    int revenue;
} Orders[MAXORDER];
char buf[BUFFERMAX];
char id[BUFFERMAX];

int compare(const void *a, const void *b) {

    const struct order *orderA = a;
    const struct order *orderB = b;

    if(orderA->start < orderB->start)
        return -1;
    if(orderA->start > orderB->start)
        return 1;
    return orderA->duration - orderB->duration;

}
void sort_orders(int max2) {
    // se fait ch.. a réécrire un  fichier
    // ^ on comprend que ça prend du temps
    qsort(Orders,max2, sizeof(struct order), compare); 
}
int next_compatible(int numOrder, int max2) {
    int start = Orders[numOrder].start;
    int end = start + Orders[numOrder].duration;
    int low = numOrder+1; 
    int high = max2; 
    int middle; 
    int k;
    while (low <= high) {
        middle = low + (high - low) / 2;
        if(Orders[middle].start < end)
            low = middle + 1;
        else {
            k = middle;
            high = middle - 1;
        }
    }
    return k;
}

int main() {
    int max1;
    fgets(buf, BUFFERMAX, stdin);
    sscanf(buf, "%d", &max1);
    // boucle sur le nombre de blocs
    for(int numBlock=0; numBlock<max1; numBlock++) {
        int max2;
        fgets(buf, BUFFERMAX, stdin);
        sscanf(buf, "%d", &max2);
        // boucle sur le nombre de lignes du bloc
        for(int numOrder = 0; numOrder < max2; numOrder++) {
            fgets(buf, BUFFERMAX, stdin);
            sscanf(buf, "%40s %d %d %d"
                      , Orders[numOrder].trade_id
                      , &Orders[numOrder].start
                      , &Orders[numOrder].duration
                      , &Orders[numOrder].revenue);
        }
        sort_orders(max2);
        Orders[max2].start = INFNTY;
        Orders[max2].duration   = 0;
        Orders[max2].revenue      = 0;
        max2++;
        // calcul du meilleur revenu
        for(int numOrder = max2-2; numOrder >= 0; numOrder--) {
            int compatible = next_compatible(numOrder, max2);
            int next = numOrder+1;
            int revenue_from_next = Orders[next].revenue;
            int revenue_plus_compatible = Orders[numOrder].revenue + Orders[compatible].revenue;
            if (revenue_from_next > revenue_plus_compatible) {
                Orders[numOrder].revenue = revenue_from_next;
            }
            else {
                Orders[numOrder].revenue = revenue_plus_compatible;

            }
        }
        // le meilleur finit dans la meilleure case du tableau
        printf("%d\n", Orders[0].revenue);
    }
    return 0;
}


