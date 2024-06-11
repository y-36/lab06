#include <stdio.h>
#include "string.h"

int main(void) {
    string str1 = string_create("hello");
    string str2 = string_create("worlds");
    string str3 = string_create("hello");

    // Comparar str1 con str2
    if (string_less(str1, str2)) {
        printf("'%s' is less than '%s'\n", string_ref(str1), string_ref(str2));
    } else {
        printf("'%s' is not less than '%s'\n", string_ref(str1), string_ref(str2));
    }

    // Comparar str1 con str3
    if (string_eq(str1, str3)) {
        printf("'%s' is equal to '%s'\n", string_ref(str1), string_ref(str3));
    } else {
        printf("'%s' is not equal to '%s'\n", string_ref(str1), string_ref(str3));
    }

    // Liberar memoria
    str1 = string_destroy(str1);
    str2 = string_destroy(str2);
    str3 = string_destroy(str3);

    return 0;
}
