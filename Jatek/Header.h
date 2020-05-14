#pragma once
#ifndef JATEK_H
#define JATEK_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
typedef struct Palya {
	int szel;
	int hossz;
	char** palya;
	int fegyver;
	int bossElet;
	int bossX;
	int bossY;
	bool b;
	bool f;
}Palya;
Palya* createPalya(const char*);
void beolvasPalya(const char*, char**);
void kirajzolPalya(Palya*);
Palya* jatekMenet(Palya*);
Palya* jatekMenetExtra(Palya*);
void kiirSzabalyok();
#endif