/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <string.h>

void CS232(char* src, int length) {
    //char * srcptr, replaceptr;
    char *srcptr, *replaceptr;
    char *replacement = "232 is awesome!";//15 + NULL
    srcptr = src;
    replaceptr = replacement;
    if (length >= strlen(replacement)+1) {
        for (int i = 0; i < strlen(replacement)+1; i++) {
            *srcptr++ = *replaceptr++;
        }
    }
}

void replace_string(char* str, int length) {
    //char str[15];
    CS232(str, length);
    //return str;

}

int main(int argc, char ** argv) {
    char ret[16];
    replace_string(ret, 16);
    printf("replaced string = %s\n", ret);
    return 0;
}
