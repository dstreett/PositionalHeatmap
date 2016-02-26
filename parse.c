#include <stdio.h>
#include <stdlib.h>

void parseTile(char line[], int nbytes);

void qualityAve(char *line) {
	int i = 0;
	double total = 0, count = 0;

	while (line[i] != '\n') {
		total += line[i] - 32;
		count++;
		i++;
	}
	
    /*I could cast i to get then amount*/
	printf("%f\n", total/count);
}
		

int main(int argc, char *argv[]) {

	FILE * file = fopen(argv[1], "r");

	if (file == 0) {
		printf("Bad File\n");
		exit(0);
	} else {
        //Arb size of char []
		int nbytes = 1024;
		char lineStr[nbytes];
		int lineNum = 0;
        /*The first little bit is just junk from old code*/
        printf("meh\twhat\tlane\ttile\tx_coor\ty_coor\tave_qual\n");


        /*reads everything in*/
		while(fgets(lineStr, sizeof(lineStr), file)) {
			lineNum++;
			if (lineNum == 1) {
				parseTile(lineStr, nbytes);
			} else if (lineNum == 4) {
				qualityAve(lineStr);
				lineNum = 0;
			}
		}
	}

	fclose(file);
}


void parseTile(char line[], int nbytes) {
	
	int i = 0;
	int count = 0;
	int newStr[1024];
	int location = 0;

	for (i = 0; line[i] != '\0'; i++) {
        /*The program wants the location bits of the header name - so we don't care about the first part
         * (after the first ":") hence why we need to keep track of location. It returns based on there
         * We want everything after that until a space, newline, null (or anything) so we replace those with a
         * \0. I just like tabs better so I swap all ':' with tabs. */

		if (line[i] == ':') {
			count++;
			line[i] = '\t';
		} else if (count == 1) {
			location = i;
			count++;
		} else if (line[i] == '#' || line[i] == ' ' || line[i] == '/' || line[i] == '\n') {
			line[i] = '\0';
			break;
		}	
	}
    /*Returns after all junk, until the \0 which is the end of the location information*/
	printf("%s\t", &line[location]);	
}
