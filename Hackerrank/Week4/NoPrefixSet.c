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

int parse_int(char*);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(int words_count, char** words) {
    typedef struct TrieNode{
        struct TrieNode *children[10];
        bool isEndOfWorld;
    }TrieNode;
    TrieNode* createNode(){
        TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node -> isEndOfWorld = false;
    for(int i = 0; i < 10; i++) node -> children[i] = NULL;
    return node;
    }
    TrieNode* root = createNode();
    for(int i = 0; i < words_count; i++){
        TrieNode* current = root;
        char* word = words[i];
        for(int j = 0; word[j]; j++){
            int idx = word[j] - 'a';
            if(current -> children[idx] == NULL){
                current -> children[idx] = createNode();
            }
            current = current -> children[idx];
            if(current -> isEndOfWorld){
                printf("BAD SET\n%s\n", word);
                return;
            }
        }
        for(int k = 0; k < 10; k++){
            if(current -> children[k] != NULL){
                printf("BAD SET\n%s\n", word);
                return;
            }
        }
        current -> isEndOfWorld = true;
    }
    printf("GOOD SET\n");
    
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    char** words = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* words_item = readline();

        *(words + i) = words_item;
    }

    noPrefix(n, words);

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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
