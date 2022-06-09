#include <stdio.h>

void calculate(int *px, int *py) {
    int *pz;
    static int k = 0;
    for (pz = py; pz < py + 4; pz++) {
        *pz = *(py+k) + *(px+k);
        k++; 
    }
}

int main() {
    int a[4][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
    int (*px)[4], *py[8];
    py[0] = a[3]; py[1] = a[0];
    px = &a[3];
    printf("%d %d %d\n",*py[0],*py[1],(*py)[3]);
    calculate(px[0],py[0]);
    printf("%d %d %d\n",*py[0],*py[1],(*py)[3]);
    return 0;
}