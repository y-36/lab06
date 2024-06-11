#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

struct _s_string {
    char *content;
    unsigned int length;
};

string string_create(const char *word) {
    string str = NULL;
    str = calloc(1, sizeof(struct _s_string));
    if (str == NULL) {
        return NULL; // Manejo de error
    }
    str->length = strlen(word);/* ¬(need implementation)*/
    str->content = calloc(/*implementation*/str->length +1, sizeof(char));
    if (str->content == NULL) {
        free(str); // Manejo de error
        return NULL;
    }
    str->content = strncpy(str->content, word, str->length + 1);
    return str;
}

unsigned int string_length(string str) {
    return str->length;
}

bool string_less(const string str1, const string str2) {
    /*implementation*/
    int cmp = strcmp(str1->content, str2->content);
    return cmp < 0;
}

bool string_eq(const string str1, const string str2) {
    int cmp = strcmp(str1->content, str2->content);
    return cmp == 0;
}

string string_clone(const string str) {
    return (string_create(str->content));
}

string string_destroy(string str) {
    /*implementation*/
    if (str != NULL){
        free(str->content);
        free(str);
    }
    return NULL;
}

void string_dump(string str, FILE *file) {
    fprintf(file, "%s", str->content);
}

const char *string_ref(string str) {
    return (str->content);
}
