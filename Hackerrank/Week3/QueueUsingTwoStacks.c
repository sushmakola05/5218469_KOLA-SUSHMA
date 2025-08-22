#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    scanf("%d", &q);
    long long in[MAX], out[MAX];
    int ti = -1, to = -1; 
    while (q--) {
        int t;
        scanf("%d", &t);
        if(t == 1){
            long long x;
            scanf("%lld", &x);
            in[++ti] = x;
        }
        else if(t == 2){
            if(to < 0) while (ti >= 0) out[++to] = in[ti--];
            to--;
        }
        else if(t == 3){
            if(to < 0) while(ti >= 0) out[++to] = in[ti--];
            printf("%lld\n", out[to]);
        }
    }
    return 0;
}
