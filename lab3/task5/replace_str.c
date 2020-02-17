/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <string.h>

void CS232(char* src) {
     //char * srcptr, replaceptr; 
     char *srcptr, *replaceptr;
     int srcLength = strlen(src);
     char replacement[15] = "232 is awesome!";
     srcptr = src;
     replaceptr = replacement;
     if (srcLength >= 15) {
         for (int i = 0; i < 15; i++)
          *srcptr++ = *replaceptr++;
     }
}

void replace_string(char* str) {
    //char str[15];
    CS232(str);
   //return str;

}

int main(int argc, char ** argv) {
    char ret[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
    replace_string(ret);
    printf("replaced string = %s\n", ret);
    return 0;
}
