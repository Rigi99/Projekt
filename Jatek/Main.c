#include "Header.h"
int main()
{
	Palya* palya = beolvasPalya("1szint.txt");
	if (jatekMenet(palya)) {
		printf("\nA fegyvert a G jelzi! A lovedekeket l jelzi. Szukseg lesz ra az utolso szinten!\n");
		palya = beolvasPalya("2szint.txt");
	}
	else {
		printf("\nJatek vege!");
		return -5;
	}
	if (jatekMenet(palya)) {
		printf("Gyozd le a BOSSt!\n");
		palya = beolvasPalya("3szint.txt");
	}
	else{
		printf("\nJatek vege!");
		return -5;
	}
	if (jatekMenetExtra(palya)) {
		printf("\nJatek teljesitve! Gratulalunk!");
	}	
	else {
		printf("\nJatek vege!");
		return -5;
	}
	return -5;
}