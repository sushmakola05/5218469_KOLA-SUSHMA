#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXQ 100000
int heap[MAXQ], size = 0;
void swap(int *a, int *b){
     int t = *a;
     *a = *b;
     *b = t;
}
void heapifyUp(int i){
    while (i > 0) {
        int p = (i - 1) / 2;
        if(heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}
void heapifyDown(int i){
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, sm = i;
        if(l < size && heap[l] < heap[sm]) sm = l;
        if(r < size && heap[r] < heap[sm]) sm = r;
        if(sm == i) break;
        swap(&heap[i], &heap[sm]);
        i = sm;
    }
}
void insert(int v){
    heap[size] = v;
    heapifyUp(size++);
}
void deleteVal(int v){
    int i;
    for(i = 0; i < size; i++) if(heap[i] == v) break;
    if(i == size) return;
    heap[i] = heap[--size];
    heapifyUp(i);
    heapifyDown(i);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type, v;
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &v);
            insert(v);
        }
        else if(type == 2){
            scanf("%d", &v);
            deleteVal(v);
        }
        else{
            printf("%d\n", heap[0]);
        }
    }   
    return 0;
}
