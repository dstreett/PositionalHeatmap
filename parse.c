#include <stdio.h>
#include <stdlib.h>

void parseTile(char line[], int nbytes);

void qualityAve(char *line) {
	int i = 0;
	double total = 0, count = 0;
	while (line[i] != '\n') {
		total += line[i] - 32;
		count = count + 1;
		i++;
	}
	
	printf("%f\n", total/count);
}
		

int main(int argc, char *argv[]) {

	FILE * file = fopen(argv[1], "r");

	if (file == 0) {
		printf("Bad\n");
		exit(0);
	} else {
		int nbytes = 1024;
		char lineStr[nbytes];
		int lineNum = 0;
		printf("lane\ttile\tx_coor\ty_coor\tave_qual\n");

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
		if (line[i] == ':') {
			count++;
			line[i] = '\t';
		} else if (count == 3) {
			location = i;
			count++;
		} else if (line[i] == '#' || line[i] == ' ' || line[i] == ':' || line[i] == '/' || line[i] == '\n') {
			line[i] = '\0';
			break;
		}	

	}
	printf("%s\t", &line[location]);	
}
