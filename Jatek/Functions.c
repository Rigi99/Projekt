#include "Header.h"
Palya* createPalya(const char* fajl) {
	Palya* palya;
	FILE* f = fopen(fajl, "rt");
	if (!f) {
		printf("Sikertelen fajlmegnyitas!");
		return -5;
	}
	palya = (Palya*)calloc(1, sizeof(Palya));
	fscanf(f, "%i%i\n", &palya->hossz, &palya->szel);
	palya->palya = (char**)calloc(palya->hossz, sizeof(char*));
	palya->golyo = (char**)calloc(palya->hossz, sizeof(char*));
	if (!palya->palya || !palya->golyo) {
		printf("Sikertelen helyfoglalas!");
		return -5;
	}
	for (int i = 0; i < palya->hossz; ++i) {
		palya->palya[i] = (char*)calloc(palya->szel, sizeof(char));
		palya->golyo[i] = (char*)calloc(palya->szel, sizeof(char));
		if (!palya->palya[i] || !palya->golyo[i]) {
			printf("Sikertelen helyfoglalas!");
			return -5;
		}
	}
	fclose(f);
	return palya;
}
void beolvasPalya(const char* fajl, char** palya) {
	FILE* f = fopen(fajl, "rt");
	if (!f) {
		printf("Sikertelen fajlmegnyitas!");
		return -5;
	}
	int a, b;
	fscanf(f, "%i%i\n", &a, &b);
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			fscanf(f, "%c\n", &palya[i][j]);
		}
	}
	fclose(f);
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
Palya* jatekMenet(Palya* palya) {
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
		if (palya->palya[jatekosX][jatekosY] == 'G' || palya->palya[jatekosX][jatekosY] == 'l') {
			++palya->fegyver;
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == '1') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == '2') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == '3') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == 'F') {
			palya->b = true;
			return palya;
		}
		system("CLS");
	}
}
Palya* jatekMenetExtra(Palya* palya) {
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya->palya[jatekosX][jatekosY] = 'P';
	palya->bossElet = 4;
	for (int i = 0; i < palya->hossz; ++i) {
		for (int j = 0; j < palya->szel; ++j) {
			if (palya->palya[i][j] == 'B') {
				palya->bossX = i;
				palya->bossY = j;
			}
		}
	}
	int bossX = palya->bossX, bossY = palya->bossY;
	while (1) {
		kirajzolPalya(palya);
		printf("Jobb: d\nLe: s\nBal: a\nFel: w\nLoves: f\n");
		printf("Lovedekek szama: %i", palya->fegyver);
		printf("\nBoss elete: %i\n", palya->bossElet);
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
		if (palya->palya[jatekosX][jatekosY] == 'G' || palya->palya[jatekosX][jatekosY] == 'l') {
			++palya->fegyver;
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (option == 'f') {
			palya->golyo[jatekosX][jatekosY + 1] = '*';
			kirajzolPalya(palya);
			system("pause");
			for (int i = jatekosY + 2; i <= bossY; ++i) {
				palya->golyo[jatekosX][i] = '*';
				kirajzolPalya(palya);
				system("pause");
				palya->golyo[jatekosX][i - 1] = '0';
				//kirajzolPalya(palya);
				system("CLS");	
			}
			if (jatekosX == bossX || jatekosY == bossY) {
				--palya->fegyver;
				--palya->bossElet;
			}
		}
		if (palya->palya[jatekosX][jatekosY] == '1') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == '2') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == '3') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == '$') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == 'B') {
			palya->b = false;
			return palya;
		}
		if (palya->palya[jatekosX][jatekosY] == 'F') {
			palya->b = true;
			return palya;
		}
		if (palya->fegyver == 0 && palya->bossElet != 0) {
			palya->b = false;
			return palya;
		}
		else if (palya->bossElet == 0) {
			palya->b = true;
			return palya;
		}
		system("CLS");
	}
}