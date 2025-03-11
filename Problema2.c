#include <stdio.h>
#define NMAX 100

void patrat(int l, int u)
{
	if (l < 1 || l > 100) {
		printf("Unsupported size to display shape\n");
		return;
	}
	if (u % 90 == 0) {
		for (int a = 0; a < l; a++) {
			for (int b = 0; b < l; b++) {
				printf("*");
			}
			printf("\n");
		}
	} else if (u % 45 == 0) {
		if (l == 1)
			printf("*\n");
		else {
			int nr_spaces = l - 1, nr_stars = 1;
			while (nr_spaces >= 0) {
				for (int i = 0; i < nr_spaces; i++)
					printf(" ");
				for (int i = 0; i < nr_stars; i++)
					printf("*");
				printf("\n");
				nr_spaces--;
				nr_stars += 2;
			}
			nr_stars -= 4;
			nr_spaces += 2;
			while (nr_stars >= 1) {
				for (int i = 0; i < nr_spaces; i++)
					printf(" ");
				for (int i = 0; i < nr_stars; i++)
					printf("*");
				printf("\n");
				nr_spaces++;
				nr_stars -= 2;
			}
		}
	} else
		printf("Unsupported angle to display shape\n");
}

void dreptunghi(int l, int h)
{
	if (l < 1 || l > 100 || h < 1 || h > 100) {
		printf("Unsupported size to display shape\n");
		return;
	}
	for (int a = 0; a < h; a++) {
		for (int b = 0; b < l; b++) {
			printf("*");
		}
		printf("\n");
	}
}

void triunghi(int l, int u)
{
	if (l < 1 || l > 100) {
		printf("Unsupported size to display shape\n");
		return;
	}
	if (u % 90 != 0) {
		printf("Unsupported angle to display shape\n");
		return;
	}
	int caz = 0;
	if ((u / 90) % 4 == -1)
		caz = 3;
	else if ((u / 90) % 4 == -2)
		caz = 2;
	else if ((u / 90) % 4 == -3)
		caz = 1;
	else
		caz = (u / 90) % 4;
	if (caz == 0) { //prima forma
		int nr_stars = 1, star_counter = 0, row = 0;
		while (row != l) {
			while (star_counter != nr_stars) {
				printf("*");
				star_counter++;
			}
			printf("\n");
			row++;
			nr_stars++;
			star_counter = 0;
		}
	} else if (caz == 1) {//a 2 a
		int nr_stars = l, star_counter = 0, row = 0;
		while (row != l) {
			while (star_counter != nr_stars) {
				printf("*");
				star_counter++;
			}
			printf("\n");
			row++;
			nr_stars--;
			star_counter = 0;
		}
	} else if (caz == 2) {//a 3 a
		int nr_stars = l, star_counter = 0;
		int nr_spaces = 0, space_counter = 0, row = 0;
		while (row != l) {
			while (nr_spaces != space_counter) {
				printf(" ");
				space_counter++;
			}
			nr_spaces++;
			space_counter = 0;
			while (nr_stars != star_counter) {
				printf("*");
				star_counter++;
			}
			star_counter = 0;
			nr_stars--;
			printf("\n");
			row++;
		}
	} else if (caz == 3) {//a 4 a
		int nr_stars = 1, star_counter = 0;
		int nr_spaces = l - 1, space_counter = 0, row = 0;
		while (row != l) {
			while (nr_spaces != space_counter) {
				printf(" ");
				space_counter++;
			}
			nr_spaces--;
			space_counter = 0;
			while (nr_stars != star_counter) {
				printf("*");
				star_counter++;
			}
			star_counter = 0;
			nr_stars++;
			printf("\n"); row++;
		}
	}
}

