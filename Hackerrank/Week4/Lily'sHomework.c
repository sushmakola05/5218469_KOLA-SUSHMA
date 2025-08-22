#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
typedef struct{
    int val, idx;
} Pair;
int cmpPair(const void *a, const void *b){
    return ((Pair*)a) -> val - ((Pair*)b) -> val;
}
int countSwaps(int *arr, int n, int *target){
    Pair *map = malloc(n * sizeof(Pair));
    int *vis = calloc(n, sizeof(int));
    int swaps = 0;
    for(int i = 0; i < n; i++){
        map[i].val = target[i];
        map[i].idx = i;
        }
        qsort(map, n, sizeof(Pair), cmpPair);
        for (int i = 0; i < n; i++) {
        if (vis[i] || arr[i] == target[i]) continue;
        int cycle = 0, j = i;
        while (!vis[j]) {
            vis[j] = 1;
            int lo = 0, hi = n-1, mid, pos;
            while (lo <= hi) {
                mid = (lo+hi)/2;
                if (map[mid].val == arr[j]) { pos = map[mid].idx; break; }
                if (map[mid].val < arr[j]) lo = mid+1; else hi = mid-1;
            }
            j = pos;
            cycle++;
        }
        swaps += cycle - 1;
    }
    free(map);
    free(vis);
    return swaps;
}
int cmpAsc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int cmpDesc(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}
int lilysHomework(int arr_count, int* arr) {
    int *asc = malloc(arr_count * sizeof(int));
    int *desc = malloc(arr_count * sizeof(int));
    memcpy(asc, arr, arr_count * sizeof(int));
    memcpy(desc, arr, arr_count * sizeof(int));
    qsort(asc, arr_count, sizeof(int), cmpAsc);
    qsort(desc, arr_count, sizeof(int),cmpDesc);
    int s1 = countSwaps(arr, arr_count, asc);
    int s2 = countSwaps(arr, arr_count, desc);
    free(asc);
    free(desc);
    return (s1 < s2) ? s1 : s2;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    int result = lilysHomework(n, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
