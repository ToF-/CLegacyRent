#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 40
#define MAXORDER 10001
#define MAXTIME 2000000

struct order{
    int start;
    int end_time;
    int price;
} Orders[MAXORDER];

char Line[MAXLINE];

char *get_line(char *line) {
    fgets(line, MAXLINE, stdin);
    return line;
}

int get_int(char *line) {
    int result;
    sscanf(get_line(line), "%d", &result);
    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int compare_orders(const void *a, const void *b) {
    struct order *pa = (struct order *)a;
    struct order *pb = (struct order *)b;
    if (pa->start < pb->start)
        return -1;
    else if (pa->start > pb->start)
        return 1;
    else 
        return (pa->end_time - pb->end_time);
}
int main() {
    int max_cases = get_int(Line);
    for(int i=0; i<max_cases; i++) {
        int max_order = get_int(Line);
        for(int j = 0; j < max_order; j++) {
            int start, duration, price;
            get_line(Line);
            sscanf(Line, "%d %d %d", &start, &duration, &price);

            Orders[j].start = start;
            Orders[j].end_time   = start+duration;
            Orders[j].price      = price; 
        }
        qsort(Orders, max_order, sizeof(struct order), compare_orders);
        Orders[max_order].start = MAXTIME;
        Orders[max_order].end_time   = MAXTIME;
        Orders[max_order].price      = 0;
        max_order++;
        for(int j = max_order-2; j >= 0; j--) {
            int l = j+1;
            int h = max_order;
            int m;
            int k;
            while (l <= h) {
                m = l + (h - l) / 2;
                if(Orders[m].start < Orders[j].end_time)
                    l = m + 1;
                else {
                    k = m;
                    h = m - 1;
                }
            }
            Orders[j].price = max(Orders[j+1].price, Orders[j].price + Orders[k].price);
        }
        printf("%d\n", Orders[0].price);
    }
    return 0;
}