void cruce(int l, int u)
{
	if (l < 1 || l > 100 || (l % 2 == 0))
		printf("Unsupported size to display shape\n");
	else if (u % 90 == 0) { // forma similara unui "+"
		int nr_spaces = l / 2, space_counter = 0, row = 0;
		while (row != l) {
			if (row != l / 2) {//randurile cu o stea
				while (nr_spaces != space_counter) {
					printf(" ");
					space_counter++;
				}
				printf("*\n");
				space_counter = 0;
			} else { //randul cu l stele
				int star_counter = 0;
				while (star_counter != l) {
					printf("*");
					star_counter++;
				}
				printf("\n");
			}
			row++;
		}
	} else if (u % 45 == 0) { // forma similara unui "x"
		int row = 0;
		//pentru spatiile dinainte de prima "*"
		int nr_spaces_bf = 0, space_counter_bf = 0;
		//pentru spatiile de dupa prima "*"
		int nr_spaces_af = l - 2, space_counter_af = 0;
		while (row != l) {
			if (row < l / 2) {
				while (nr_spaces_bf != space_counter_bf) {
					printf(" ");
					space_counter_bf++;
				}
				printf("*");
				space_counter_bf = 0;
				nr_spaces_bf++;
				while (nr_spaces_af != space_counter_af) {
					printf(" ");
					space_counter_af++;
				}
				printf("*\n");
				space_counter_af = 0;
				nr_spaces_af -= 2;
			} else if (row == l / 2) {
				while (nr_spaces_bf != space_counter_bf) {
					printf(" ");
					space_counter_bf++;
				}
				printf("*\n");
				nr_spaces_bf--;
				space_counter_bf = 0;
				nr_spaces_af = 1;
			} else if (row >= l / 2) {
				while (nr_spaces_bf != space_counter_bf) {
					printf(" ");
					space_counter_bf++;
				}
				printf("*");
				space_counter_bf = 0;
				nr_spaces_bf--;
				while (nr_spaces_af != space_counter_af) {
					printf(" ");
					space_counter_af++;
				}
				printf("*\n");
				space_counter_af = 0;
				nr_spaces_af += 2;
			}
			row++;
		}
	} else
		printf("Unsupported angle to display shape\n");
}

void fereastra(int l)
{
	int nr_spaces = l / 2 - 1, space_counter = 0, row = 0;
	if (l < 5 || l > 100 || (l % 2 == 0))
		printf("Unsupported size to display shape\n");
	else
		while (row != l) {
			if (!(row == 0 || (row == l / 2) || (row == l - 1))) {
				printf("*");
				while (nr_spaces != space_counter) {
					printf(" ");
					space_counter++;
				}
				printf("*");
				space_counter = 0;
				while (nr_spaces != space_counter) {
					printf(" ");
					space_counter++;
				}
				printf("*\n");
				space_counter = 0;
			} else if ((row == 0) || (row == l / 2) || (row == l - 1)) {
				//randurile cu l stele
				int star_counter = 0;
				while (star_counter != l) {
					printf("*");
					star_counter++;
				}
				printf("\n");
			}
			row++;
		}
}

int main(void)
{
	int N, v1 = 0, v2 = 0, forme[NMAX][NMAX];
	char tip;
	//folosesc variabila first_figure pentru a nu afisa newline
	//inainte de prima figura pe care o voi afisa, dar la restul da
	int first_figure = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c", &tip);
		if (tip == 'f') {
			scanf("%d", &v1);
			forme[i][0] = 5; // 5 = 'f'
			forme[i][1] = v1;
		} else {
			scanf("%d%d", &v1, &v2);
			//salvez toate valorile citite in o matrice cu 3 coloane
			//unde prima este pentru tip (p,d,t,c,f)
			if (tip == 'p') {
				forme[i][0] = 1; // 1 = 'p'
				forme[i][1] = v1;
				forme[i][2] = v2;
			}
			if (tip == 'd') {
				forme[i][0] = 2; // 2 = 'd'
				forme[i][1] = v1;
				forme[i][2] = v2;
			}
			if (tip == 't') {
				forme[i][0] = 3; // 3 = 't'
				forme[i][1] = v1;
				forme[i][2] = v2;
			}
			if (tip == 'c') {
				forme[i][0] = 4; // 4 = 'c'
				forme[i][1] = v1;
				forme[i][2] = v2;
			}
		}
	}

	for (int len = 0; len < N; len++) {
		if (first_figure == 0)
			first_figure = 1;
		else
			printf("\n");

		//patrat
		if (forme[len][0] == 1)
			patrat(forme[len][1], forme[len][2]);

		//dreptunghi
		if (forme[len][0] == 2)
			dreptunghi(forme[len][1], forme[len][2]);

		//triunghi
		if (forme[len][0] == 3)
			triunghi(forme[len][1], forme[len][2]);

		//cruce
		if (forme[len][0] == 4)
			cruce(forme[len][1], forme[len][2]);

		//fereastra
		if (forme[len][0] == 5)
			fereastra(forme[len][1]);
	}
	return 0;
}
