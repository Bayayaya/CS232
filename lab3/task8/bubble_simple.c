/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h> /* Need for malloc */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int compares(char* String1, char* String2); //Compare String1 with String2, return 0 if need to swap, otherwise return 1.
void swaps(char* String1, char* String2); //Swap two strings

int main() {

  char* Strings[NUM];
  for (int i = 0; i < NUM; i++) {
    Strings[i] = (char*) malloc (LEN);
  }
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
        (i) The comparison of two strings by strncmp()
       (ii) Swap two strings by strcpy()
  */

  int check = 1;
  do {
    check = 1;
    for (int i = 1; i < NUM; i++) {

      if (strncmp(Strings[i - 1], Strings[i],LEN) > 0) {
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

  for (int i = 0; i < NUM; i++) {
    free(Strings[i]);
  }

  return 0;

}

//swap pointer
void swaps(char* String1, char* String2) {

  char *temp = (char *)malloc((strlen(String1) + 1) * sizeof(char)); 
  strcpy(temp, String1); 
  strcpy(String1, String2); 
  strcpy(String2, temp); 
  free(temp); 

}


