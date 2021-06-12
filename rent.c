#include <stdio.h>
#include <stdlib.h>
#define BUFFERMAX 40
#define MAXORDER 10001
#define INFNTY 2000000

struct order{
    int start;
    int duration;
    int best;
} Orders[MAXORDER];

char buf[BUFFERMAX];

int main() {
    int max1;
    fgets(buf, BUFFERMAX, stdin);
    sscanf(buf, "%d", &max1);
    for(int i=0; i<max1; i++) {
        int max2;
        fgets(buf, BUFFERMAX, stdin);
        sscanf(buf, "%d", &max2);
        for(int j = 0; j < max2; j++) {
            int a, b, c;
            char id[BUFFERMAX];
            fgets(buf, BUFFERMAX, stdin);
            sscanf(buf, "%s %d %d %d", id, &a, &b, &c);
            Orders[j].start = a;
            Orders[j].duration = b;
            Orders[j].best      = c;
        }
        FILE *out = fopen("temp","w");
        for(int j = 0; j < max2; j++) {
            fprintf(out, "%010d %010d %010d\n", Orders[j].start, Orders[j].duration, Orders[j].best);
        }
        fclose(out);
        system("sort temp > temps");
        FILE *in = fopen("temps","r");
        for(int j = 0; j < max2; j++) {
            int a, b, c;
            fgets(buf, BUFFERMAX, in);
            sscanf(buf, "%d %d %d", &a, &b, &c);
            Orders[j].start = a;
            Orders[j].duration = b;
            Orders[j].best      = c;
        }
        fclose(in);
        Orders[max2].start = INFNTY;
        Orders[max2].duration   = 0;
        Orders[max2].best      = 0;
        max2++;
        for(int j = max2-2; j >= 0; j--) {
            int k = j+1;
            while(k <= max2 && Orders[k].start < Orders[j].start + Orders[j].duration)
                k++;
            Orders[j].best = Orders[j+1].best > Orders[j].best + Orders[k].best ? Orders[j+1].best : Orders[j].best + Orders[k].best;
        }
        printf("%d\n", Orders[0].best);
    }
    return 0;
}


