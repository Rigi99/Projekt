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
			if (palya->palya[i][j] == '0' || palya->palya[i][j] == 'M') {
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
		printf("Lovedekek szama: %i", palya->fegyver);
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'w') {
			--jatekosX;
		}
		if (option == 'a') {	
			--jatekosY;
		}
		if (option == 's') {
			++jatekosX;
		}
		if (option == 'd') {
			++jatekosY;
		}
		if (palya->palya[jatekosX][jatekosY] == '0' || palya->palya[jatekosX][jatekosY] == 'M') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'f') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'e') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'g') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'y') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'v') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'e') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'r') {
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
			palya->f = true;
		}
		if (palya->palya[jatekosX][jatekosY] == 'f') {
			++palya->fegyver;
			palya->palya[jatekosX][jatekosY] = 'P';
			palya->palya[elozoX][elozoY] = '0';
		}
		if (palya->palya[jatekosX][jatekosY] == 'G') {
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
	int golyoX, golyoY;
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
	if (palya->f && palya->fegyver != 0) {
		while (1) {
			kirajzolPalya(palya);
			printf("Loves felfele: f\nLoves lefele: l\nLoves jobbra: j\nLoves balra: b\n");
			printf("Lovedekek szama: %i", palya->fegyver);
			printf("\nBoss elete: %i\n", palya->bossElet);
			char option = getch();
			elozoX = jatekosX;
			elozoY = jatekosY;
			if (option == 'w') {
				--jatekosX;
			}
			if (option == 'a') {

				--jatekosY;
			}
			if (option == 's') {
				jatekosX++;
			}
			if (option == 'd') {
				jatekosY++;
			}
			if (palya->palya[jatekosX][jatekosY] == '0' || palya->palya[jatekosX][jatekosY] == 'M') {
				palya->palya[jatekosX][jatekosY] = 'P';
				palya->palya[elozoX][elozoY] = '0';
			}
			if (option == 'l') {
				golyoX = jatekosX + 2;
				golyoY = jatekosY;
				while (1) {
					if (palya->palya[golyoX][golyoY] == '0' || palya->palya[jatekosX][jatekosY] == 'M' || palya->palya[golyoX][golyoY] == '$') {
						palya->palya[golyoX][golyoY] = '*';
						palya->palya[elozoX][elozoY] = 'P';
						palya->palya[golyoX - 1][golyoY] = '0';
						++golyoX;
					}
					system("CLS");
					kirajzolPalya(palya);
					if (palya->palya[golyoX][golyoY] == 'B') {
						palya->palya[golyoX - 1][golyoY] = '$';
						--palya->bossElet;
						break;
					}
					if (palya->palya[golyoX][golyoY] == '3' || palya->palya[golyoX][golyoY] == '2') {
						palya->palya[golyoX - 1][golyoY] = '0';
						break;
					}
				}
				--palya->fegyver;
			}
			if (option == 'j') {
				golyoY = jatekosY + 2;
				golyoX = jatekosX;
				while (1) {
					if (palya->palya[golyoX][golyoY] == '0' || palya->palya[jatekosX][jatekosY] == 'M' || palya->palya[golyoX][golyoY] == '$') {
						palya->palya[golyoX][golyoY] = '*';
						palya->palya[elozoX][elozoY] = 'P';
						palya->palya[golyoX][golyoY - 1] = '0';
						++golyoY;
					}
					system("CLS");
					kirajzolPalya(palya);
					if (palya->palya[golyoX][golyoY] == 'B') {
						palya->palya[golyoX][golyoY - 1] = '$';
						--palya->bossElet;
						break;
					}
					if (palya->palya[golyoX][golyoY] == '1' || palya->palya[golyoX][golyoY] == '2') {
						palya->palya[golyoX][golyoY - 1] = '0';
						break;
					}
				}
				--palya->fegyver;
			}
			if (option == 'b') {
				golyoY = jatekosY - 2;
				golyoX = jatekosX;
				while (1) {
					if (palya->palya[golyoX][golyoY] == '0' || palya->palya[jatekosX][jatekosY] == 'M' || palya->palya[golyoX][golyoY] == '$') {
						palya->palya[golyoX][golyoY] = '*';
						palya->palya[elozoX][elozoY] = 'P';
						palya->palya[golyoX][golyoY + 1] = '0';
						--golyoY;
					}
					system("CLS");
					kirajzolPalya(palya);
					if (palya->palya[golyoX][golyoY] == 'B') {
						palya->palya[golyoX][golyoY + 1] = '$';
						--palya->bossElet;
						break;
					}
					if (palya->palya[golyoX][golyoY] == '1' || palya->palya[golyoX][golyoY] == '2') {
						palya->palya[golyoX][golyoY + 1] = '0';
						break;
					}
				}
				--palya->fegyver;
			}
			if (option == 'f') {
				golyoX = jatekosX - 2;
				golyoY = jatekosY;
				while (1) {
					if (palya->palya[golyoX][golyoY] == '0' || palya->palya[jatekosX][jatekosY] == 'M' || palya->palya[golyoX][golyoY] == '$') {
						palya->palya[golyoX][golyoY] = '*';
						palya->palya[elozoX][elozoY] = 'P';
						palya->palya[golyoX + 1][golyoY] = '0';
						--golyoX;
					}
					system("CLS");
					kirajzolPalya(palya);
					if (palya->palya[golyoX][golyoY] == 'B') {
						palya->palya[golyoX + 1][golyoY] = '$';
						--palya->bossElet;
						break;
					}
					if (palya->palya[golyoX][golyoY] == '3' || palya->palya[golyoX][golyoY] == '2') {
						palya->palya[golyoX + 1][golyoY] = '0';
						break;
					}
				}
				--palya->fegyver;
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
			if (palya->palya[jatekosX][jatekosY] == 'A') {
				palya->b = false;
				return palya;
			}
			if (palya->palya[jatekosX][jatekosY] == 'F') {
				palya->b = true;
				return palya;
			}
			if (palya->fegyver == 0) {
				palya->b = false;
				return palya;
			}
			if (palya->bossElet == 0) {
				palya->b = true;
				return palya;
			}
			system("CLS");
		}
	}
	else {
	palya->b = false;
	return palya;
	}
}
void kiirSzabalyok() {
	printf("#Mesterlovesz\nA jatek arrol szol, hogy a jatekos egy celszemelyt keres, akit ki kell iktatni.\nA celszemelyhez elvezeto ut egy labirintus, viszont a labirintusban talalja meg a fegyveret, es a toltenyeket.\nA labirintusok teljesitese utan, a merenylo fel kell jusson egy epulet tetejere, hogy eszrevetlen maradjon.\nA celszemelyt 4 ponton kell eltalalja, ablakokon keresztul, hoy elegendo mereg jusson a szervezetebe.\nHa az osszes lovest sikeresen adta le, vege a jateknak, es a jatekos nyert.	\nAzonban, ha nem az utat koveti, es megprobal nem ures mezore lepni, a jateknak vege.\n\nSzabalyok:\n\t-csak ures mezore lehet lepni\n\t- csak kezvetlenul az ablak(A) melletti mezorol lehet leadni lovest\n\t- a fegyvert(fegyver), es az osszes golyot(G) be kell gyujteni a masodik palyan, kulonben nem sikerulhet\n\t- nem szabad nekimenni semminek\n\t- a labirintus veget a F betu jeloli\n\t- a cmd ablakot ki kell nagyitani\n\t- FONTOS: a Caps Lock legyen kikapcsolva!!!\n");
}