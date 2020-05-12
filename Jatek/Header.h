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
typedef struct Palya {
	int szel;
	int hossz;
	char** palya;
}Palya;
Palya* beolvasPalya(const char*);
void kirajzolPalya(Palya*);
bool jatekMenet(Palya*);
#endif