#include <stdio.h>

int main(int argc, char *argv[]) {

	/* example:
	 *  char str[10090];
	   int ch, n = 0;

	   while ((ch = getchar()) != EOF && n < 1000) {
	      str[n] = ch;
	      ++n;
	   }

	   for (int i = 0; i < n; ++i)
	      putchar(str[i]);


	   return 0;

	 */

	char str[100];
	int ch, n = 0;

	while ((ch = getchar()) != EOF && n < 100) { //EOF = end of file
		str[n] = ch; //convert int to a char
		++n;
	}
	
	int i;

	for (i = 0; i < n ; ++i) {
		if(str[i]>= 'a' & str[i]<= 'z'){
			str[i] -='a' - 'A';
		}
	}


	for (int i = 0; i < n; ++i)
		putchar(str[i]);

	putchar('\n');

	return 0;
}

