#include "Header.h"
Palya* beolvasPalya(const char* fajl) {
	Palya* palya;
	FILE* f = fopen(fajl, "rt");
	if (!f) {
		printf("Sikertelen fajlmegnyitas!");
		return -5;
	}
	palya = (Palya*)calloc(1, sizeof(Palya));
	fscanf(f, "%i%i\n", &palya->hossz, &palya->szel);
	palya->palya = (char**)calloc(palya->hossz, sizeof(char*));
	if (!palya->palya) {
		printf("Sikertelen helyfoglalas!");
		return -5;
	}
	for (int i = 0; i < palya->hossz; ++i) {
		palya->palya[i] = (char*)calloc(palya->szel, sizeof(char));
		if (!palya->palya[i]) {
			printf("Sikertelen helyfoglalas!");
			return -5;
		}
	}
	for (int i = 0; i < palya->hossz; ++i) {
		for (int j = 0; j < palya->szel; ++j) {
			fscanf(f, "%c\n", &palya->palya[i][j]);
		}
	}
	return palya;
}
void kirajzolPalya(Palya* palya) {
	for (int i = 0; i < palya->hossz; ++i) {
		for (int j = 0; j < palya->szel; ++j) {
			if (palya->palya[i][j] == '3' && (i == 0 || i == palya->hossz - 1)) {
				printf("-");
				continue;
			}
			else if (palya->palya[i][j] == '2') {
				printf("#");
				continue;
			}
			else if (palya->palya[i][j] == '1') {
				printf("|");
				continue;
			}
			if (palya->palya[i][j] == '0') {
				printf(" ");
				continue;
			}
			else {
				printf("%c", palya->palya[i][j]);
				continue;
			}
		}
		printf("\n");
	}
}
bool jatekMenet(Palya* palya) {
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya->palya[jatekosX][jatekosY] = 'P';
	palya->fegyver = 0;
	while (1) {
		kirajzolPalya(palya);
		printf("Jobb: d\nLe: s\nBal: a\nFel: w\n");
		printf("Lovedekek szama: %i", palya->fegyver);
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'd') {
			jatekosY++;
		}
		if (option == 's') {
			jatekosX++;
		}
		if (option == 'a') {
			--jatekosY;
		}
		if (option == 'w') {
			--jatekosX;
		}
		if (palya->palya[jatekosX][jatekosY] == '0') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == '1') {
			return false;
		}
		if (palya->palya[jatekosX][jatekosY] == '2') {
			return false;
		}
		if (palya->palya[jatekosX][jatekosY] == '3') {
			return false;
		}
		if (palya->palya[jatekosX][jatekosY] == 'F') {
			return true;
		}
		if (palya->palya[jatekosX][jatekosY] == 'G' || palya->palya[jatekosX][jatekosY] == 'l') {
			++palya->fegyver;
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		system("CLS");
	}
}
bool jatekMenetExtra(Palya* palya) {
	srand(time(NULL));
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	int bossX, bossY = palya->szel - 1;
	int** lovedek[1][1];
	int** boss[2][2];
	palya->palya[jatekosX][jatekosY] = 'P';
	palya->fegyver = 0;
	while (1) {
		kirajzolPalya(palya);
		printf("Jobb: d\nLe: s\nBal: a\nFel: w\nLoves: f\n");
		printf("Lovedekek szama: %i", palya->fegyver);
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'd') {
			jatekosY++;
		}
		if (option == 's') {
			jatekosX++;
		}
		if (option == 'a') {
			--jatekosY;
		}
		if (option == 'w') {
			--jatekosX;
		}
		if (option == "f") {
			for (int i = jatekosY + 1; i < palya->szel; ++i) {
				if (lovedek[jatekosX][jatekosY] == '0') {
					palya->palya[jatekosX][jatekosY] = 'P';
					palya->palya[elozoX][elozoY] = '0';
				}
			}
		}
		if (palya->palya[jatekosX][jatekosY] == '0') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == '1') {
			return false;
		}
		if (palya->palya[jatekosX][jatekosY] == '2') {
			return false;
		}
		if (palya->palya[jatekosX][jatekosY] == '3') {
			return false;
		}
		if (palya->palya[jatekosX][jatekosY] == 'F') {
			return true;
		}
		if (palya->palya[jatekosX][jatekosY] == 'G' || palya->palya[jatekosX][jatekosY] == 'l') {
			++palya->fegyver;
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		//lovoldozes;
		if (palya->fegyver == 0) {
			return false;
		}
		system("CLS");
	}
}