#include <stdio.h>
int func (int k, int *px){
    *px = *px & k ^ 10; //0100 & 
                        //000000 = 0 
                        //001010 = 
                        //001010
    return *px;
}

int main(){ 
    int a = 4, b = 8, c,d;
    c = a >> 2; // c = 1 
    c += b; // c = 9 
    c = c << 4; //01001 = 010010000 or 2*2*2*2 = 16 * 9 = 160-16 = 144 
    d = a >> 2 + (a << 4) & 10 ^ func(4,&d)| 4; // 1 + 01000000 & 
                                                //     00001010 = 0 ^ 01010
                                                //                    00100 
                                                //                    01110 = 14                    
    printf("%d--%d\n",c,d); // 144--14
    return 0;
}