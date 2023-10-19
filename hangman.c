#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <curses.h>
#define system(cls) printf("\e[1;1H\e[2J")
#endif

void logo() {
	printf("\n\t\t\t    :::::::::::::::::::::::");
	printf("\n\t\t\t    :::			:::");
	printf("\n\t\t\t    :::     HANGMAN	:::");
	printf("\n\t\t\t    :::			:::");
	printf("\n\t\t\t    :::::::::::::::::::::::");
}

int main() {
	int i, c, count = 0, flag = 0, temp = 0;
	char a[50], b[50], d = '_', x, ch;
	char *next, *movieName;
	int movieIndex;
	time_t rdnSeed;

	srand((unsigned)time(&rdnSeed));
	system("cls");
	logo();

	FILE *pFile;
	long lSize;
	char *completeList;

	pFile = fopen("movieList", "rb");
	if (pFile == NULL) {
		perror("File cannot be opened");
		exit(1);
	}

	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	completeList = malloc(sizeof(char) * lSize);
	if (completeList == NULL) {
		perror("malloc() failed");
		exit(1);
	}

	fread(completeList, 1, lSize, pFile);
	// printf("%s\n\n",completeList);
	fclose(pFile);

	movieIndex = rand() % 90;
	next = strtok(completeList, "\n");
	while (next != NULL) {
		if (movieIndex == 0) {
			movieName = next;
		}
		next = strtok(NULL, "\n");
		movieIndex--;
	}
	// printf("\n%s\n",movieName);

	for (c = 0; c < 50 && movieName[c] != 0; c++) {
		a[c] = movieName[c];
	}

	printf("\n\n\n\t******************************************");
	printf("\n\t..........................................\n");

	for (i = 0; i < 38 - (c / 2); i++) {
		printf(" ");
	}

	for (i = 0; i < c; i++) {
		if ((a[i] > 96 && a[i] < 123) || (a[i] > 64 && a[i] < 91)) {
			printf("%c", d);
		} else {
			printf("%c", a[i]);
		}
		b[i] = d;
	}

	printf("\n\t..........................................");
	printf("\n\t******************************************\n\n");

	while (count < c) {
		flag = 0;
		printf("\n\n\n\n\t\tEnter any character: ");
		x = getch();

		for (i = 0; i < c; i++) {
			if (x == a[i]) {
				b[i] = a[i];
				flag = 1;
				temp++;
			}
		}

		system("cls"); // clrscr();
		logo();
		printf("\n\n\n\t	  "
		       "******************************************");
		printf("\n\t	      "
		       "..........................................\n");

		for (i = 0; i < 38 - (c / 2); i++) {
			printf(" ");
		}

		for (i = 0; i < c; i++) {
			if ((a[i] > 96 && a[i] < 123) ||
			    (a[i] > 64 && a[i] < 91)) {
				printf("%c", b[i]);
			} else {
				printf("%c", a[i]);
			}
		}

		printf(
		    "\n\t	   ..........................................");
		printf("\n\t	      "
		       "******************************************\n\n");

		if (flag == 0) {
			count++;
			printf("\n\n\t\t\t	%c is a wrong guess", x);
			printf("\n\t\t\t    you have %d more chance ",
			       c - count);
			printf("\n\t\t\t    %d more word remaining", c - temp);
		} else {
			count++;
			printf("\n\n\t\t\t   *** you are correct ***");
			printf("\n\t\t\t    you have %d more chance ",
			       c - count);
			printf("\n\t\t\t    %d more word remaining", c - temp);
		}

		if (temp == c) {
			break;
		}
	}
	if (temp == c) {
		printf("\n\n\n\t\t	  :)  @*@*@* YOU WON *@*@*@  :)");
	} else {
		printf("\n\n\n\t\t	  :( YOU LOSE :(");
		printf("\n\t\t	      :( YOU ARE HANGED :(");
	}

	getch();
	free(completeList);
	return 0;
}
