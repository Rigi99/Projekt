#include "Header.h"
int main()
{
	Palya* palya = createPalya("1szint.txt");
	beolvasPalya("1szint.txt", palya->palya);
	palya = jatekMenet(palya);
	if (palya->b) {
		system("CLS");
		printf("A fegyvert a G jelzi! A lovedekeket l jelzi. Szukseg lesz ra az utolso szinten!\n");
		beolvasPalya("2szint.txt", palya->palya);
		palya = jatekMenet(palya);
	}
	else {
		system("CLS");
		printf("Jatek vege!");
		return -5;
	}
	if (palya->b) {
		system("CLS");
		printf("Gyozd le a BOSSt!\n");
		beolvasPalya("3szint.txt", palya->palya);
		palya = jatekMenetExtra(palya);
	}
	else {
		system("CLS");
		printf("Jatek vege!");
		return -5;
	}
	if (palya->b) {
		system("CLS");
		printf("Jatek teljesitve! Gratulalunk!");
	}
	else {
		system("CLS");
		printf("\nJatek vege!");
		return -5;
	}
	return -5;
}