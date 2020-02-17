#include <stdio.h>
#include <stdlib.h>


void rotate_4(int *p_a, int*p_b, int*p_c, int* p_d) {
    //TO-DO: please implement left rotate 4 integers by one position

    int temp;
    temp = * p_a;
    * p_a = * p_b;
    * p_b = * p_c;
    * p_c = * p_d;
    * p_d = temp;
}

int main(int argc, char ** argv) { // char* = Array of chars = String; char ** = Array of Strings

    //TO-DO check if there are 4 inputs.
    //print out an error message if there are not enough inputs.
    //hint: use argc

    if (argc != 5) {
        printf("%d\n", argc);
        puts("Error: rotate needs four numbers");
    } else {

        int a = atoi(argv[1]); //atoi converts string to int
        int b = atoi(argv[2]);
        int c = atoi(argv[3]);
        int d = atoi(argv[4]);

        rotate_4(&a, &b, &c, &d);
        printf("%d %d %d %d\n", a, b, c, d);

    }
    return 0;
}
