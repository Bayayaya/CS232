/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int compares(char* String1, char* String2); //Compare String1 with String2, return 0 if need to swap, otherwise return 1.
void swaps(char* String1, char* String2); //Swap two strings

int main() {

  char Strings[NUM][LEN];

  printf("Please enter %d strings, one per line:\n", NUM);
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */
  for (int i = 0; i < NUM; i++) {
    fgets(Strings[i], LEN , stdin);
  }



  puts("\nHere are the strings in the order you entered:");
  /* Write a for loop here to print all the strings. */

  for (int i = 0; i < NUM; i++) {
    printf("%s", Strings[i]);
  }

  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) The swap of two strings must be done by copying them
            (using a temp variable of your choice) one character at a time,
            without using any C string library functions.
            That is, write your own while/for loop to do this.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */

  int check = 1;
  do {
    check = 1;
    for (int i = 1; i < NUM; i++) {

      if (compares(Strings[i - 1], Strings[i]) == 0) {
        swaps(Strings[i - 1], Strings[i]);
        check = 0;
      }

    }
  } while (check == 0);

  /* Output sorted list */

  puts("\nIn alphabetical order, the strings are:");
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

  for (int i = 0; i < NUM; i++) {
    printf("%s", Strings[i]);
  }

}

int compares(char* String1, char* String2) {
  int len = 0;

  if (strlen(String1) < strlen(String2)) {
    len = strlen(String1);
  } else {
    len = strlen(String2);
  }
  //String1 strickly smaller or bigger than String2
  for (int i = 0; i < len; i++) {
    if (String1[i] > String2[i]) {
      return 0; //need to swap
    }
    if (String1[i] < String2[i]) {
      return 1; //dont' swap
    }
  }

//if first len characters of String1 same as first len characters of String2
  if (strlen(String1) < strlen(String2)) {
    return 1; //don't swap
  } else {
    return 0; //swap
  }

}

void swaps(char* String1, char* String2) {

  int len = 0;

  if (strlen(String1) > strlen(String2)) {
    len = strlen(String1);
  } else {
    len = strlen(String2);
  }

  char temp[len + 1];

  for (int j = 0; j < len + 1; j++) {
    temp[j] = String1[j];
    String1[j] = String2[j];
    String2[j] = temp[j];
  }

}


