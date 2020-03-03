#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* readinput();

int main () {

	int ctc = 0, ctw = 0, ctln = 0, ctsp = 0, ctup = 0, ctlw = 0, ctnm = 0;
	bool shouldkeepgoing;
	do {
		char* Strings = readinput();
		int stringlen = strlen(Strings); // include null
		//printf("%s string lenth is %d\n", Strings, stringlen);
		ctc += (stringlen);
		ctln ++;
		for (int i = 0; i < stringlen; i++) {


			if (Strings[i] >= 'A' && Strings[i] <= 'Z') {
				ctup++;
			} else if (Strings[i] >= 'a' && Strings[i] <= 'z') {
				ctlw++;
			} else if (Strings[i] >= '0' && Strings[i] <= '9') {
				ctnm++;
			} else if (Strings[i] == '\t' || Strings[i] == ' ' ) {
				ctsp++;
			}
			bool wordck = Strings[i] != ' ' && Strings[i] != '\n' && Strings[i] != '\t'; //check if String[i] is white space or new line

			if (wordck && (i == 0 || Strings[i - 1] == ' ' || Strings[i - 1] == '\n' || Strings[i - 1] == '\t')) {
				//if String[i] is white space or a new line and i ==0, then add one word.
				//if String[i] is white space or a new line and previous char is not white space or new line, then add one word
				ctw++;
			}
		}
		shouldkeepgoing = stringlen != 0 && Strings[stringlen - 1] == '\n';
		//printf("char %d, word %d, line %d, space %d, upcase %d, lowercase %d, number %d\n", ctc, ctw, ctln, ctsp, ctup, ctlw, ctnm);

		//printf("%d %d %d %d %d %d %d\n", ctc, ctw, ctln, ctsp, ctup, ctlw, ctnm);
		free(Strings);
	} while (shouldkeepgoing); //check whether Strings reach to EOF

	printf("%d %d %d %d %d %d %d\n", ctc, ctw, ctln, ctsp, ctup, ctlw, ctnm);
}


char* readinput() {
#define CHUNK 10
	char* input = NULL;
	char buff[CHUNK];
	int inputlen = 0, templen = 0;
	do {
		char* ret = fgets(buff, CHUNK, stdin);
		if (ret == NULL) {
			buff[0] = '\0';
		}// check if buff reach to end of file and then clear buff
		templen = strlen(buff);
		input = (char*)realloc(input, inputlen + templen + 1);
		strcpy(input + inputlen, buff); // how to copy and the length
		inputlen += templen;
	} while (templen == CHUNK - 1 && buff[CHUNK - 2] != '\n');
	return input;
}
