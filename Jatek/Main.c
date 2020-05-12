#include "Header.h"
int main()
{
	Palya* palya = beolvasPalya("1szint.txt");
	if (jatekMenet(palya)) {
		palya = beolvasPalya("2szint.txt");
	}
	else {
		printf("Jatek vege!");
		return -5;
	}
	if (jatekMenet(palya)) {
		palya = beolvasPalya("3szint.txt");
	}
	else{
		printf("Jatek vege!");
		return -5;
	}
	if (jatekMenetExtra(palya)) {
		printf("Jatek teljesitve! Gratulalunk!");
	}	
	else {
		printf("Jatek vege!");
		return -5;
	}
	return -5;
}