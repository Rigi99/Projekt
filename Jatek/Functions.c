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
	//system("pause");
}
bool jatekMenet(Palya* palya) {
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya->palya[jatekosX][jatekosY] = 'P';
	while (1) {
		kirajzolPalya(palya);
		printf("Jobb: d\nLe: s\nBal: a\nFel: w\n");
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
		if (palya->palya[jatekosX][jatekosY] == 'F') {
			return true;
		}
		system("CLS");
	}
}