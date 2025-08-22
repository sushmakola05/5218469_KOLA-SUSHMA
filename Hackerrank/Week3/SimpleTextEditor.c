#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000005

char S[MAX]; int len = 0;
typedef struct{
    int type;
    char *data;
}Op;
Op ops[MAX]; int top = -1;

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q, t, k; 
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &t);
        if(t == 1){
            char w[1005]; 
            scanf("%s", w);
            int L = strlen(w);
            ops[++top].type = 1;
            ops[top].data = malloc(L + 1);
            strcpy(ops[top].data, w);
            strcpy(S + len, w);
            len += L;
        }else if(t == 2){
            scanf("%d", &k);
            ops[++top].type = 2;
            ops[top].data = malloc(k + 1);
            strncpy(ops[top].data, S + len - k, k);
            ops[top].data[k] = '\0';
            len -= k;
            S[len] = '\0';
        }else if(t == 3){
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        }else{
            if(ops[top].type == 1){
                int L = strlen(ops[top].data);
                len -= L;
                S[len] = '\0';
            }else{
                strcpy(S + len, ops[top].data);
                len += strlen(ops[top].data);
            }
            free(ops[top].data);
            top--;
        }
    }
    return 0;
}
